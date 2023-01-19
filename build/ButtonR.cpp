///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*--------------------------------****************************************----------------------------------
|                                *                                      *                                 |
|  Program Buttons               *       BottonO Class Definitions      *                                 |
|                                *                                      *                                 |
---------------------------------****************************************----------------------------------*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

    The ButtonO class creates a rectangle shaped static-size button, window-resized-not-responsive button.
      
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
      
    Parent class to the ButtonO class

    Requirement
    c and c++ 20 or later
    Raylib library: https://www.raylib.com

*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include "ButtonR.hpp"

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
ButtonR::ButtonR()
{
    // Empty, see BontonS.hpp variables
}

//--------------------------------------------------------------------- Constructor-1
/*---------------------------------------------------

    constructor-1 
    text, position

 ----------------------------------------------------*/
ButtonR::ButtonR(string text, float x, float y)
{
    this->text = text;
    rec.x = x;
    rec.y = y;

    build_btn();
}

//--------------------------------------------------------------------- Constructor-2
/*------------------------------------------------------------

    Constructor-2
    - raylib default font
    text, position, font size

    Note: the font size will modify the size of the button

 -------------------------------------------------------------*/
ButtonR::ButtonR(string text, float x, float y, float font_size)
{
    this->text = text;
    rec.x = x;
    rec.y = y;
    this->font_size = font_size;
   
    build_btn();
}

//--------------------------------------------------------------------- Constructor-3
/*---------------------------------------------------

    constructor-3
    - raylib default font
    text, position, font size, font color, 
    button color

 ----------------------------------------------------*/
ButtonR::ButtonR(string text, float x, float y, float font_size, Color font_color, Color btn_color)
{
    this->text = text;
    rec.x = x;
    rec.y = y;
    this->font_size = font_size;
    this->font_color = font_color;
    this->btn_live_color = btn_color;

    build_btn();
}

//--------------------------------------------------------------------- Constructor-4
/*---------------------------------------------------

    constructor-4
    - raylib default font
    text, position, font size, font color,
    button color, border color

 ----------------------------------------------------*/
ButtonR::ButtonR(string text, float x, float y, float font_size, Color font_color, Color btn_color, Color border_color)
{
    this->text = text;
    rec.x = x;
    rec.y = y;
    this->font_size = font_size;
    this->font_color = font_color;
    this->btn_live_color = btn_color;
    this->border_live_color = border_color;

    build_btn();
}

//--------------------------------------------------------------------- Constructor-5
/*---------------------------------------------------

    constructor-5
    - loaded font
    text, position, font

 ----------------------------------------------------*/
ButtonR::ButtonR(string text, float x, float y, Font &font)
{
    this->text = text;
    rec.x = x;
    rec.y = y;
    this->font = font;
    is_ray_font = false;
    
    build_btn();
}

//--------------------------------------------------------------------- Constructor-6
/*---------------------------------------------------

    constructor-6
    - loaded font
    text, position, font, font size

 ----------------------------------------------------*/
ButtonR::ButtonR(string text, float x, float y, Font &font, float font_size)
{
    this->text = text;
    rec.x = x;
    rec.y = y;
    this->font = font;
    this->font_size = font_size;
    is_ray_font = false;

    build_btn();
}

//--------------------------------------------------------------------- Constructor-7
/*---------------------------------------------------

    constructor-7
    - loaded font
    text, position, font, font size, font color, 
    button color

 ----------------------------------------------------*/
ButtonR::ButtonR(string text, float x, float y, Font &font, float font_size, Color font_color, Color btn_color)
{
    this->text = text;
    rec.x = x;
    rec.y = y;
    this->font = font;
    this->font_size = font_size;
    this->btn_live_color = btn_color;
    this->font_color = font_color;
    is_ray_font = false;
    
    build_btn();
}

//--------------------------------------------------------------------- Constructor-8
/*---------------------------------------------------

    constructor-8
    - loaded font
    text, position, font, font size, font color,
    button color, border color

 ----------------------------------------------------*/
ButtonR::ButtonR(string text, float x, float y, Font &font, float font_size, Color font_color, Color btn_color, Color border_color)
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

    build_btn();
}

//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

// Accessors Functions
//----------------------------------------------------------------------------------

//--------------------------------------------------------------------- Function draw()
/*----------------------------------------------------

    Draws button

 -----------------------------------------------------*/
