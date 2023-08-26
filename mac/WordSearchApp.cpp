/***************************************************************
 * Name:      WordSearchApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Mark ()
 * Created:   2021-11-09
 * Copyright: Mark ()
 * License:
 **************************************************************/

#include "WordSearchApp.h"

//(*AppHeaders
#include "WordSearchMain.h"
#include "wx/image.h"
//*)

IMPLEMENT_APP(WordSearchApp);

bool WordSearchApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	WordSearchFrame* Frame = new WordSearchFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
