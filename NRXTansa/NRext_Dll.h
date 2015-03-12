/////////////////////////////////////////////////////////////////////
// NrExt_Dll.h file used by NewsRoom and its extensions.

#ifndef __NREXT_H_DLL
#define __NREXT_H_DLL

/////////////////////////////////////////////////////////////////////
// Defines and type definition used both by NewsRoom and the
// extensions.

#define WMU_NRCC				(WM_USER + 1010)

// Private NrExport messages start from 1000.
#define PEM_USER					1000

//////////////////////// Message IDs ////////////////////////////////
// Messages sent from NewsRoom to Extensions.
#define NRM_HELLO					1
#define NRM_GOODBYE					2
#define NRM_LOGINDONE				3
#define NRM_SAVEOBJECT				4
#define NRM_CLOSEOBJECT				5
#define NRM_DESTROYOBJECT			6
#define NRM_GETOBJECTNAME			7
#define NRM_GETOBJECTPROOFHEADER	8
#define NRM_GETSTATUSBARUNIT		9
#define NRM_UI_MODIFYSPECS			10
#define NRM_GETDOCICONBAR			11
#define NRM_PAGEFUNC				12
#define NRM_OUTPUTFUNC				13
#define NRM_SETFOCUS				14  //new in 6.0

#define NRM_NR_PAGETAG				100
#define NRM_NR_OBJECTTAG			110
#define NRM_NR_OBJECTINFO			111
#define NRM_NR_BBOXINFO				119
#define NRM_NR_BLOCKINFO			120

#define NRM_OBJECTDEFINED			130
#define NRM_OBJ_RELASED             131   // Verrini - MYRIADE NRX NFR

// Messages sent from Extension to NewsRoom.
#define EXM_CREATEDOC				1
#define EXM_CREATEVIEW				2
#define EXM_DESTROYVIEW				3
#define EXM_SETOBJECTDATA			4
#define EXM_GETACTIVEDOCDATA		5
#define EXM_GETCONTENT				6
#define EXM_MERGECONTENT			7
#define EXM_GETOBJECTINFO			8
#define EXM_SETOBJECTDIM			9
#define EXM_SETOBJECTTSPECS			10
#define EXM_APPLYMACRO				11
#define EXM_SETVIEWCAPTION			12
#define EXM_STRINGTODECIPTS			13
#define EXM_DECIPTSTOSTRING			14
#define EXM_VIRTUALFUNC				15
#define EXM_MENUFUNC				16
#define EXM_CLEARCONTENT			19
#define EXM_EDITMODE_DRAFT			20
#define EXM_EDITMODE_BLOCKS			21
#define EXM_GETCOMPLEXCONTENT		22
#define EXM_SUPPRESSCOMMANDS		23
#define EXM_GETCONTENT_COM			24	//new in 6.0
#define EXM_IMPORTFILE				25  //new in 6.0
#define EXM_GETXFIELD				26  //new in 6.0 
#define EXM_SETXFIELD				27  //new in 6.0 
#define EXM_GETVIEWCAPTION			28  //new in 6.0
#define	EXM_GETIMAGEDATA			29  //only internal use NFR 1217
#define	EXM_GETPREVHRD				30  //only internal use NFR 1217
#define EXM_AUTORUNAROUND			31  //only internal use	NFR 1217
#define EXM_RESTOREDEFAULTINFO		32	//only internal use NFR 1217
#define EXM_FREEDEFAULTINFO			33	//only internal use	NFR 1217
#define EXM_TRANSFORM_IMAGE			34
#define EXM_GETHERMESMENUSTATUS		35
#define EXM_ISCARTONOBJECT			36
#define EXM_GETNEXTOBJECT			37
#define EXM_ISTEXTUALOBJ			38
#define EXM_SETACTIVEOBJ			39
#define EXM_GETSELSTARTPOS			40
#define EXM_ISJUMPOBJECT			41
#define EXM_ISDRAFTEDITMODE			42
#define EXM_DELETEDEFINE			43
#define EXM_GETCONTENT_FORMYRIADE	44
#define EXM_GETIMAGEINFO			45
#define EXM_FREEDATA				46

