/***************************************************************
 * Name:      mulchGUIMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2013-06-26
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef MULCHGUIMAIN_H
#define MULCHGUIMAIN_H



#include "mulchGUIApp.h"



#include "GUIDialog.h"

class mulchGUIDialog: public GUIDialog
{
    public:
        mulchGUIDialog(wxDialog *dlg);
        ~mulchGUIDialog();
    private:
        virtual void OnClose(wxCloseEvent& event);
        virtual void OnQuit(wxCommandEvent& event);
        virtual void OnAbout(wxCommandEvent& event);
};
#endif // MULCHGUIMAIN_H
