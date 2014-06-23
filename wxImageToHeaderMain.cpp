/***************************************************************
 * Name:      wxImageToHeaderMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    SanAndreasP ()
 * Created:   2014-06-23
 * Copyright: SanAndreasP ()
 * License:
 **************************************************************/

#include "wxImageToHeaderMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(wxImageToHeaderFrame)
#include <wx/intl.h>
#include <wx/string.h>
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

//(*IdInit(wxImageToHeaderFrame)
const long wxImageToHeaderFrame::ID_CHECKBOX1 = wxNewId();
const long wxImageToHeaderFrame::ID_CHECKBOX2 = wxNewId();
const long wxImageToHeaderFrame::ID_STATICBOX1 = wxNewId();
const long wxImageToHeaderFrame::ID_LISTBOX1 = wxNewId();
const long wxImageToHeaderFrame::ID_BUTTON2 = wxNewId();
const long wxImageToHeaderFrame::ID_BUTTON1 = wxNewId();
const long wxImageToHeaderFrame::ID_TEXTCTRL1 = wxNewId();
const long wxImageToHeaderFrame::ID_BUTTON3 = wxNewId();
const long wxImageToHeaderFrame::ID_STATICBOX2 = wxNewId();
const long wxImageToHeaderFrame::ID_RICHTEXTCTRL1 = wxNewId();
const long wxImageToHeaderFrame::ID_CHECKBOX3 = wxNewId();
const long wxImageToHeaderFrame::ID_TEXTCTRL2 = wxNewId();
const long wxImageToHeaderFrame::ID_BUTTON4 = wxNewId();
const long wxImageToHeaderFrame::ID_STATICTEXT1 = wxNewId();
const long wxImageToHeaderFrame::ID_PANEL1 = wxNewId();
const long wxImageToHeaderFrame::ID_TEXTENTRYDIALOG1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(wxImageToHeaderFrame,wxFrame)
    //(*EventTable(wxImageToHeaderFrame)
    //*)
END_EVENT_TABLE()

