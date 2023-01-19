//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*--------------------------------****************************************----------------------------------
|                                *                                      *                                 |
|  Program Buttons               *       BottonO Class Definitions      *                                 |
|                                *                                      *                                 |
---------------------------------****************************************----------------------------------*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

    The ButtonR class creates a rectangle shaped static-size button, window-resized-not-responsive button.

    The button size is computed from the font size and length of the text;
    the text is automatically centered on the button.
    See mutators to  modify the button’s position, the text’s position in the button, and the button’s size.

    The button's border can be turn on and off.
    the border's size is computed from the font size and length of the text;
    modifying the button's size, we also modify the border's size.
    See mutators for modifying specifically the shadow's size.

    The button's shadow can be turn on and off.
    The shadow size is computed from the font size and length of the text;
    modifying the button's size, we also modify the shadow's size.
    See mutators for modifying specifically the shadow's size and position.

    The default font is raylib font.

    Requirement
    c and c++ 20 or later
    Raylib library: https://www.raylib.com



*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include "ButtonO.hpp"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//--------------------------------------------- Class ButtonR ---------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

// Constructors
//----------------------------------------------------------------------------------


//--------------------------------------------------------------------- Default constructor
/*---------------------------------------------------

    Default construtor
    - raylib default font

 ----------------------------------------------------*/
ButtonO::ButtonO()
{
   
}

//--------------------------------------------------------------------- Constructor-1
/*---------------------------------------------------

    constructor-1
    text, position

 ----------------------------------------------------*/
ButtonO::ButtonO(string text, float x, float y)
{
    this->text = text;
    rec.x = x;
    rec.y = y;

    ButtonR::build_btn();
}

//--------------------------------------------------------------------- Constructor-2
/*------------------------------------------------------------

    Constructor-2
    - raylib default font
    text, position, font size

    Note: the font size will modify the size of the button

 -------------------------------------------------------------*/
ButtonO::ButtonO(string text, float x, float y, float font_size)
{
    this->text = text;
    rec.x = x;
    rec.y = y;
    this->font_size = font_size;
    btn_live_color = btn_color;
    border_live_color = border_color;

    ButtonR::build_btn();
}

//--------------------------------------------------------------------- Constructor-3
/*---------------------------------------------------

    constructor-3
    - raylib default font
    text, position, font size, font color,
    button color

 ----------------------------------------------------*/
ButtonO::ButtonO(string text, float x, float y, float font_size, Color font_color, Color btn_color)
{
    this->text = text;
    rec.x = x;
    rec.y = y;
    this->font_size = font_size;

    ButtonR::build_btn();
}

//--------------------------------------------------------------------- Constructor-4
/*---------------------------------------------------

    constructor-4
    - raylib default font
    text, position, font size, font color,
    button color, border color

 ----------------------------------------------------*/
ButtonO::ButtonO(string text, float x, float y, float font_size, Color font_color, Color btn_color, Color border_color)
{
    this->text = text;
    rec.x = x;
    rec.y = y;
    this->font_size = font_size;
    this->font_color = font_color;
    this->btn_live_color = btn_color;
    this->border_live_color = border_color;

    ButtonR::build_btn();
}

//--------------------------------------------------------------------- Constructor-5
/*---------------------------------------------------

    constructor-5
    - loaded font
    text, position, font

 ----------------------------------------------------*/
ButtonO::ButtonO(string text, float x, float y, Font &font)
{
    this->text = text;
    rec.x = x;
    rec.y = y;
    this->font = font;
    is_ray_font = false;

    ButtonR::build_btn();
}

//--------------------------------------------------------------------- Constructor-6
/*---------------------------------------------------

    constructor-6
    - loaded font
    text, position, font, font size

 ----------------------------------------------------*/
ButtonO::ButtonO(string text, float x, float y, Font &font, float font_size)
{
    this->text = text;
    rec.x = x;
    rec.y = y;
    this->font = font;
    this->font_size = font_size;
    is_ray_font = false;

    ButtonR::build_btn();
}

//--------------------------------------------------------------------- Constructor-7
/*---------------------------------------------------

    constructor-7
    - loaded font
    text, position, font, font size, font color,
    button color

 ----------------------------------------------------*/
ButtonO::ButtonO(string text, float x, float y, Font &font, float font_size, Color font_color, Color btn_color)
{
    this->text = text;
    rec.x = x;
    rec.y = y;
    this->font = font;
    this->font_size = font_size;
    this->btn_live_color = btn_color;
    this->font_color = font_color;
    is_ray_font = false;

    ButtonR::build_btn();
}

//--------------------------------------------------------------------- Constructor-8
/*---------------------------------------------------

    constructor-8
    - loaded font
    text, position, font, font size, font color,
    button color, border color

 ----------------------------------------------------*/
ButtonO::ButtonO(string text, float x, float y, Font &font, float font_size, Color font_color, Color btn_color, Color border_color)
{
    this->text = text;
    rec.x = x;
    rec.y = y;
    this->font = font;
    this->font_size = font_size;
    this->btn_live_color = btn_color;
    this->font_color = font_color;
    this->border_live_color = border_color;
    is_ray_font = false;

    ButtonR::build_btn();
}

//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

// Accessors Functions
//----------------------------------------------------------------------------------

//--------------------------------------------------------------------- Function draw()
/*----------------------------------------------------

    Draws button

 -----------------------------------------------------*/
void ButtonO::draw()
{
    ButtonR::update();

    if (is_shadow) DrawRectangleRounded(shadow, roundness, 4, shadow_color);
    DrawRectangleRounded(rec, roundness, 1, btn_live_color);
    if (is_border)  DrawRectangleRoundedLines(border, roundness, 4, border_thickness, border_live_color);
    DrawTextEx(font, text.c_str(), text_pos, font_size, font_spacing, font_color);
}


//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

// Mutators Functions
//---------------------------------------------------------------------------------



//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

// Class Methods Operations (private)
//---------------------------------------------------------------------------------



