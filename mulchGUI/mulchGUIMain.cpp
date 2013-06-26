/***************************************************************
 * Name:      mulchGUIMain.cpp
 * Purpose:   Code for Application Frame
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

#include "mulchGUIMain.h"

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxT("A GUI Front-End for the Mulch Library.\nBuilt with wxWidgets 2.8.12"));

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}



mulchGUIDialog::mulchGUIDialog(wxDialog *dlg)
    : GUIDialog(dlg)
{
}

mulchGUIDialog::~mulchGUIDialog()
{
}

void mulchGUIDialog::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void mulchGUIDialog::OnQuit(wxCommandEvent &event)
{
    Destroy();
}

void mulchGUIDialog::OnAbout(wxCommandEvent &event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("About"));
}
