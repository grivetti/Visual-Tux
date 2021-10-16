#include "VtuxCodeCtrl.hpp"

CodeCtrl::CodeCtrl(wxWindow *parent) : wxStyledTextCtrl(parent)
{
	this->StyleClearAll();
	this->SetLexer(wxSTC_LEX_CPP);

	this->SetMarginWidth(MARGIN_LINE_NUMBERS, 50);
	this->StyleSetForeground(wxSTC_STYLE_LINENUMBER, wxColour(75, 75, 75));
	this->StyleSetBackground(wxSTC_STYLE_LINENUMBER, wxColour(220, 220, 220));
	this->SetMarginType(MARGIN_LINE_NUMBERS, wxSTC_MARGIN_NUMBER);

	this->SetWrapMode(wxSTC_WRAP_WORD);
	this->SetUseHorizontalScrollBar(false);

	wxFont font(8, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	this->StyleSetFont(wxSTC_STYLE_LINENUMBER, font);
	this->StyleSetFont(wxSTC_STYLE_DEFAULT, font);
	this->StyleSetFont(wxSTC_C_STRING, font);
	this->StyleSetFont(wxSTC_C_STRING, font);
	this->StyleSetFont(wxSTC_C_PREPROCESSOR, font);
	this->StyleSetFont(wxSTC_C_IDENTIFIER, font);
	this->StyleSetFont(wxSTC_C_NUMBER, font);
	this->StyleSetFont(wxSTC_C_CHARACTER, font);
	this->StyleSetFont(wxSTC_C_WORD, font);
	this->StyleSetFont(wxSTC_C_WORD2, font);
	this->StyleSetFont(wxSTC_C_COMMENT, font);
	this->StyleSetFont(wxSTC_C_COMMENTLINE, font);
	this->StyleSetFont(wxSTC_C_COMMENTDOC, font);
	this->StyleSetFont(wxSTC_C_COMMENTDOCKEYWORD, font);
	this->StyleSetFont(wxSTC_C_COMMENTDOCKEYWORDERROR, font);
	this->StyleSetFont(wxSTC_C_OPERATOR, font);
	this->StyleSetFont(wxSTC_C_DEFAULT, font);

	this->StyleSetForeground(wxSTC_C_STRING, wxColour(150, 0, 0));
	this->StyleSetForeground(wxSTC_C_PREPROCESSOR, wxColour(165, 105, 0));
	this->StyleSetForeground(wxSTC_C_IDENTIFIER, wxColour(40, 0, 60));
	this->StyleSetForeground(wxSTC_C_NUMBER, wxColour(0, 150, 0));
	this->StyleSetForeground(wxSTC_C_CHARACTER, wxColour(150, 0, 0));
	this->StyleSetForeground(wxSTC_C_WORD, wxColour(0, 0, 150));
	this->StyleSetForeground(wxSTC_C_WORD2, wxColour(0, 150, 0));
	this->StyleSetForeground(wxSTC_C_COMMENT, wxColour(150, 150, 150));
	this->StyleSetForeground(wxSTC_C_COMMENTLINE, wxColour(150, 150, 150));
	this->StyleSetForeground(wxSTC_C_COMMENTDOC, wxColour(150, 150, 150));
	this->StyleSetForeground(wxSTC_C_COMMENTDOCKEYWORD, wxColour(0, 0, 200));
	this->StyleSetForeground(wxSTC_C_COMMENTDOCKEYWORDERROR, wxColour(0, 0, 200));

	this->SetKeyWords(0, CPP_WORD_1);

	this->SetEdgeMode(wxSTC_EDGE_BACKGROUND);
	this->SetEdgeColour(wxColour("red"));
	this->SetEdgeColumn(120);

	wxColor yellow("yellow");
	this->MarkerDefine(MARKER_TAB, wxSTC_MARK_ARROW);
	this->MarkerSetForeground(MARKER_TAB, yellow);
	this->MarkerSetBackground(MARKER_TAB, yellow);

	wxColor orange("orange");
	this->MarkerDefine(MARKER_EOF, wxSTC_MARK_ARROW);
	this->MarkerSetForeground(MARKER_EOF, orange);
	this->MarkerSetBackground(MARKER_EOF, orange);

	this->SetUseTabs(false);
	this->SetTabWidth(4);
	this->SetIndent(4);

	this->Bind(wxEVT_STC_MODIFIED, &CodeCtrl::OnModified, this);
}


void CodeCtrl::OnModified(wxStyledTextEvent & event)
{
    int type = event.GetModificationType();
    if ((type & (wxSTC_MOD_INSERTTEXT | wxSTC_MOD_DELETETEXT)) == 0)
    {
        return;
    }
    int linesAdded = event.GetLinesAdded();
    int position = event.GetPosition();
    int curLine = LineFromPosition(position);
    int lineCount = GetLineCount();
    
    for (int j = curLine; (j <= j + linesAdded) && (j < lineCount); ++j)
    {
        int marker = MarkerGet(j);
        bool isTAB = (MASK_TAB & marker) > 0;
        wxString line = GetLineText(j);
        int i = line.find("\t");
        if (i > -1)
        {
            if (!isTAB)
            {
                this->MarkerAdd(j, MARKER_TAB);
            }
        }
        else
        {
            if (isTAB)
            {
                this->MarkerDelete(j, MARKER_TAB);
            }
        }
    }
    
    if (LineLength(lineCount - 1) > 0)
    {
        int markerLine = MarkerLineFromHandle(markerHandlerEOF);
        if (markerLine != lineCount - 1)
        {
            markerHandlerEOF = MarkerAdd(lineCount - 1, MARKER_EOF);
        }
    }
    else
    {
        MarkerDeleteHandle(markerHandlerEOF);
        markerHandlerEOF = 0;
    }
}