void ButtonR::draw()
{
    update();

    if (is_shadow) DrawRectangleRec(shadow, shadow_color);
    DrawRectangleRec(rec, btn_live_color);
    if (is_border) DrawRectangleLinesEx(border, border_thickness, border_live_color);
    DrawTextEx(font, text.c_str(), text_pos, font_size, font_spacing, font_color); 

}


//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

// Mutators Functions
//---------------------------------------------------------------------------------

//--------------------------------------------------------------------- Function update()
/*----------------------------------------------------

    Updates button

 -----------------------------------------------------*/
int ButtonR::update()
{
    int result = -1;

    // Mouse position
    Vector2 mouse_pos = GetMousePosition();

    if (CheckCollisionPointRec(mouse_pos, rec))
    {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            btn_live_color = btn_pressed;
            border_live_color = border_pressed;
            result = MOUSE_BUTTON_LEFT;
        }
        else if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
        {
            btn_live_color = btn_pressed;
            border_live_color = border_pressed;
            result = MOUSE_BUTTON_RIGHT;
        }
        else if (IsMouseButtonDown(MOUSE_BUTTON_MIDDLE))
        {
            btn_live_color = btn_pressed;
            border_live_color = border_pressed;
            result = MOUSE_BUTTON_MIDDLE;
        }
        else
        {
            btn_live_color = btn_hover;
            border_live_color = border_hover;
        }
    }
    else
    {
        // state idle
        btn_live_color = btn_color;
        border_live_color = border_color;
    }

    return result;

} // update()


//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

// Mutators Functions
//---------------------------------------------------------------------------------


//--------------------------------------------------------------------- Method mod_font_size()
/*----------------------------------------------------

     Modifies font size and
     Resizes button to fit text
     Takes a string

 -----------------------------------------------------*/
void ButtonR::mod_font_size(float font_size)
{
    this->font_size = font_size;
    resize_btn = true;
    build_btn();
}

//--------------------------------------------------------------------- Method mod_font_size_no_resize()
/*----------------------------------------------------

     Modifies font size and
     does NOT resizes button to fit text
     Takes a string

 -----------------------------------------------------*/
void ButtonR::mod_font_size_no_resize(float font_size)
{
    this->font_size = font_size;
    resize_btn = false;
    build_btn();
}

//--------------------------------------------------------------------- Method mod_text()
/*----------------------------------------------------

     Modifies text and
     Resizes button to fit text
     Takes a string

 -----------------------------------------------------*/
void ButtonR::mod_text(string text) 
{
    this->text = text;
    resize_btn = true;
    build_btn();
}

//--------------------------------------------------------------------- Method mod_text_no_resize()
/*----------------------------------------------------

     Modifies text and 
     does NOT resizes button to fit text
     Takes a string

 -----------------------------------------------------*/
void ButtonR::mod_text_no_resize(string text) 
{
    this->text = text;
    resize_btn = false;
    build_btn();
}


//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

// Class Methods Operations (private)
//---------------------------------------------------------------------------------


//--------------------------------------------------------------------- Method build_btn()
/*----------------------------------------------------------

    Builds the botton, 
    computes size from the font size and length of the text

 -----------------------------------------------------------*/
void ButtonR::build_btn()
{
    font_spacing = 2;
    float ratio_width = (is_ray_font) ? 3.5f : 4.0f,
          ratio_height = (is_ray_font) ? 2.0f : 1.4f;     
   
    //--- Button size
    /*
        The button size is computed from the font size and length of the text
        See mutators to modify the button’s position,
        the text’s position in the button, and the button’s size.
    */
    text_size = MeasureTextEx(font, text.c_str(), font_size, font_spacing);
    one_char_size = MeasureTextEx(font, "C", font_size, font_spacing);
    if (resize_btn)
    {
        //--- Button size
        rec.width = (text_size.x + ratio_width * one_char_size.x);
        rec.height = text_size.y * (float)(ratio_height * (text_size.y / font_size));
    }
    //--- Centers text in button
    text_pos =
    {
        rec.x + (rec.width - text_size.x) / 2,
        rec.y + (rec.height - text_size.y) / 2
    };

    //---- Button border  
    border = rec;
    border_thickness = (rec.width + rec.height) / 150;
    
    //---- Button shadow
    float ratio_shadow_y = (is_ray_font) ? 1.0f : 7.0f;
    shadow = { rec.x + 5,  rec.y + 5, rec.width, rec.height };

    
}






