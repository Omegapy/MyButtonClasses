///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*--------------------------------****************************************----------------------------------
|                                *                                      *                                 |
|  Program Buttons               *       BottonR Class Definitions      *                                 |
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

****** Please see the README.txt file for more information about this project **********

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
    this->btn_color = btn_color;

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
    this->btn_color = btn_color;
    this->border_color = border_color;

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
    this->btn_color = btn_color;
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
    this->btn_color = btn_color;
    this->font_color = font_color;
    this->border_color = border_color;
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
    if (is_shadow) DrawRectangleRec(shadow, shadow_color);
    DrawRectangleRec(rec, btn_color);
    if (is_border) DrawRectangleLinesEx(border, border_thickness, border_color);
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
            btn_color = btn_pressed;
            result = MOUSE_BUTTON_LEFT;
        }
        else if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
        {
            btn_color = btn_pressed;
            result = MOUSE_BUTTON_RIGHT;
        }
        else if (IsMouseButtonDown(MOUSE_BUTTON_MIDDLE))
        {
            btn_color = btn_pressed;
            result = MOUSE_BUTTON_MIDDLE;
        }
        else
        {
            btn_color = btn_hover;
            border_color = border_hover;
        }
    }
    else
    {
        btn_color = btn_idle;
        border_color = border_idle;
    }

    return result;

} // update()


//--------------------------------------------------------------------- Method mod_is_border()
/*----------------------------------------------------

     Modifies is border 
     True adds a border
     False removes border

 -----------------------------------------------------*/
void ButtonR::mod_is_border(bool is_border)
{
    this->is_border = is_border;
}

//--------------------------------------------------------------------- Method mod_is_shadow()
/*----------------------------------------------------

     Modifies is shadow 
     True adds a shadow
     False removes shadow

 -----------------------------------------------------*/
void ButtonR::mod_is_shadow(bool is_shadow)
{
    this->is_shadow = is_shadow;
}


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

// --------------------------------------------------------------------- Method mod_button_color()
/*----------------------------------------------------

     Modifies button color

 -----------------------------------------------------*/
void ButtonR::mod_button_color(Color btn_color)
{
    this->btn_color = btn_color;
    this->btn_idle = btn_color;
}

// --------------------------------------------------------------------- Method mod_button_hover_color()
/*----------------------------------------------------

     Modifies button hover color

 -----------------------------------------------------*/
void ButtonR::mod_button_hover_color(Color btn_hover)
{
    this->btn_hover = btn_hover;
}

// --------------------------------------------------------------------- Method mod_button_pressed_color()
/*----------------------------------------------------

     Modifies button pressed color

 -----------------------------------------------------*/
void ButtonR::mod_button_pressed_color(Color btn_pressed)
{
    this->btn_pressed = btn_pressed;
}

// --------------------------------------------------------------------- Method mod_border_color()
/*----------------------------------------------------

     Modifies border color

 -----------------------------------------------------*/
void ButtonR::mod_border_color(Color border_color)
{
    this->border_color = border_color;
}

// --------------------------------------------------------------------- Method mod_border_hover_color()
/*----------------------------------------------------

     Modifies border hover color

 -----------------------------------------------------*/
void ButtonR::mod_border_hover_color(Color border_hover)
{
    this->border_hover = border_hover;
}

// --------------------------------------------------------------------- Method mod_border_pressed_color()
/*----------------------------------------------------

     Modifies border pressed color

 -----------------------------------------------------*/
void ButtonR::mod_border_pressed_color(Color border_pressed)
{
    this->border_pressed = border_pressed;
}

// --------------------------------------------------------------------- Method mod_border_thickness()
/*----------------------------------------------------

     Modifies border thickness

 -----------------------------------------------------*/
void ButtonR::mod_border_thickness(float border_thickness)
{
    this->border_thickness = border_thickness/30;
}

// --------------------------------------------------------------------- Method mod_shadow_color()
/*----------------------------------------------------

     Modifies shadow color

 -----------------------------------------------------*/
void ButtonR::mod_shadow_color(Color shadow_color)
{
    this->shadow_color = shadow_color;
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
          ratio_height = (is_ray_font) ? 2.0f : 1.4f,
          ratio_thickness = (is_ray_font) ? 30.0f : 35.0f;
        
   
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
        border_thickness = rec.x / ratio_thickness;
    
        //---- Button shadow
        float ratio_shadow_y = (is_ray_font) ? 1.0f : 7.0f;
        shadow = { (float)floor((rec.x + rec.x * shadow_offset)), (float)(rec.y + rec.y * shadow_offset) - ratio_shadow_y , rec.width, rec.height };
    
}






