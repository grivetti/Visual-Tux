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

BEGIN_EVENT_TABLE(VTux, wxFrame)
    EVT_MENU(ID_SAVE, VTux::OnSave)
    EVT_MENU(ID_OPEN, VTux::OnOpen)
    EVT_MENU(ID_EXIT, VTux::OnExit)
END_EVENT_TABLE()

VTux::VTux()
        : wxFrame(NULL, wxID_ANY, VTUX_NAME,wxDefaultPosition,wxSize(800,600))
{
    this->menu = new wxMenuBar();
    this->file = new wxMenu();
    this->file->Append(ID_SAVE,wxT("&Save File\tCtrl-S"));
    this->file->Append(ID_OPEN, wxT("&Open File\tCtrl-O"));
    this->file->AppendSeparator();
    this->file->Append(ID_EXIT,wxT("&Exit\tCtrl-Q"));
    this->menu->Append(file, wxT("&File"));
    this->SetMenuBar(menu); 
    this->text = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER | wxTE_MULTILINE);
}

void VTux::OnAbout(wxCommandEvent& event)
{
    wxMessageBox(MDCONCAT("This is the "),
                 MDCONCAT("About "), wxOK | wxICON_INFORMATION);
}
void VTux::OnHello(wxCommandEvent& event)
{
    wxLogMessage(MDCONCAT("Hello from "));
}

void VTux::OnSave(wxCommandEvent &event)
{
    wxFileDialog *saveDialog = new wxFileDialog(this, wxT("Save File"), wxT(""), wxT(""), wxT("Header Files (*.h)|*.h|C++ Files (*.cpp)|*.cpp"), wxFD_SAVE);
    int response = saveDialog->ShowModal();
    if(response == wxID_OK)
    {
        this->text->SaveFile(saveDialog->GetPath());
    }
}

void VTux::OnOpen(wxCommandEvent &event) {
    wxFileDialog *openDialog = new wxFileDialog(this, wxT("Open File"), wxT(""), wxT(""),
                                                wxT("Header Files (*.h)|*.h|C++ Files (*.cpp)|*.cpp"), wxFD_OPEN);
    int response = openDialog->ShowModal();
    if (response == wxID_OK) {
        this->text->LoadFile(openDialog->GetPath());
    }
}

void VTux::OnExit(wxCommandEvent& event)
{
    this->Close(true);
    this->Destroy();
}