#define EXM_UTF16_GETCONTENT_COM	70
#define EXM_UTF16_GETCOMPLEXCONTENT 71
#define EXM_UTF16_FINDREPLACE		72
#define EXM_UTF16_IMPORTFILE		73
#define EXM_UTF16_GETCONTENT		74
#define EXM_UTF16_MERGECONTENT		75


#define EXM_HERMES_GETOBJTAG		100
#define EXM_HERMES_GETNROBJINFO		101
#define EXM_HERMES_GETPAGETAG		102
#define EXM_HERMES_GETNRPAGEINFO	103
#define EXM_HERMES_RELEASEPAGE		104
#define EXM_OUTPUTDOC				105
#define EXM_GETCHARDATA				106
#define EXM_FIRSTVISIBLECHAR		107
#define EXM_NEXTVISIBLECHAR			108
#define EXM_FINDREPLACE				109
#define EXM_GETPAGEPLANNEDCOLORS	110
#define EXM_GETPAGEEFFECTIVECOLORS	111

#define EXM_HIGHLIGHTBLOCK			120
#define EXM_HIGHLIGHTOBJECT			121
#define EXM_HIGHLIGHTOBJECTEND		122
#define EXM_OPENNRGROUP				123

#define EXM_ISTEXTOPENED			150
#define EXM_ADDTOTEXT				151
#define EXM_GETSTRINGID				152  //new in 6.0
#define EXM_ISPAGEOPENED			153  //new in 6.0
#define EXM_METADATA_READY          154   // Verrini - MYRIADE NRX NFR

// Page func values.
#define PAGEFUNC_NEW				0
#define PAGEFUNC_OPEN				1

// Output func values.
#define OUTPUTFUNC_OUTPUT			0

#define CLK			1
#define CLK_CTRL	2
#define DCLK		3
#define DCLK_CTRL	4

// Message posted by Extension to NewsRoom, when it needs to be recalled
// wParam contains the instance handle of the Extension that NewsRoom will call
// LOWORD of lParam contains the message code that NewsRoom will send the extension
// The extension will receive a the specified message with the value of lParam as is
// and wParam set to 0.
#define WMU_NOTIFYEXTENSION		(WM_USER + 2000)

///////////////////////// Special message identifiers ///////////////
// Extension type flags (returned from NRM_HELLO msg)
#define EXTTYPE_ALLWAYSUP			0x01		// Extension is always in memory.
#define EXTTYPE_PAGEFUNCS			0x04		// Interested in Page functions.
#define EXTTYPE_OUTPUTFUNCS			0x08		// Interested in Output functions.
#define EXTTYPE_SETFOCUS			0x10		// Want the focus - new in 6.0
											

// Identifiers of private messages.
#define EXTFUNC_EXECUTE				0           // Specifies if a message is sent to execute operations.
#define EXTFUNC_GETHELP				1			// Specifies if a message is sent to get some informations.

// Type of save.
#define SAVE_USERSAVE				0
#define SAVE_QUICKRELEASE			1
#define SAVE_RELEASE				2
#define SAVE_AUTOSAVE				3
#define SAVE_SAVEAS					4

// Object types (must be specified in wParam in EXM_CREATEDOC msg).
#define OBJTYPE_TXT					1
#define OBJTYPE_HEADLINE			2
#define OBJTYPE_CAPTION				3
#define OBJTYPE_ECONOMICS			11
#define OBJTYPE_NECRO				12

#define EXT_SET_STYLESHEET		0x0001
#define EXT_SET_CF				0x0002
#define EXT_SET_CP				0x0004
#define EXT_SET_CL				0x0008
#define EXT_SET_CS				0x0010
#define EXT_SET_CW				0x0020
#define EXT_SET_CJ				0x0040
#define EXT_SET_OBJTYPE			0x0080

// Status bar unit to be returned from the NRM_GETSTATUSBARUNIT msg.
#define TEXTSIZEUNIT_REALLINES		0
#define TEXTSIZEUNIT_STDLINES		1
#define TEXTSIZEUNIT_CHARS			2
#define TEXTSIZEUNIT_MM				3
#define TEXTSIZEUNIT_INCH			4
#define TEXTSIZEUNIT_MODULES		5
#define TEXTSIZEUINT_MODULESLINES	6