wxImageToHeaderFrame::wxImageToHeaderFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(wxImageToHeaderFrame)
    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(1000,401));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(216,264), wxSize(1000,424), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    CB_WithAlpha = new wxCheckBox(Panel1, ID_CHECKBOX1, _("with alpha channel"), wxPoint(320,72), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    CB_WithAlpha->SetValue(false);
    CB_FileOut = new wxCheckBox(Panel1, ID_CHECKBOX2, _("output to file:"), wxPoint(320,96), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
    CB_FileOut->SetValue(false);
    StaticBox1 = new wxStaticBox(Panel1, ID_STATICBOX1, _("Selected Images"), wxPoint(16,16), wxSize(288,376), 0, _T("ID_STATICBOX1"));
    LB_Images = new wxListBox(Panel1, ID_LISTBOX1, wxPoint(24,40), wxSize(272,312), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX1"));
    Btn_RemoveFile = new wxButton(Panel1, ID_BUTTON2, _("-"), wxPoint(160,360), wxSize(24,24), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    Btn_AddFile = new wxButton(Panel1, ID_BUTTON1, _("+"), wxPoint(136,360), wxSize(24,24), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    TC_FileOut = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxPoint(336,112), wxSize(168,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TC_FileOut->Disable();
    Btn_FileOut = new wxButton(Panel1, ID_BUTTON3, _("Choose..."), wxPoint(504,112), wxSize(75,24), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    Btn_FileOut->Disable();
    StaticBox2 = new wxStaticBox(Panel1, ID_STATICBOX2, _("Output"), wxPoint(600,16), wxSize(384,376), 0, _T("ID_STATICBOX2"));
    RichTextCtrl1 = new wxRichTextCtrl(Panel1, ID_RICHTEXTCTRL1, wxEmptyString, wxPoint(608,40), wxSize(368,344), wxRE_MULTILINE|wxRE_READONLY, wxDefaultValidator, _T("ID_RICHTEXTCTRL1"));
    wxRichTextAttr rchtxtAttr_1;
    rchtxtAttr_1.SetBulletStyle(wxTEXT_ATTR_BULLET_STYLE_ALIGN_LEFT);
    CB_Compress = new wxCheckBox(Panel1, ID_CHECKBOX3, _("Compress Bytes with EasyCompô"), wxPoint(320,144), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX3"));
    CB_Compress->SetValue(false);
    CB_Compress->Disable();
    TC_Header = new wxTextCtrl(Panel1, ID_TEXTCTRL2, wxEmptyString, wxPoint(320,40), wxSize(256,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    Button1 = new wxButton(Panel1, ID_BUTTON4, _("Convert"), wxPoint(320,216), wxSize(256,32), 0, wxDefaultValidator, _T("ID_BUTTON4"));
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Header-Filename"), wxPoint(320,24), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    FD_ImageFiles = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, _("Portable Network Graphics (*.png)|*.png"), wxFD_DEFAULT_STYLE|wxFD_OPEN|wxFD_FILE_MUST_EXIST|wxFD_MULTIPLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    TED_ImageVarName = new wxTextEntryDialog(this, wxEmptyString, _("Please select a variable name"), wxEmptyString, wxOK|wxCANCEL|wxCENTRE|wxWS_EX_VALIDATE_RECURSIVELY, wxDefaultPosition);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxImageToHeaderFrame::OnBtn_AddFileClick);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxImageToHeaderFrame::OnButton1Click);
    //*)
}

wxImageToHeaderFrame::~wxImageToHeaderFrame()
{
    delete TED_ImageVarName; // wxSmith builder doesn't do this automatically, so...
    //(*Destroy(wxImageToHeaderFrame)
    //*)
}

void wxImageToHeaderFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void wxImageToHeaderFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(wxbuildinfoformat::short_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void wxImageToHeaderFrame::OnBtn_AddFileClick(wxCommandEvent& event)
{
    if( this->FD_ImageFiles->ShowModal() == wxID_OK ) {
        wxArrayString files;
        this->FD_ImageFiles->GetFilenames(files);
        for( wxString file : files ) {
            if( this->TED_ImageVarName->ShowModal() == wxID_OK ) {
                this->m_images.insert(std::pair<std::string, std::string>(this->TED_ImageVarName->GetValue().ToStdString(), file.ToStdString()));
                this->LB_Images->AppendAndEnsureVisible(this->TED_ImageVarName->GetValue());
            }
        }
    }
}

void wxImageToHeaderFrame::OnButton1Click(wxCommandEvent& event)
{
    bool shouldConvert = true;
    if( this->m_images.empty() ) {
        this->LB_Images->SetBackgroundColour(wxColour(255,192,192));
        shouldConvert = false;
    } else {
        this->LB_Images->SetBackgroundColour(wxNullColour);
    }
    this->LB_Images->Refresh();

    if( this->TC_Header->GetValue().IsEmpty() ) {
        this->TC_Header->SetBackgroundColour(wxColour(255,192,192));
        shouldConvert = false;
    } else {
        this->TC_Header->SetBackgroundColour(wxNullColour);
    }
    this->TC_Header->Refresh();

    if( shouldConvert ) {
        std::map<std::string, std::string> convBytes;
        std::stringstream str;
        for( std::pair<std::string, std::string> elem : this->m_images ) {
            wxImage img(elem.second);
            unsigned long imgArea = img.GetWidth()*img.GetHeight();
            unsigned char *imgData = img.GetData();
            for( unsigned long i = 0; i < imgArea*3L; i++ ) {
                str << "\\x" << std::hex << (unsigned int)imgData[i];
            }
            convBytes.insert(std::pair<std::string, std::string>(elem.first, str.str()));
            str.clear();
        }
        str << "#ifndef wxImageToHeaderMAIN_H"
            << "#define wxImageToHeaderMAIN_H";
    }
}
