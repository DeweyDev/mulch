/***************************************************************
 * Name:      mulchGUIApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2013-06-26
 * Copyright:  ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "mulchGUIApp.h"
#include "mulchGUIMain.h"

IMPLEMENT_APP(mulchGUIApp);

bool mulchGUIApp::OnInit()
{
    
    mulchGUIDialog* dlg = new mulchGUIDialog(0L);
    
    dlg->Show();
    return true;
}
