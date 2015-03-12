// NRXTANSA.h : main header file for the NRXTANSA DLL
//

#if !defined(AFX_NRXTANSA_H__0669943B_0F67_496D_8F0F_232BF4EB4A9C__INCLUDED_)
#define AFX_NRXTANSA_H__0669943B_0F67_496D_8F0F_232BF4EB4A9C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CNRXTANSAApp
// See NRXTANSA.cpp for the implementation of this class
//

class CNRXTANSAApp : public CWinApp
{
public:
	CNRXTANSAApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNRXTANSAApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CNRXTANSAApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NRXTANSA_H__0669943B_0F67_496D_8F0F_232BF4EB4A9C__INCLUDED_)
