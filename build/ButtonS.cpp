///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*--------------------------------****************************************----------------------------------
|                                *                                      *                                 |
|  Program Buttons               *       BottonS Class Definitions      *                                 |
|                                *                                      *                                 |
---------------------------------****************************************----------------------------------*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

    The ButtonS class creates a static-size button, window-resized-not-responsive button.
      
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

*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include "ButtonS.hpp"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//--------------------------------------------- Class <name> ---------------------------------------------------
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
ButtonS::ButtonS()
{
    // Empty, see BontonS.hpp variables
}

//--------------------------------------------------------------------- Constructor-1
/*---------------------------------------------------

    constructor-1 
    text, position

 ----------------------------------------------------*/
ButtonS::ButtonS(string text, float x, float y)
{
    this->text = text;
    rec.x = x;
    rec.y = y;

    build_btn(IS_RAY_FONT);
}

//--------------------------------------------------------------------- Constructor-2
/*------------------------------------------------------------

    Constructor-2
    - raylib default font
    text, position, font size

    Note: the font size will modify the size of the button

 -------------------------------------------------------------*/
ButtonS::ButtonS(string text, float x, float y, float font_size)
{
    this->text = text;
    rec.x = x;
    rec.y = y;
    this->font_size = font_size;
   
    build_btn(IS_RAY_FONT);
}

//--------------------------------------------------------------------- Constructor-3
/*---------------------------------------------------

    constructor-3
    - raylib default font
    text, position, font size, font color, 
    button color

 ----------------------------------------------------*/
ButtonS::ButtonS(string text, float x, float y, float font_size, Color font_color, Color btn_color)
{
    this->text = text;
    rec.x = x;
    rec.y = y;
    this->font_size = font_size;
    this->font_color = font_color;
    this->btn_color = btn_color;

    build_btn(IS_RAY_FONT);
}

//--------------------------------------------------------------------- Constructor-4
/*---------------------------------------------------

    constructor-4
    - raylib default font
    text, position, font size, font color,
    button color, border color

 ----------------------------------------------------*/
    ButtonS::ButtonS(string text, float x, float y, float font_size, Color font_color, Color btn_color, Color border_color)
{
    this->text = text;
    rec.x = x;
    rec.y = y;
    this->font_size = font_size;
    this->font_color = font_color;
    this->btn_color = btn_color;
    this->border_color = border_color;

    build_btn(IS_RAY_FONT);
}

//--------------------------------------------------------------------- Constructor-5
/*---------------------------------------------------

    constructor-5
    - loaded font
    text, position, font

 ----------------------------------------------------*/
ButtonS::ButtonS(string text, float x, float y, Font font)
{
    this->text = text;
    rec.x = x;
    rec.y = y;
    this->font = font;
    
    build_btn(IS_NOT_RAY_FONT);
}

//--------------------------------------------------------------------- Constructor-6
/*---------------------------------------------------

    constructor-6
    - loaded font
    text, position, font, font size

 ----------------------------------------------------*/
ButtonS::ButtonS(string text, float x, float y, Font font, float font_size)
{
    this->text = text;
    rec.x = x;
    rec.y = y;
    this->font = font;
    this->font_size = font_size;

    build_btn(IS_NOT_RAY_FONT);
}

//--------------------------------------------------------------------- Constructor-7
/*---------------------------------------------------

    constructor-7
    - loaded font
    text, position, font, font size, font color, 
    button color

 ----------------------------------------------------*/
ButtonS::ButtonS(string text, float x, float y, Font font, float font_size, Color font_color, Color btn_color)
{
    this->text = text;
    rec.x = x;
    rec.y = y;
    this->font = font;
    this->font_size = font_size;
    this->btn_color = btn_color;
    this->font_color = font_color;
    
    build_btn(IS_NOT_RAY_FONT);
}

//--------------------------------------------------------------------- Constructor-8
/*---------------------------------------------------

    constructor-8
    - loaded font
    text, position, font, font size, font color,
    button color, border color

 ----------------------------------------------------*/
ButtonS::ButtonS(string text, float x, float y, Font font, float font_size, Color font_color, Color btn_color, Color border_color)
{
    this->text = text;
    rec.x = x;
    rec.y = y;
    this->font = font;
    this->font_size = font_size;
    this->btn_color = btn_color;
    this->font_color = font_color;
    this->border_color = border_color;

    build_btn(IS_NOT_RAY_FONT);
}

//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

// Accessors Functions
//----------------------------------------------------------------------------------


//--------------------------------------------------------------------- Function update()
/*----------------------------------------------------

    Updates button

 -----------------------------------------------------*/
void ButtonS::update()
{
    //Mouse position
    Vector2 mouse_pos = GetMousePosition();

    if (CheckCollisionPointRec(mouse_pos, rec))
    {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            btn_color = btn_pressed;
        } 
        else
        {
            btn_color = btn_color_hover;
        }
    }
    else
    {
        btn_color = btn_idle;
    }
}

//--------------------------------------------------------------------- Function draw()
/*----------------------------------------------------

    Draws button

 -----------------------------------------------------*/
void ButtonS::draw()
{
    if (is_shadow) DrawRectangleRec(shadow, shadow_color);
    DrawRectangleRec(rec, btn_color);
    if (is_border) DrawRectangleLinesEx(border, border_thickness, border_color);
    DrawTextEx(font, text.c_str(), text_pos, font_size, font_spacing, font_color); // Draw text using font and additional parameters
}


//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

// Mutators Functions
//---------------------------------------------------------------------------------


//--------------------------------------------------------------------- Function <name>()
/*----------------------------------------------------

    Function Description
    Not inherited by child classes

 -----------------------------------------------------*/


//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

// Class Functions Operations (private)
//---------------------------------------------------------------------------------


//--------------------------------------------------------------------- Function build_btn()
/*----------------------------------------------------------

    Builds the botton, 
    computes size from the font size and length of the text

 -----------------------------------------------------------*/
void ButtonS::build_btn(bool is_ray_font)
{
    float ratio_width = (is_ray_font) ? 10.0f : 7.0f;
    float ratio_height = (is_ray_font) ? 2.5f : 1.5f;
   
    //--- Button size
    /*
        The button size is computed from the font size and length of the text
        See mutators to modify the button’s position,
        the text’s position in the button, and the button’s size.
    */
    text_size = MeasureTextEx(font, text.c_str(), font_size, font_spacing);
    one_char_size = MeasureTextEx(font, "C", font_size, font_spacing);

    //--- Button size
    rec.width = (text_size.x + ratio_width * one_char_size.x);
    rec.height = text_size.y * (float)(ratio_height * (text_size.y / font_size));

    //--- Centers text in button
    text_pos =
    {
        rec.x + (rec.width - text_size.x) / 2,
        rec.y + (rec.height - text_size.y) / 2
    };

    //---- Button border  
    border = rec;
}

//--------------------------------------------------------------------- 
/*----------------------------------------------------------

    

 -----------------------------------------------------------*/




