// NRXTANSA.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "NRXTANSA.h"
#include "NRext_Dll.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/***************************************************************************************
	NRXTANSA
	
	Version History:
	1.0.0.3 jpm
		replace message to "MSG_TSNE_MESSAGE"
	1.0.0.2 jpm
		added check: run custom code only if user clicked the Newsroom icon
		(done by checking for EXTFUNC_EXECUTE)
	1.0.0.1 jpm
		provided functionality to run Tansa proofing and hyphenation 
		through keyboard shortcuts
	1.0.0.0 jpm
		initial release

****************************************************************************************/



//
//	Note!
//
//		If this DLL is dynamically linked against the MFC
//		DLLs, any functions exported from this DLL which
//		call into MFC must have the AFX_MANAGE_STATE macro
//		added at the very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the 
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

/////////////////////////////////////////////////////////////////////////////
// CNRXTANSAApp

BEGIN_MESSAGE_MAP(CNRXTANSAApp, CWinApp)
	//{{AFX_MSG_MAP(CNRXTANSAApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNRXTANSAApp construction

CNRXTANSAApp::CNRXTANSAApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CNRXTANSAApp object

CNRXTANSAApp theApp;



//***************************************************************************
//								EXTENSION STUFF
//***************************************************************************
//

// some functions 
void GetPluginBin(LPTSTR);

// some constants
#define CFG_FILE			"nrxtansa.xml"
#define MSG_CLIENTTITLE		"Newsroom Tansa Plugin"
#define MSG_MYMESSAGE		"MSG_TSNE_MESSAGE"
#define MSG_SHOWTANSAMENU	10			//msg code to show menu
#define	MSG_RUNTANSAPROOFING	20		//msg code to run Tansa proofing
#define MSG_RUNTANSAHYPHENATION	30		//msg code to run Tansa hyphenation
#define MSG_CLOSEPLUGIN		90			//msg code to close plugin

// some globals
HWND hNRwnd;
LPFUNC_CALLNEWSROOM nrfunc = NULL;


extern "C" _declspec(dllexport) LRESULT WINAPI MainExtProc (UINT msg, WPARAM wParam, LPARAM lParam)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	LRESULT lResult = 0;
	HWND hP = 0;
	static long lMsg;

	static STARTUPINFO si;
	static PROCESS_INFORMATION pi;

	LPTSTR szCmd = NULL;


	switch (msg)
	{

		case NRM_HELLO:
			//AfxMessageBox("HELLO");

			hNRwnd=(HWND)wParam;	//handle to Newsroom
			//nrfunc=(LPFUNC_CALLNEWSROOM)lParam;
			//construct the flags; notice that no page or output flags are used if you want to use
			//such functionality specifies the correct flags (see NRM_HELLO message description)

			
			szCmd = new TCHAR[MAX_PATH];
			GetPluginBin(szCmd);	//get plugin path and filename from config xml file


			ZeroMemory( &si, sizeof(si) );
			si.cb = sizeof(si);
			ZeroMemory( &pi, sizeof(pi) );


			if ( CreateProcess(NULL,	// No module name
					szCmd,			// plugin bin
					NULL,           // Process handle not inheritable
					NULL,           // Thread handle not inheritable
					FALSE,          // Set handle inheritance to FALSE
					0,              // No creation flags
					NULL,           // Use parent's environment block
					NULL,           // Use parent's starting directory 
					&si,            // Pointer to STARTUPINFO structure
					&pi )           // Pointer to PROCESS_INFORMATION structure
				) { 
				lResult = EXTTYPE_ALLWAYSUP;				
			}
			else {
				AfxMessageBox("Tansa plugin was not loaded successfully. CreateProcess failed.");
				lResult = 0;
			}


			delete [] szCmd;	//clear memory -important
			break;
	

		case NRM_GOODBYE:
			//AfxMessageBox("GOODBYE");

			hP = FindWindow(NULL, MSG_CLIENTTITLE);
			if ( hP != 0 ) {
				if ( lMsg == 0 ) {
					lMsg = RegisterWindowMessageA(MSG_MYMESSAGE);
				}
				SendMessageA(hP, lMsg, (WPARAM)hNRwnd, (LPARAM)MSG_CLOSEPLUGIN); //send msg to close plugin
			}
			// no need to show msg since Newsroom is being closed anyway
			// else {
			// 	AfxMessageBox("The plugin is not loaded. Please close and relaunch Newsroom.");
			// }

			//not needed
			//nrfunc=NULL;

		    // Close process and thread handles.
			CloseHandle(pi.hProcess);
			CloseHandle(pi.hThread);

			lResult = 1;
			break;


		case NRM_CUSTOM1:	//send msg to show the menu
			//AfxMessageBox("CUSTOM1");

			if ( wParam == EXTFUNC_EXECUTE ) {
				hP = FindWindow(NULL, MSG_CLIENTTITLE);
				if ( hP != 0 ) {
					if ( lMsg == 0 ) {
						lMsg = RegisterWindowMessageA(MSG_MYMESSAGE);
					}
					SendMessageA(hP, lMsg, (WPARAM)hNRwnd, (LPARAM)MSG_SHOWTANSAMENU); 
				}
				else {
					AfxMessageBox("The Tansa plugin is not loaded. Please close and relaunch Newsroom.");

					// Close process and thread handles.
					CloseHandle(pi.hProcess);
					CloseHandle(pi.hThread);
				}
			}

			lResult = 1;
			break;


		case NRM_CUSTOM2:	//send msg to run proofing
			//AfxMessageBox("CUSTOM2");

			if ( wParam == EXTFUNC_EXECUTE ) {
				hP = FindWindow(NULL, MSG_CLIENTTITLE);
				if ( hP != 0 ) {
					if ( lMsg == 0 ) {
						lMsg = RegisterWindowMessageA(MSG_MYMESSAGE);
					}
					SendMessageA(hP, lMsg, (WPARAM)hNRwnd, (LPARAM)MSG_RUNTANSAPROOFING); 
				}
				else {
					AfxMessageBox("The Tansa plugin is not loaded. Please close and relaunch Newsroom.");

					// Close process and thread handles.
					CloseHandle(pi.hProcess);
					CloseHandle(pi.hThread);
				}
			}

			lResult = 1;
			break;


		case NRM_CUSTOM3:	//send msg to run hyphenation
			//AfxMessageBox("CUSTOM3");

			if ( wParam == EXTFUNC_EXECUTE ) {
				hP = FindWindow(NULL, MSG_CLIENTTITLE);
				if ( hP != 0 ) {
					if ( lMsg == 0 ) {
						lMsg = RegisterWindowMessageA(MSG_MYMESSAGE);
					}
					SendMessageA(hP, lMsg, (WPARAM)hNRwnd, (LPARAM)MSG_RUNTANSAHYPHENATION); 
				}
				else {
					AfxMessageBox("The Tansa plugin is not loaded. Please close and relaunch Newsroom.");

					// Close process and thread handles.
					CloseHandle(pi.hProcess);
					CloseHandle(pi.hThread);
				}
			}

			lResult = 1;
			break;

	}

	return lResult;
}



