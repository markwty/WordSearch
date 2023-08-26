/***************************************************************
 * Name:      WordSearchMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Mark ()
 * Created:   2021-11-09
 * Copyright: Mark ()
 * License:
 **************************************************************/

#include "WordSearchMain.h"
#include "wx/msgdlg.h"

//(*InternalHeaders(WordSearchFrame)
#include "wx/intl.h"
#include "wx/string.h"
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
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

//(*IdInit(WordSearchFrame)
const int WordSearchFrame::ID_WORDSRICHTEXTCTRL = wxNewId();
const int WordSearchFrame::ID_LEFTRIGHTCHECKBOX = wxNewId();
const int WordSearchFrame::ID_GENERATEBTN = wxNewId();
const int WordSearchFrame::ID_TOPBOTTOMCHECKBOX = wxNewId();
const int WordSearchFrame::ID_TOPLEFTBOTTOMRIGHTCHECKBOX = wxNewId();
const int WordSearchFrame::ID_WORDSLBL = wxNewId();
const int WordSearchFrame::ID_TOPRIGHTBOTTOMLEFTCHECKBOX = wxNewId();
const int WordSearchFrame::ID_RIGHTLEFTCHECKBOX = wxNewId();
const int WordSearchFrame::ID_BOTTOMRIGHTTOPLEFTCHECKBOX = wxNewId();
const int WordSearchFrame::ID_SEARCHGRID = wxNewId();
const int WordSearchFrame::ID_GRIDPANEL = wxNewId();
const int WordSearchFrame::ID_WORDSCHECKLISTBOX = wxNewId();
const int WordSearchFrame::ID_SIZEFACTORTEXTCTRL = wxNewId();
const int WordSearchFrame::ID_SIZEFACTORLBL = wxNewId();
const int WordSearchFrame::ID_REVEALBTN = wxNewId();
const int WordSearchFrame::ID_BOTTOMTOPCHECKBOX = wxNewId();
const int WordSearchFrame::ID_BOTTOMLEFTTOPRIGHTCHECKBOX = wxNewId();
const int WordSearchFrame::idMenuQuit = wxNewId();
const int WordSearchFrame::idMenuAbout = wxNewId();
const int WordSearchFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(WordSearchFrame,wxFrame)
    //(*EventTable(WordSearchFrame)
    //*)
END_EVENT_TABLE()

