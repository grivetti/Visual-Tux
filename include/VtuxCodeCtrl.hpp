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
#ifndef __VTUX_CODE_CONTROL_HPP__
#define __VTUX_CODE_CONTROL_HPP__


#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include <wx/stc/stc.h>

class CodeCtrl : public wxStyledTextCtrl
{
public:
    const int MASK_TAB = (1 << MARKER_TAB);
    const int MASK_EOF = (1 << MARKER_EOF);
    CodeCtrl(wxWindow *parent);
    void OnModified(wxStyledTextEvent& event);
private:
    const int MARGIN_LINE_NUMBERS = 0;
    const wxString CPP_WORD_1 =
        "asm else new this"
        "auto enum operator throw "
        "bool explicit private true "
        "break export protected try "
        "case extern public typedef "
        "catch false register typeid "
        "char float reinterpret_cast typename "
        "class for return union "
        "const friend short unsigned "
        "const_cast goto signed using "
        "continue if sizeof virtual "
        "default inline static void "
        "delete int static__cast volatile "
        "do long struct wchar_t "
        "double mutable switch while "
        "dynamic_cast namespace template";
    const int MARKER_TAB = 1;
    const int MARKER_EOF = 2;
	int markerHandlerEOF = 0;
};

#endif