/*******
******** these functions are not used right now *******

LRESULT CallNewsRoom (UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (nrfunc != NULL) {
		//return result of call
		return nrfunc(AfxGetInstanceHandle(), msg, wParam, lParam);
	}

	//return failure
	return 0;
}


// get active document-data from NewsRoom
BOOL	GetActiveDocData(NRX_DATA* pNrxData)
{
	// preset the return-data
	memset(pNrxData,0,sizeof(NRX_DATA));

	// make a Newsroom-call
	CallNewsRoom(EXM_GETACTIVEDOCDATA, 0, (LPARAM)pNrxData);
	
	// check result
	if( !pNrxData->po )
	{
		// no data returned by Newsroom
		// OutputDebugString("NRX:GetDocActiveData:unable to retrieve data\n");
		MessageBox(0, "NRX-Can't get DocData", "Debug", MB_OK);
		return FALSE;
	}
	else 
	{
		// data returned
		return TRUE;
	}
}

************/



void GetPluginBin(LPTSTR szCmd)
{
	IXMLDOMDocumentPtr pXMLDoc = NULL;
	IXMLDOMNodePtr pNode = NULL;

	/*
	//	Make sure that MSXML 4.0 is installed
	if (!isMSXMLInstalled()) {
		AfxMessageBox("MSXML not installed");
		return NULL;
	}
	*/

	//create XML dom instance
	HRESULT hr = pXMLDoc.CreateInstance(CLSID_DOMDocument);
	if (FAILED(hr)) {
		AfxMessageBox("Failed to create XML DOM document instance");
		return;
	}
	pXMLDoc->async = false; //Load the document synchronously

	//load the XML document
	variant_t vResult;
	vResult = pXMLDoc->load(CFG_FILE);	//cfg file located in same folder as the dll/nrx file
	if (((bool)vResult) != TRUE) {
		AfxMessageBox("Failed to load XML document");
		return;
	}

	//find the required node
	pNode = pXMLDoc->selectSingleNode("//PluginBin");
	if (pNode == NULL) {
		AfxMessageBox("Failed to find node <PluginBin>");
		return;
	}

	_tcscpy(szCmd, pNode->text);	//copy string to pointer

	pNode = NULL;
	pXMLDoc = NULL;
}
