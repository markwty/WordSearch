/***************************************************************
 * Name:      WordSearchMain.h
 * Purpose:   Defines Application Frame
 * Author:    Mark ()
 * Created:   2021-11-09
 * Copyright: Mark ()
 * License:
 **************************************************************/

#ifndef WORDSEARCHMAIN_H
#define WORDSEARCHMAIN_H

//(*Headers(WordSearchFrame)
#include "wx/button.h"
#include "wx/checkbox.h"
#include "wx/checklst.h"
#include "wx/frame.h"
#include "wx/grid.h"
#include "wx/menu.h"
#include "wx/panel.h"
#include "wx/richtext/richtextctrl.h"
#include "wx/stattext.h"
#include "wx/statusbr.h"
#include "wx/textctrl.h"
//*)

#include "stdlib.h"
#include "time.h"

class WordSearchFrame: public wxFrame
{
    public:

        WordSearchFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~WordSearchFrame();
        void Initialise();
        wxVector<wxVector<int>> Orientations(wxVector<wxVector<wxUniChar>>& grid, wxString word
                                   , int curr_index, wxVector<int>& position, int pos, bool oriens[]);
        wxVector<int> FindEmpty(wxVector<wxVector<wxUniChar>>& grid, int length, bool oriens[]);
        void PlaceGrid(wxVector<wxVector<wxUniChar>>& grid, wxVector<int> loc, wxString word);
        void PlaceWords(wxVector<wxString> ordered_words, bool oriens[]);
        void ColorIndex(int index, wxColor color);

    private:

        //(*Handlers(WordSearchFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnGenerateBtnClick(wxCommandEvent& event);
        void OnWordsCheckListBoxToggled(wxCommandEvent& event);
        void OnRevealBtnClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(WordSearchFrame)
        static const int ID_WORDSRICHTEXTCTRL;
        static const int ID_LEFTRIGHTCHECKBOX;
        static const int ID_GENERATEBTN;
        static const int ID_TOPBOTTOMCHECKBOX;
        static const int ID_TOPLEFTBOTTOMRIGHTCHECKBOX;
        static const int ID_WORDSLBL;
        static const int ID_TOPRIGHTBOTTOMLEFTCHECKBOX;
        static const int ID_RIGHTLEFTCHECKBOX;
        static const int ID_BOTTOMRIGHTTOPLEFTCHECKBOX;
        static const int ID_SEARCHGRID;
        static const int ID_GRIDPANEL;
        static const int ID_WORDSCHECKLISTBOX;
        static const int ID_SIZEFACTORTEXTCTRL;
        static const int ID_SIZEFACTORLBL;
        static const int ID_REVEALBTN;
        static const int ID_BOTTOMTOPCHECKBOX;
        static const int ID_BOTTOMLEFTTOPRIGHTCHECKBOX;
        static const int idMenuQuit;
        static const int idMenuAbout;
        static const int ID_STATUSBAR1;
        //*)

        //(*Declarations(WordSearchFrame)
        wxButton* GenerateBtn;
        wxButton* RevealBtn;
        wxCheckBox* BottomLeftTopRightCheckBox;
        wxCheckBox* BottomRightTopLeftCheckBox;
        wxCheckBox* BottomTopCheckBox;
        wxCheckBox* LeftRightCheckBox;
        wxCheckBox* RightLeftCheckBox;
        wxCheckBox* TopBottomCheckBox;
        wxCheckBox* TopLeftBottomRightCheckBox;
        wxCheckBox* TopRightBottomLeftCheckBox;
        wxCheckListBox* WordsCheckListBox;
        wxGrid* SearchGrid;
        wxPanel* GridPanel;
        wxRichTextCtrl* WordsRichTextCtrl;
        wxStaticText* SizeFactorLbl;
        wxStaticText* WordsLbl;
        wxStatusBar* StatusBar1;
        wxTextCtrl* SizeFactorTextCtrl;
        //*)

        wxVector <wxString> words;
        wxVector<wxVector<int>> positions;
        wxVector<wxString> selected_words;
        wxVector<wxColor> colors;
        bool showAnswers = false;

        DECLARE_EVENT_TABLE()
};

#endif // WORDSEARCHMAIN_H
