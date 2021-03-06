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

#include "VtuxApp.hpp"


bool MyApp::OnInit()
{
    VTux *frame = new VTux();
    frame->Show(true);
    return true;
}

IMPLEMENT_APP(MyApp);