WordSearchFrame::WordSearchFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(WordSearchFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(1336,742));
    WordsRichTextCtrl = new wxRichTextCtrl(this, ID_WORDSRICHTEXTCTRL, wxEmptyString, wxPoint(832,160), wxSize(280,272), wxRE_MULTILINE, wxDefaultValidator, _T("ID_WORDSRICHTEXTCTRL"));
    wxRichTextAttr rchtxtAttr_1;
    rchtxtAttr_1.SetBulletStyle(wxTEXT_ATTR_BULLET_STYLE_ALIGN_LEFT);
    LeftRightCheckBox = new wxCheckBox(this, ID_LEFTRIGHTCHECKBOX, _("Left-Right"), wxPoint(832,8), wxDefaultSize, 0, wxDefaultValidator, _T("ID_LEFTRIGHTCHECKBOX"));
    LeftRightCheckBox->SetValue(true);
    GenerateBtn = new wxButton(this, ID_GENERATEBTN, _("Generate"), wxPoint(840,488), wxDefaultSize, 0, wxDefaultValidator, _T("ID_GENERATEBTN"));
    TopBottomCheckBox = new wxCheckBox(this, ID_TOPBOTTOMCHECKBOX, _("Top-Bottom"), wxPoint(832,56), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TOPBOTTOMCHECKBOX"));
    TopBottomCheckBox->SetValue(true);
    TopLeftBottomRightCheckBox = new wxCheckBox(this, ID_TOPLEFTBOTTOMRIGHTCHECKBOX, _("Top left-Bottom right"), wxPoint(832,32), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TOPLEFTBOTTOMRIGHTCHECKBOX"));
    TopLeftBottomRightCheckBox->SetValue(true);
    WordsLbl = new wxStaticText(this, ID_WORDSLBL, _("List of words"), wxPoint(832,136), wxDefaultSize, 0, _T("ID_WORDSLBL"));
    TopRightBottomLeftCheckBox = new wxCheckBox(this, ID_TOPRIGHTBOTTOMLEFTCHECKBOX, _("Top right-Bottom left"), wxPoint(832,80), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TOPRIGHTBOTTOMLEFTCHECKBOX"));
    TopRightBottomLeftCheckBox->SetValue(true);
    RightLeftCheckBox = new wxCheckBox(this, ID_RIGHTLEFTCHECKBOX, _("Right-Left"), wxPoint(832,104), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RIGHTLEFTCHECKBOX"));
    RightLeftCheckBox->SetValue(true);
    BottomRightTopLeftCheckBox = new wxCheckBox(this, ID_BOTTOMRIGHTTOPLEFTCHECKBOX, _("Bottom right-Top left"), wxPoint(944,56), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BOTTOMRIGHTTOPLEFTCHECKBOX"));
    BottomRightTopLeftCheckBox->SetValue(true);
    GridPanel = new wxPanel(this, ID_GRIDPANEL, wxPoint(0,0), wxSize(824,700), wxTAB_TRAVERSAL, _T("ID_GRIDPANEL"));
    SearchGrid = new wxGrid(GridPanel, ID_SEARCHGRID, wxPoint(0,0), wxSize(824,700), wxBORDER_RAISED, _T("ID_SEARCHGRID"));
    SearchGrid->CreateGrid(5,5);
    SearchGrid->EnableEditing(false);
    SearchGrid->EnableGridLines(true);
    SearchGrid->SetColLabelSize(1);
    SearchGrid->SetRowLabelSize(1);
    SearchGrid->SetDefaultRowSize(40, true);
    SearchGrid->SetDefaultColSize(40, true);
    SearchGrid->SetDefaultCellFont( SearchGrid->GetFont() );
    SearchGrid->SetDefaultCellTextColour( SearchGrid->GetForegroundColour() );
    WordsCheckListBox = new wxCheckListBox(this, ID_WORDSCHECKLISTBOX, wxPoint(1120,0), wxSize(216,700), 0, 0, 0, wxDefaultValidator, _T("ID_WORDSCHECKLISTBOX"));
    SizeFactorTextCtrl = new wxTextCtrl(this, ID_SIZEFACTORTEXTCTRL, _("1"), wxPoint(920,448), wxSize(176,22), 0, wxDefaultValidator, _T("ID_SIZEFACTORTEXTCTRL"));
    SizeFactorLbl = new wxStaticText(this, ID_SIZEFACTORLBL, _("Size Factor"), wxPoint(840,448), wxDefaultSize, 0, _T("ID_SIZEFACTORLBL"));
    RevealBtn = new wxButton(this, ID_REVEALBTN, _("Show/hide all answers"), wxPoint(840,528), wxDefaultSize, 0, wxDefaultValidator, _T("ID_REVEALBTN"));
    BottomTopCheckBox = new wxCheckBox(this, ID_BOTTOMTOPCHECKBOX, _("Bottom-Top"), wxPoint(1000,80), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BOTTOMTOPCHECKBOX"));
    BottomTopCheckBox->SetValue(true);
    BottomLeftTopRightCheckBox = new wxCheckBox(this, ID_BOTTOMLEFTTOPRIGHTCHECKBOX, _("Bottom left-Top right"), wxPoint(944,104), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BOTTOMLEFTTOPRIGHTCHECKBOX"));
    BottomLeftTopRightCheckBox->SetValue(true);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_GENERATEBTN,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&WordSearchFrame::OnGenerateBtnClick);
    Connect(ID_WORDSCHECKLISTBOX,wxEVT_COMMAND_CHECKLISTBOX_TOGGLED,(wxObjectEventFunction)&WordSearchFrame::OnWordsCheckListBoxToggled);
    Connect(ID_REVEALBTN,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&WordSearchFrame::OnRevealBtnClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&WordSearchFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&WordSearchFrame::OnAbout);
    //*)
    Initialise();
}

WordSearchFrame::~WordSearchFrame()
{
    //(*Destroy(WordSearchFrame)
    //*)
}

void WordSearchFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void WordSearchFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void WordSearchFrame::Initialise()
{
    wxColor arr[] = {wxColor(255,0,0,150), wxColor(0,255,0,150), wxColor(0,0,255,150)
    , wxColor(255,165,0,150), wxColor(0,122,0,150), wxColor(255,192,203,150)
    , wxColor(122,122,0,150), wxColor(0,122,122,150), wxColor(203,195,227,150)};
    colors = wxVector<wxColor>(arr, arr + sizeof(arr)/sizeof(arr[0]));
    SearchGrid->SetDefaultCellFont(wxFont(23, wxSWISS, wxNORMAL, wxNORMAL, false, _("MS Sans Serif")));
    RevealBtn->Enable(false);
}

wxVector<wxVector<int>> WordSearchFrame::Orientations(wxVector<wxVector<wxUniChar>>& grid, wxString word
                                   , int curr_index, wxVector<int>& position, int pos, bool oriens[])
{
    wxVector<wxVector<int>> availablePos = wxVector<wxVector<int>>();
    int x, y;
    if (position[2] > position[0])
    {
        x = pos + position[0];
    }
    else if (position[2] == position[0])
    {
        x = position[0];
    }
    else
    {
        x = position[0] - pos;
    }
    if (position[3] > position[1])
    {
        y = pos + position[1];
    }
    else if (position[3] == position[1])
    {
        y = position[1];
    }
    else
    {
        y = position[1] - pos;
    }

    int length = (int)word.length();
    int grid_size = (int)grid.size();
    bool pass;

    if (oriens[2])
    {
        pass = true;
        if (x-curr_index >= 0 && x-curr_index+length-1 < grid_size)
        {
            for (int i = 0; i < length; i++)
            {
                if (grid[x-curr_index+i][y] != '\0' && word[i] != grid[x-curr_index+i][y])
                {
                    pass = false;
                    break;
                }
            }
            if (pass)
            {
                int arr[] = {x-curr_index, y, x-curr_index+length-1, y};
                wxVector<int> vect(arr, arr + sizeof(arr)/sizeof(arr[0]));
                availablePos.push_back(vect);
            }
        }
    }

    if (oriens[1])
    {
        pass = true;
        if (x-curr_index >= 0 && x-curr_index+length-1 < grid_size
            && y-curr_index >= 0 && y-curr_index+length-1 < grid_size)
        {
            for (int i = 0; i < length; i++)
            {
                if (grid[x-curr_index+i][y-curr_index+i] != '\0' && word[i] != grid[x-curr_index+i][y-curr_index+i])
                {
                    pass = false;
                    break;
                }
            }
            if (pass)
            {
                int arr[] = {x-curr_index, y-curr_index, x-curr_index+length-1, y-curr_index+length-1};
                wxVector<int> vect(arr, arr + sizeof(arr)/sizeof(arr[0]));
                availablePos.push_back(vect);
            }
        }
    }

    if (oriens[0])
    {
        pass = true;
        if (y-curr_index >= 0 && y-curr_index+length-1 < grid_size)
        {
            for (int i = 0; i < length; i++)
            {
                if (grid[x][y-curr_index+i] != '\0' && word[i] != grid[x][y-curr_index+i])
                {
                    pass = false;
                    break;
                }
            }
            if (pass)
            {
                int arr[] = {x, y-curr_index, x, y-curr_index+length-1};
                wxVector<int> vect(arr, arr + sizeof(arr)/sizeof(arr[0]));
                availablePos.push_back(vect);
            }
        }
    }

    if (oriens[7])
    {
        pass = true;
        if (y-curr_index >= 0 && y-curr_index+length-1 < grid_size
            && x+curr_index < grid_size && x+curr_index-length+1 >= 0)
        {
            for (int i = 0; i < length; i++)
            {
                if (grid[x+curr_index-i][y-curr_index+i] != '\0' && word[i] != grid[x+curr_index-i][y-curr_index+i])
                {
                    pass = false;
                    break;
                }
            }
            if (pass)
            {
                int arr[] = {x+curr_index, y-curr_index, x+curr_index-length+1, y-curr_index+length-1};
                wxVector<int> vect(arr, arr + sizeof(arr)/sizeof(arr[0]));
                availablePos.push_back(vect);
            }
        }
    }

    if (oriens[6])
    {
        pass = true;
        if (x+curr_index < grid_size && x+curr_index-length+1 >= 0)
        {
            for (int i = 0; i < length; i++)
            {
                if (grid[x+curr_index-i][y] != '\0' && word[i] != grid[x+curr_index-i][y])
                {
                    pass = false;
                    break;
                }
            }
            if (pass)
            {
                int arr[] = {x+curr_index, y, x+curr_index-length+1, y};
                wxVector<int> vect(arr, arr + sizeof(arr)/sizeof(arr[0]));
                availablePos.push_back(vect);
            }
        }
    }

    if (oriens[5])
    {
        pass = true;
        if (x+curr_index < grid_size && x+curr_index-length+1 >= 0
            && y+curr_index < grid_size && y+curr_index-length+1 >= 0)
        {
            for (int i = 0; i < length; i++)
            {
                if (grid[x+curr_index-i][y+curr_index-i] != '\0' && word[i] != grid[x+curr_index-i][y+curr_index-i])
                {
                    pass = false;
                    break;
                }
            }
            if (pass)
            {
                int arr[] = {x+curr_index, y+curr_index, x+curr_index-length+1, y+curr_index-length+1};
                wxVector<int> vect(arr, arr + sizeof(arr)/sizeof(arr[0]));
                availablePos.push_back(vect);
            }
        }
    }

    if (oriens[4])
    {
        pass = true;
        if (y+curr_index < grid_size && y+curr_index-length+1 >= 0)
        {
            for (int i = 0; i < length; i++)
            {
                if (grid[x][y+curr_index-i] != '\0' && word[i] != grid[x][y+curr_index-i])
                {
                    pass = false;
                    break;
                }
            }
            if (pass)
            {
                int arr[] = {x, y+curr_index, x, y+curr_index-length+1};
                wxVector<int> vect(arr, arr + sizeof(arr)/sizeof(arr[0]));
                availablePos.push_back(vect);
            }
        }
    }

    if (oriens[3])
    {
        pass = true;
        if (x-curr_index >= 0 && x-curr_index+length-1 < grid_size
            && y+curr_index < grid_size && y+curr_index-length+1 >= 0)
        {
            for (int i = 0; i < length; i++)
            {
                if (grid[x-curr_index+i][y+curr_index-i] != '\0' && word[i] != grid[x-curr_index+i][y+curr_index-i])
                {
                    pass = false;
                    break;
                }
            }
            if (pass)
            {
                int arr[] = {x-curr_index, y+curr_index, x-curr_index+length-1, y+curr_index-length+1};
                wxVector<int> vect(arr, arr + sizeof(arr)/sizeof(arr[0]));
                availablePos.push_back(vect);
            }
        }
    }
    return availablePos;
}

wxVector<int> WordSearchFrame::FindEmpty(wxVector<wxVector<wxUniChar>>& grid, int length, bool oriens[])
{
    wxVector<wxVector<int>> availablePos = wxVector<wxVector<int>>();
    wxVector<int> flippable = wxVector<int>();
    int grid_size = (int)grid.size();
    bool pass;

    for (int x = 0; x < grid_size; x++)
    {
        for (int y = 0; y < grid_size; y++)
        {
            if (oriens[2] || oriens[6])
            {
                pass = true;
                if (x+length-1 < grid_size)
                {
                    for (int i = 0; i < length; i++)
                    {
                        if (grid[x+i][y] != '\0')
                        {
                            pass = false;
                            break;
                        }
                    }
                    if (pass)
                    {
                        int arr[] = {x, y, x+length-1, y};
                        wxVector<int> vect(arr, arr + sizeof(arr)/sizeof(arr[0]));
                        availablePos.push_back(vect);
                        flippable.push_back((oriens[2] && oriens[6])?3:(oriens[2])?1:2);
                    }
                }
            }

            if (oriens[1] || oriens[5])
            {
                pass = true;
                if (x+length-1 < grid_size
                    && y+length-1 < grid_size)
                {
                    for (int i = 0; i < length; i++)
                    {
                        if (grid[x+i][y+i] != '\0')
                        {
                            pass = false;
                            break;
                        }
                    }
                    if (pass)
                    {
                        int arr[] = {x, y, x+length-1, y+length-1};
                        wxVector<int> vect(arr, arr + sizeof(arr)/sizeof(arr[0]));
                        availablePos.push_back(vect);
                        flippable.push_back((oriens[1] && oriens[5])?3:(oriens[1])?1:2);
                    }
                }
            }

            if (oriens[0] || oriens[4])
            {
                pass = true;
                if (y+length-1 < grid_size)
                {
                    for (int i = 0; i < length; i++)
                    {
                        if (grid[x][y+i] != '\0')
                        {
                            pass = false;
                            break;
                        }
                    }
                    if (pass)
                    {
                        int arr[] = {x, y, x, y+length-1};
                        wxVector<int> vect(arr, arr + sizeof(arr)/sizeof(arr[0]));
                        availablePos.push_back(vect);
                        flippable.push_back((oriens[0] && oriens[4])?3:(oriens[0])?1:2);
                    }
                }
            }

            if (oriens[7] || oriens[3])
            {
                pass = true;
                if (y+length-1 < grid_size
                    && x-length+1 >= 0)
                {
                    for (int i = 0; i < length; i++)
                    {
                        if (grid[x-i][y+i] != '\0')
                        {
                            pass = false;
                            break;
                        }
                    }
                    if (pass)
                    {
                        int arr[] = {x, y, x-length+1, y+length-1};
                        wxVector<int> vect(arr, arr + sizeof(arr)/sizeof(arr[0]));
                        availablePos.push_back(vect);
                        flippable.push_back((oriens[7] && oriens[3])?3:(oriens[7])?1:2);
                    }
                }
            }
        }
    }

    if (availablePos.size() == 0)
    {
        return wxVector<int>();
    }
    int index = rand() % availablePos.size();
    int flipnum = rand() % 2;
    if ((flippable[index] == 3 && flipnum == 1) || flippable[index] == 1)
    {
        return availablePos[index];
    }
    wxVector<int> vect = availablePos[index];
    int arr[] = {vect[2],vect[3],vect[0],vect[1]};
    vect = wxVector<int>(arr, arr + sizeof(arr)/sizeof(arr[0]));
    return vect;
}

void WordSearchFrame::PlaceGrid(wxVector<wxVector<wxUniChar>>& grid, wxVector<int> loc, wxString word)
{
    int length = word.length();
    if (loc[2] > loc[0])
    {
        if (loc[1] == loc[3])
        {
            for (int i = 0; i < length; i++)
            {
                grid[loc[0] + i][loc[1]] = word[i];
            }
        }
        else if (loc[1] < loc[3])
        {
            for (int i = 0; i < length; i++)
            {
                grid[loc[0] + i][loc[1] + i] = word[i];
            }
        }
        else
        {
            for (int i = 0; i < length; i++)
            {
                grid[loc[0] + i][loc[1] - i] = word[i];
            }
        }
    }
    else if (loc[2] < loc[0])
    {
        if (loc[1] == loc[3])
        {
            for (int i = 0; i < length; i++)
            {
                grid[loc[0] - i][loc[1]] = word[i];
            }
        }
        else if (loc[1] < loc[3])
        {
            for (int i = 0; i < length; i++)
            {
                grid[loc[0] - i][loc[1] + i] = word[i];
            }
        }
        else
        {
            for (int i = 0; i < length; i++)
            {
                grid[loc[0] - i][loc[1] - i] = word[i];
            }
        }
    }
    else
    {
        if (loc[1] == loc[3])
        {
            for (int i = 0; i < length; i++)
            {
                grid[loc[0]][loc[1]] = word[i];
            }
        }
        else if (loc[1] < loc[3])
        {
            for (int i = 0; i < length; i++)
            {
                grid[loc[0]][loc[1] + i] = word[i];
            }
        }
        else
        {
            for (int i = 0; i < length; i++)
            {
                grid[loc[0]][loc[1] - i] = word[i];
            }
        }
    }
}

float custom_strtof(wxString str, bool& success){
    if(str.length()==0){
        success = false;
        return -1;
    }
    bool neg = false;
    int start=0;
    if(str[0]=='-'){
        neg=true;
        start++;
    }
    float val = 0;
    bool point = false;
    int divide = 0;
    for(int i = start; str[i]; i++){
        int digit = str[i] - '0';
        if(digit >= 0 && digit <=9){
            val = val * 10 + digit;
            if (point){
                divide++;
            }
        }else if(!point && digit == -2){
            point = !point;
        }else{
            success = false;
            return -1;
        }
    }
    success = true;
    if(neg){
        return -val/pow(10,divide);
    }else{
        return val/pow(10,divide);
    }
}

void WordSearchFrame::PlaceWords(wxVector<wxString> ordered_words, bool oriens[])
{
    int grid_size = 0;
    for (int i = 0; i < (int)ordered_words.size(); i++)
    {
        int length = ordered_words[i].length();
        if (length > grid_size)
        {
            grid_size = length;
        }
    }
    bool success = false;
    float size_factor = custom_strtof(SizeFactorTextCtrl->GetLineText(0), success);
    if (!success) {
        SetStatusText("Size factor is invalid", 0);
        return;
    }
    grid_size = size_factor * grid_size;
    if (grid_size <= 0) {
        SetStatusText("Size factor must be positive", 0);
        return;
    }

    int grid_length = (grid_size > 10) ? ((GridPanel -> GetSize().GetHeight() - 20) / grid_size): 40;
    
    positions = wxVector<wxVector<int>>();
    wxVector<wxVector<wxUniChar>> grid = wxVector<wxVector<wxUniChar>>();
    for (int i = 0; i < grid_size; i++)
    {
        grid.push_back(wxVector<wxUniChar>(grid_size, '\0'));
    }

    srand(time(NULL));
    selected_words = wxVector<wxString>();
    while (ordered_words.size() > 0)
    {
        wxVector<wxVector<int>> locs = wxVector<wxVector<int>>();
        int index = 0;//rand() % ordered_words.size()
        wxString curr_word = ordered_words[index];
        for (int i = 0; i < (int)selected_words.size(); i++)
        {
            wxString selected_word = selected_words[i];
            if (selected_word.length() == 0)
            {
                continue;
            }
            int curr_index = 0;
            for (wxString::const_iterator it = curr_word.begin(); it != curr_word.end(); ++it)
            {
                int pos = selected_word.Find(*it);
                while (pos != wxNOT_FOUND)
                {
                    wxVector<wxVector<int>>availablePos = Orientations(grid, curr_word, curr_index, positions[i], pos, oriens);
                    if (availablePos.size() > 0)
                    {
                        for (int ii = 0; ii < (int)availablePos.size(); ii++)
                        {
                            locs.push_back(availablePos[ii]);
                        }
                    }
                    if (pos + 1 == (int)selected_word.length())
                    {
                        break;
                    }
                    int pos2 = selected_word.substr(pos + 1).Find(*it);
                    if (pos2 != wxNOT_FOUND)
                    {
                        pos = pos + 1 + pos2;
                    }
                    else
                    {
                        pos = pos2;
                    }
                }
                curr_index++;
            }
        }
        ordered_words.erase(ordered_words.begin() + index);
        if (locs.size() > 0)
        {
            index = rand() % locs.size();
            positions.push_back(locs[index]);
            selected_words.push_back(curr_word);
            PlaceGrid(grid, locs[index], curr_word);
        }
        else
        {
            wxVector<int> vect = FindEmpty(grid, curr_word.length(), oriens);
            positions.push_back(vect);
            if (vect.size() > 0)
            {
                selected_words.push_back(curr_word);
                PlaceGrid(grid, vect, curr_word);
            }
            else
            {
                selected_words.push_back("");
            }
        }
    }

    if(grid_size > SearchGrid -> GetNumberCols())
    {
        SearchGrid -> AppendCols(grid_size-SearchGrid->GetNumberCols());
    }
    else if (grid_size < SearchGrid->GetNumberCols())
    {
        SearchGrid -> DeleteCols(0, SearchGrid->GetNumberCols()-grid_size);
    }
    if(grid_size > SearchGrid -> GetNumberRows())
    {
        SearchGrid -> AppendRows(grid_size-SearchGrid->GetNumberRows());
    }
    else if(grid_size < SearchGrid -> GetNumberRows())
    {
        SearchGrid -> DeleteRows(0, SearchGrid->GetNumberRows()-grid_size);
    }
    int font_size = 25 / 40.0 * grid_length;
    SearchGrid->SetDefaultCellFont(wxFont(font_size, wxSWISS, wxNORMAL, wxNORMAL, false, _("MS Sans Serif")));
    for (int i = 0; i < grid_size; i++)
    {
        SearchGrid->SetColSize(i, grid_length);
        SearchGrid->SetRowSize(i, grid_length);
    }
    for (int x = 0; x < grid_size; x++)
    {
        for (int y = 0; y < grid_size; y++)
        {
            SearchGrid -> SetCellAlignment(x, y, wxALIGN_CENTRE, wxALIGN_CENTRE);
            if (grid[x][y] == '\0')
            {
                SearchGrid->SetCellValue(x, y, (char)('a' + rand()%26));
                continue;
            }
            SearchGrid->SetCellValue(x, y, grid[x][y]);
        }
    }
    for (int i = 0; i < (int)selected_words.size(); i++)
    {
        if (selected_words[i].IsEmpty())
        {
            WordsCheckListBox->SetString(i, WordsCheckListBox->GetString(i) + " (ommited)");
        }
    }
    showAnswers = false;
    RevealBtn->Enable();
}

void WordSearchFrame::OnGenerateBtnClick(wxCommandEvent& event)
{
    RevealBtn->Enable(false);
    int num_lines = WordsRichTextCtrl->GetNumberOfLines();
    words.clear();
    WordsCheckListBox->Clear();
    for (int i = 0; i < num_lines; i++)
    {
        wxString word = WordsRichTextCtrl->GetLineText(i);
        word.MakeLower();
        words.push_back(word);
        WordsCheckListBox->Append(word);
    }
    //WordsRichTextCtrl->Clear();
    for (int x = 0; x < SearchGrid->GetNumberRows(); x++)
    {
        for (int y = 0; y < SearchGrid->GetNumberCols(); y++)
        {
            SearchGrid -> SetCellBackgroundColour(x, y, wxNullColour);
        }
    }
    bool oriens[] = {LeftRightCheckBox->IsChecked(), TopLeftBottomRightCheckBox->IsChecked()
    ,TopBottomCheckBox->IsChecked(), TopRightBottomLeftCheckBox->IsChecked()
    ,RightLeftCheckBox->IsChecked(), BottomRightTopLeftCheckBox->IsChecked()
    ,BottomTopCheckBox->IsChecked(), BottomLeftTopRightCheckBox->IsChecked()};
    PlaceWords(words, oriens);
}

void WordSearchFrame::ColorIndex(int index, wxColor color)
{
    wxVector<int> loc = positions[index];
    if (loc.size() == 0)
    {
        return;
    }
    if (loc[2] > loc[0])
    {
        if (loc[1] == loc[3])
        {
            for (int i = 0; i < loc[2] - loc[0] + 1; i++)
            {
                SearchGrid->SetCellBackgroundColour(loc[0] + i, loc[1], color);
            }
        }
        else if (loc[1] < loc[3])
        {
            for (int i = 0; i < loc[2] - loc[0] + 1; i++)
            {
                SearchGrid->SetCellBackgroundColour(loc[0] + i, loc[1] + i, color);
            }
        }
        else
        {
            for (int i = 0; i < loc[2] - loc[0] + 1; i++)
            {
                SearchGrid->SetCellBackgroundColour(loc[0] + i, loc[1] - i, color);
            }
        }
    }
    else if (loc[2] < loc[0])
    {
        if (loc[1] == loc[3])
        {
            for (int i = 0; i < loc[0] - loc[2] + 1; i++)
            {
                SearchGrid->SetCellBackgroundColour(loc[0] - i, loc[1], color);
            }
        }
        else if (loc[1] < loc[3])
        {
            for (int i = 0; i < loc[0] - loc[2] + 1; i++)
            {
                SearchGrid->SetCellBackgroundColour(loc[0] - i, loc[1] + i, color);
            }
        }
        else
        {
            for (int i = 0; i < loc[0] - loc[2] + 1; i++)
            {
                SearchGrid->SetCellBackgroundColour(loc[0] - i, loc[1] - i, color);
            }
        }
    }
    else
    {
        if (loc[1] == loc[3])
        {
            for (int i = 0; i < 1; i++)
            {
                SearchGrid->SetCellBackgroundColour(loc[0], loc[1], color);
            }
        }
        else if (loc[1] < loc[3])
        {
            for (int i = 0; i < loc[3] - loc[1] + 1; i++)
            {
                SearchGrid->SetCellBackgroundColour(loc[0], loc[1] + i, color);
            }
        }
        else
        {
            for (int i = 0; i < loc[1] - loc[3] + 1; i++)
            {
                SearchGrid->SetCellBackgroundColour(loc[0], loc[1] - i, color);
            }
        }
    }
}

void WordSearchFrame::OnWordsCheckListBoxToggled(wxCommandEvent& event)
{
    if (!RevealBtn->IsEnabled())
    {
        return;
    }
    int item_no = event.GetSelection();
    if (item_no != wxNOT_FOUND)
    {
        if(!WordsCheckListBox->IsChecked(item_no))
        {
            wxArrayInt arr;
            WordsCheckListBox->GetCheckedItems(arr);
            ColorIndex(item_no, wxNullColour);
            for (int i = 0; i < (int)arr.size(); i++)
            {
                ColorIndex(arr[i], colors[arr[i] % colors.size()]);
            }
        }
        else
        {
            ColorIndex(item_no, colors[item_no % colors.size()]);
        }
        SearchGrid->Refresh();
    }
}

void WordSearchFrame::OnRevealBtnClick(wxCommandEvent& event)
{
    if (showAnswers)
    {
        for (int i = 0; i < WordsCheckListBox->GetCount(); i++)
        {
            WordsCheckListBox->Check(i, false);
        }
        for (int x = 0; x < SearchGrid->GetNumberRows(); x++)
        {
            for (int y = 0; y < SearchGrid->GetNumberCols(); y++)
            {
                SearchGrid->SetCellBackgroundColour(x, y, wxNullColour);
            }
        }
    }
    else
    {
        for (int i = 0; i < WordsCheckListBox->GetCount(); i++)
        {
            WordsCheckListBox->Check(i);
        }
        wxArrayInt arr;
        WordsCheckListBox->GetCheckedItems(arr);
        for (int i = 0; i < (int)arr.size(); i++)
        {
            ColorIndex(arr[i], colors[arr[i] % colors.size()]);
        }
    }
    showAnswers = !showAnswers;
    SearchGrid->Refresh();
}
