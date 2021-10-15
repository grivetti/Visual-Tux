#ifndef __VTUX_APP_HPP__
#define __VTUX_APP_HPP__

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "VtuxFrame.hpp"

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

#endif