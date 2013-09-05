//------------------------------------------------------------------------------
// Source code generated by wxDesigner from file: MaterialSetting.wdr
// Do not modify this file, all changes will be lost!
//------------------------------------------------------------------------------

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
    #pragma implementation "MaterialSetting_wdr.h"
#endif

// For compilers that support precompilation
#include "wx/wxprec.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

// Include private header
#include "MaterialSetting_wdr.h"

#include <wx/intl.h>

// Euro sign hack of the year
#if wxUSE_UNICODE
    #define __WDR_EURO__ wxT("\u20ac")
#else
    #if defined(__WXMAC__)
        #define __WDR_EURO__ wxT("\xdb")
    #elif defined(__WXMSW__)
        #define __WDR_EURO__ wxT("\x80")
    #else
        #define __WDR_EURO__ wxT("\xa4")
    #endif
#endif

// Implement window functions

wxSizer *MaterialSetting( wxWindow *parent, bool call_fit, bool set_sizer )
{
    wxFlexGridSizer *item0 = new wxFlexGridSizer( 2, 0, 0 );

    wxFlexGridSizer *item1 = new wxFlexGridSizer( 2, 0, 0 );

    wxString *strs2 = (wxString*) NULL;
    wxComboBox *item2 = new wxComboBox( parent, ID_COMBO_MATERIAL, wxT(""), wxDefaultPosition, wxSize(200,-1), 0, strs2, wxCB_DROPDOWN );
    item1->Add( item2, 0, wxALIGN_CENTER|wxALL, 5 );

    wxButton *item3 = new wxButton( parent, ID_BUTTON_SELECT, /*_("Select")*/_("选择器"), wxDefaultPosition, wxDefaultSize, 0 );
    item1->Add( item3, 0, wxALIGN_CENTER|wxALL, 5 );

    wxTextCtrl *item4 = new wxTextCtrl( parent, ID_TEXTCTRL_TEXTURE_NAME, wxT(""), wxDefaultPosition, wxSize(200,-1), wxTE_PROCESS_ENTER );
    item1->Add( item4, 0, wxALIGN_CENTER|wxALL, 5 );

    wxButton *item5 = new wxButton( parent, ID_BUTTON_OPEN, /*_("Open")*/_("打开"), wxDefaultPosition, wxDefaultSize, 0 );
    item1->Add( item5, 0, wxALIGN_CENTER|wxALL, 5 );

    wxStaticText *item6 = new wxStaticText( parent, ID_TEXT, /*_("Emissive")*/_("自发光"), wxDefaultPosition, wxDefaultSize, 0 );
    item1->Add( item6, 0, wxALIGN_CENTER|wxALL, 5 );

    wxButton *item7 = new wxButton( parent, ID_BUTTON_EMISSIVE, wxT(""), wxDefaultPosition, wxSize(120,-1), 0 );
    item1->Add( item7, 0, wxALIGN_CENTER|wxALL, 5 );

    wxStaticText *item8 = new wxStaticText( parent, ID_TEXT_DURATION, /*_("Duration")*/_("周期"), wxDefaultPosition, wxDefaultSize, 0 );
    item1->Add( item8, 0, wxALIGN_CENTER|wxALL, 5 );

    wxTextCtrl *item9 = new wxTextCtrl( parent, ID_TEXTCTRL_DURATION, wxT(""), wxDefaultPosition, wxSize(120,-1), wxTE_PROCESS_ENTER );
    item1->Add( item9, 0, wxALIGN_CENTER|wxALL, 5 );

    wxStaticText *item10 = new wxStaticText( parent, ID_TEXT_DRAW_STYLE, /*_("Draw Style")*/_("画面风格"), wxDefaultPosition, wxDefaultSize, 0 );
    item1->Add( item10, 0, wxALIGN_CENTER|wxALL, 5 );

    wxString strs11[] = 
    {
        //_("常规"), 
        //_("半透明"), 
        //_("变暗"), 
        //_("Alpha混合"), 
        //_("颜色混合"), 
        //_("调整")
        _("Regular"), 
        _("Translucent"), 
        _("Darken"), 
        _("AlphaBlend"), 
        _("ColourBlend"), 
        _("Modulate")
    };
    wxComboBox *item11 = new wxComboBox( parent, ID_COMBO_DRAW_STYLE, wxT(""), wxDefaultPosition, wxSize(120,-1), 6, strs11, wxCB_DROPDOWN );
    item1->Add( item11, 0, wxALIGN_CENTER|wxALL, 5 );

    wxStaticText *item12 = new wxStaticText( parent, ID_TEXT, _("Stage Style"), wxDefaultPosition, wxDefaultSize, 0 );
    item1->Add( item12, 0, wxALIGN_CENTER|wxALL, 5 );

    wxString strs13[] = 
    {
        _("Modulated"), 
        _("TransModulate2X"), 
        _("TransModulate4X")
    };
    wxComboBox *item13 = new wxComboBox( parent, ID_COMBO_STAGE_STYLE, wxT(""), wxDefaultPosition, wxSize(120,-1), 3, strs13, wxCB_DROPDOWN );
    item1->Add( item13, 0, wxALIGN_CENTER|wxALL, 5 );

    wxStaticText *item14 = new wxStaticText( parent, ID_TEXT_TEX_ADD_MODE, /*_("Address Mode")*/_("寻址模式"), wxDefaultPosition, wxDefaultSize, 0 );
    item1->Add( item14, 0, wxALIGN_CENTER|wxALL, 5 );

    wxString strs15[] = 
    {
        //_("包装"), 
        //_("夹取"), 
        //_("竟像")
        _("Wrap"), 
        _("Clamp"), 
        _("Mirror")
    };
    wxComboBox *item15 = new wxComboBox( parent, ID_COMBO_TEX_ADD_MODE, wxT(""), wxDefaultPosition, wxSize(120,-1), 3, strs15, wxCB_DROPDOWN );
    item1->Add( item15, 0, wxALIGN_CENTER|wxALL, 5 );

    wxStaticText *item16 = new wxStaticText( parent, ID_TEXT_TEX_SCALE, /*_("Scale")*/_("放大系数"), wxDefaultPosition, wxDefaultSize, 0 );
    item1->Add( item16, 0, wxALIGN_CENTER|wxALL, 5 );

    wxTextCtrl *item17 = new wxTextCtrl( parent, ID_TEXTCTRL_SCALE, wxT(""), wxDefaultPosition, wxSize(80,-1), wxTE_PROCESS_ENTER );
    item1->Add( item17, 0, wxALIGN_CENTER|wxALL, 5 );

    wxStaticText *item18 = new wxStaticText( parent, ID_TEXT, /*_("Rotate_Anim")*/_("跟随旋转"), wxDefaultPosition, wxDefaultSize, 0 );
    item1->Add( item18, 0, wxALIGN_CENTER|wxALL, 0 );

    wxTextCtrl *item19 = new wxTextCtrl( parent, ID_TEXTCTRL_ROTATE_ANIM, wxT(""), wxDefaultPosition, wxSize(80,-1), wxTE_PROCESS_ENTER );
    item1->Add( item19, 0, wxALIGN_CENTER|wxALL, 5 );

    wxCheckBox *item20 = new wxCheckBox( parent, ID_CHECKBOX_TWO_SIDE, /*_("Two Side")*/_("双面"), wxDefaultPosition, wxDefaultSize, 0 );
    item1->Add( item20, 0, wxALIGN_CENTER|wxALL, 5 );

    wxButton *item21 = new wxButton( parent, ID_BUTTON_SAVE, /*_("Save")*/_("保存"), wxDefaultPosition, wxDefaultSize, 0 );
    item1->Add( item21, 0, wxALIGN_CENTER|wxALL, 5 );

    item0->Add( item1, 0, wxALIGN_CENTER|wxALL, 5 );

    if (set_sizer)
    {
        parent->SetSizer( item0 );
        if (call_fit)
            item0->SetSizeHints( parent );
    }
    
    return item0;
}

// Implement menubar functions

// Implement toolbar functions

// Implement bitmap functions


// End of generated file
