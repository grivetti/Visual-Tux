
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

#include "VtuxMetadata.hpp"

enum
{
    ID_Hello = 1
};

class MyFrame : public wxFrame
{
public:
    MyFrame();
private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
};

#endif