// Units used from conversion from decipts to string.
#define EXTUNIT_PTS					0
#define EXTUNIT_PICA				1
#define EXTUNIT_MM					2
#define EXTUNIT_INCH				3
#define EXTUNIT_LINES				4

// General defines.
#define MAXEXT_HELPMSG				128
#define	MAX_EXTOBJECTNAME			128
#define	MAX_EXTICONBARNAME			32
#define	MAX_EXTPROOFHEADER			128

/////////////////////////////////////////////////////////////////////
// Structure used for data exchange.
typedef struct {
	LPVOID		pp;					// Pointer to active PPAGE object.
	HANDLE		hInstDocOwner;		// Instance handle of document owner (0 if NewsRoom).
	LPVOID		po;					// Pointer to active POBJECT object.
	LPVOID		lpExtPrivate;		// Object's private data pointer.
	LPVOID		lpData;				// General purpose pointer.
	LONG		lSizeData;			// Size of lpData if necessary.
	UINT		msg;				// Message.
} NRX_DATA;
typedef NRX_DATA FAR * LPEXTDATA;

// Struct for getting object info (EXM_GETOBJECTINFO message and EXM_GETIMAGEINFO message).
struct NROBJ_INFO {
	RECT	rc;						// Total frame area.
	LONG	lChars;					// Nmber of chars.
	short	nRealLines;				// Number of lines.
	LONG	lRealSize;				// Total text depth.
};

// Struct for setting object dimensions (EXM_SETOBJECTDIM message).
struct NROBJ_DIM {
	short	nWidth;
	short	nDepth;
};

// Struct and defines for setting object default typographic specs (EXM_SETOBJECTTSPECS message).
struct NROBJ_TSPECS {
	char	StyleSheet[9];
	short	$F;		// Font.
	short	$S;		// Size.
	short	$L;		// Leading.
	short	$Z;		// SetSize.
	short	$K;		// Kerning.
	short	$A;		// Alignment (1 = left, 2 = right, 3 = centered, 4 = justified).
};

// Character data structure.
struct NR_CHARDATA {
	BYTE	byCode;
	BYTE	fCommand;
	BYTE	fSystem;
};

struct NR_FINDREPLACE {
	LONG	lStart;
	LONG	lSize;
	LPSTR	lpReplace;
};

struct NR_UTF16_FINDREPLACE {
	LONG	lStart;
	LONG	lSize;
	LPWSTR	lpReplace;
};

struct NRX_OUTPUT
{
	int		hProof;
	BOOL	bSpooler;
	BYTE	fSeparating;
	BYTE	byProcessColor;
	LPSTR	lpSpotColorName;
	BOOL	fCovertSpots;
	BOOL	fComposite;
	BOOL	fEps;
	BOOL	fJumpPages;
	LPSTR	lpPath;
};

typedef struct 
{
  LPSTR            MediaURI;
  LPSTR			   MetadataSection;
  LPVOID           lpData;         
} NRX_MYR_DATA;
typedef NRX_MYR_DATA FAR * LPEXTMYRDATA;


