
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

#ifndef __VTUX_FRAME_HPP__
#define __VTUX_FRAME_HPP__

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include <wx/stc/stc.h>


#include "VtuxCodeCtrl.hpp"

#include "VtuxMetadata.hpp"

enum
{
    ID_NEW = 10001,
    ID_SAVE,
    ID_SAVEAS,
    ID_MODIFIED,
    ID_OPEN,
    ID_EXIT,
};


class VTux : public wxFrame
{
public:
    VTux();
protected:
    wxMenuBar *menu;
    wxMenu *file;
    CodeCtrl *text;
    wxString fileName;
    void OnNew(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnOpen(wxCommandEvent &event);
    void OnExit(wxCommandEvent &event);
    void OnSave(wxCommandEvent &event);
    void OnSaveAs(wxCommandEvent& event);
    void OnModified(wxStyledTextEvent& event);
};

#endif