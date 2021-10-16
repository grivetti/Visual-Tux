/***************************
 *
 * THIS FILE IS PART OF THE VISUAL TUX SOFTWARE OR VTUX
 * 
 * GNU AFFERO GENERAL PUBLIC LICENSE
 * 
 * VTUX is free software, you can study, fork and modify
 * as long you respect the license imposed by its creator;
 * VTUX is distributed in the hope that it will be useful
 * for every kind of developer, but it doesn't come without
 * any warranty;
 * =)
*****************************/

#include "VtuxFrame.hpp"


VTux::VTux()
        : wxFrame(NULL, wxID_ANY, VTUX_NAME,wxDefaultPosition,wxSize(800,600))
{
    this->text = new CodeCtrl(this);
    this->menu = new wxMenuBar();
    this->file = new wxMenu();
    this->file->Append(ID_NEW, wxT("&New File\tCtrl-N"));
    this->file->Append(ID_OPEN, wxT("&Open File\tCtrl-O"));
    this->file->AppendSeparator();
    this->file->Append(ID_SAVE,wxT("&Save File\tCtrl-S"));
    this->file->Append(ID_SAVEAS,wxT("&Save File as"));
    this->file->AppendSeparator();
    this->file->Append(ID_EXIT,wxT("&Exit\tCtrl-Q"));
    this->menu->Append(file, wxT("&File"));
    this->SetMenuBar(menu);
    this->CreateStatusBar();
    this->SetStatusText("A C/C++ free software IDE for linux");
    this->Centre();

    this->Bind(wxEVT_MENU, &VTux::OnNew, this, ID_NEW);
    this->Bind(wxEVT_MENU, &VTux::OnOpen, this, ID_OPEN);
    this->Bind(wxEVT_MENU, &VTux::OnSave, this, ID_SAVE);
    this->Bind(wxEVT_MENU, &VTux::OnSaveAs, this, ID_SAVEAS);
    this->Bind(wxEVT_MENU, &VTux::OnExit, this, ID_EXIT);
	this->Bind(wxEVT_STC_CHANGE, &VTux::OnModified, this);
}


void VTux::OnAbout(wxCommandEvent& event)
{
    wxMessageBox(MDCONCAT("This is the "),
                 MDCONCAT("About "), wxOK | wxICON_INFORMATION);
}


void VTux::OnNew(wxCommandEvent& event)
{
    this->fileName = "";
    this->text->ClearAll();
    this->SetStatusText("New file created");
}


void VTux::OnOpen(wxCommandEvent &event) {
    wxFileDialog *openDialog = new wxFileDialog(this, wxT("Open File"), wxT(""), wxT(""),
                                                wxT("C Files (*.c)|*.c|C++ Files (*.cpp)|*.cpp|Header Files (*.h)|*.h"), wxFD_OPEN | wxFD_FILE_MUST_EXIST);
    int response = openDialog->ShowModal();
    
    if (response == wxID_OK)
    {
        this->fileName = openDialog->GetPath();
        if (this->text->LoadFile(this->fileName))
        {
            this->SetStatusText(this->fileName);
        }else
        {
            this->SetStatusText("Could not load file: " + this->fileName);
        }
    }
}


void VTux::OnSave(wxCommandEvent &event)
{
    if (this->fileName.length() > 0) {
        if (this->text->GetModify()) {
            if (this->text->SaveFile(fileName))
            {
                this->SetStatusText("Saving File: " + this->fileName);
            }else
            {
                this->SetStatusText("Could not save File: " + this->fileName);
            }
        }
    }
    else
    {
        this->OnSaveAs(event);
    }
}


void VTux::OnSaveAs(wxCommandEvent &event) {
    wxFileDialog *openDialog = new wxFileDialog(this, wxT("Open File"), wxT(""), wxT(""),
                                                wxT("C Files (*.c)|*.c|C++ Files (*.cpp)|*.cpp|Header Files (*.h)|*.h"), wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
    int response = openDialog->ShowModal();
    
    if (response == wxID_OK)
    {
        this->fileName = openDialog->GetPath();
        if (this->text->SaveFile(this->fileName))
        {
            this->SetStatusText(this->fileName);
        }else
        {
            this->SetStatusText("Could not load file: " + this->fileName);
        }
    }
}


void VTux::OnExit(wxCommandEvent& event)
{
    this->Close(true);
    this->Destroy();
}


void VTux::OnModified(wxStyledTextEvent & event)
{
	if (this->text->GetModify())
    {
        this->SetStatusText("File Modified");
    }
    else
    {
        this->SetStatusText("");
    }
}