// Defines and type definition used only by extension and if the Hermes On Line support is required.
#ifdef H_ONLINE_DLL
	#define NRM_TABLEINFO				140
	#define NRM_ROWINFO					141
	#define NRM_CELLINFO				142
	#define NRM_CELLRULENUMBER			143
	#define NRM_CELLRULE				144

	#define EXM_GETTABLECONTENT			130

	typedef struct {
		short nWidth;		// Table width.
		short nDepth;		// Table depth.
		short nCols;		// Number of columns.
		short nRows;		// Number of rows.
		short nBlocks;		// Number of blocks containing the table.
		short nHeads;		// Number of rows reserved as header.
		short nHSpace;		// Horizontal space between cells.
		short nVSpace;		// Vertical space between cells.
		short nBorder;		// Table's border.
	} NRX_TABLEINFO;
	typedef NRX_TABLEINFO FAR * LPNRX_TABLEINFO;

	typedef struct {
		short nDepth;		// Row depth.
		short nExtra;		// 
		short nBlock;		// Index of block containing the row.
	} NRX_ROWINFO;
	typedef NRX_ROWINFO FAR * LPNRX_ROWINFO;

	typedef struct {
		BYTE byType;
		short nSize;			// Rule size
		short nBlack;			// Lunghezza nero
		short nWhite;			// Lunghezza bianco
		COLORREF rgbColor;		// Rule Color
	} CELL_RULE;
	typedef CELL_RULE FAR * LPCELL_RULE;
		
	typedef struct {
		short nRow;			// The row the cell belong to.
		short nCol;			// The column the cell belong to.
		short nWidth;		// Cell width.
		short nDepth;		// Cell depth.
		short nVJoined;		// 0 if not vertival joined.
							// 1 if joined to upper cell.
							// n the number of cells joined below.
		short nHJoined;		// 0 if not horizontal joined.
							// 1 if joined to left cell.
							// n the number of cells joined on the right.
		BYTE byAlign;		// Horizontal alignment.
		BYTE byVAlign;		// Vertical alignment for the cell.
							//  #define	VA_TOP		1
							//  #define	VA_CENTER	2
							//  #define	VA_BOTTOM	3
		short nIndentLeft;	// Left indentation.
		short nIndentRight;	// Right indentation.
		short nIndentTop;	// Top indentation.
		short nIndentBottom;	// Bottom indentation.
		COLORREF rgbColor;	// Background color for the cell.
		short nDirection;	// Text direction inside cell.
		short nBorderH;		// Top rule index.
		short nBorderV;		// Left rule index.
		short nGridH;		// Bottom rule index.
		short nGridV;		// Right rule index.
		LPSTR lpText;		// Text contained in the cell.
	} NRX_CELLINFO;
	typedef NRX_CELLINFO FAR * LPNRX_CELLINFO;
#endif	// H_ONLINE_DLL.

//*****************************************************************
//
// LPFUNC_CALLNEWSROOM - pointer to NewsRoom handler function
//
// return value
//	
//		DWORD - depends on the message used but generally 0 stands
//				for failure
//
// input params:
//
//		HINSTANCE - the instace of module that calls this function
//
//		UINT - message beeing send to NewsRoom
//
//		WPARAM - message parameters
//
//		LPARAM - message parameters
//
// output params:
//		
//      none
//
//*****************************************************************8
typedef long (__stdcall * LPFUNC_CALLNEWSROOM)(HINSTANCE,UINT, WPARAM, LPARAM);//lint63

//*****************************************************************
//
//	MainExtProc - the main function an extension DLL should export
//
//  return value
//
//		LRESULT - depends on the message (on HELLO message returns flags)
//
//  input params:
//
//		msg - message recieved from news room 
// 
//		WPARAM - message parameters
//
//		LPARAM - message parameters
//
//*****************************************************************8
#ifndef __NREXT_H_
extern "C" _declspec(dllexport) LRESULT WINAPI MainExtProc (UINT msg, WPARAM wParam, LPARAM lParam);
#endif

// Optional

//*****************************************************************
//
//	CallNewsRoom 
//
//  this is not a obligatory function it is used to make clear calls
//  to NewsRoom
//
//	Example (_lpfnNRProc is of type LPFUNC_CALLNEWSROOM and _hInst
//			 is the current module instance):
//
//	LRESULT CallNewsRoom (UINT msg, WPARAM wParam, LPARAM lParam) 
//	{
//		return ( (* _lpfnNRProc)(_hInst, msg, wParam, lParam) );
//	}	
//
//
//*****************************************************************8
LRESULT CallNewsRoom (UINT msg, WPARAM wParam, LPARAM lParam);

//******************************************************************
//Custom stuff:
//******************************************************************

#define NRM_CUSTOM1		1001
#define NRM_CUSTOM2		1002
#define NRM_CUSTOM3		1003

// not used 
// get active document-data from NewsRoom
//BOOL	GetActiveDocData(NRX_DATA* pNrxData);

#endif	//__NREXT_H_DLL
