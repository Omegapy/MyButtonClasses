
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /*--------------------------------****************************************----------------------------------
  |                                *                                      *                                 |
  |  Program ButtonS Class         *       ButtonS Class Declarations     *                                 |
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

#ifndef BUTTON_S_HPP
#define BUTTON_S_HPP

#ifdef _MSC_VER
#pragma once
#endif  // _MSC_VER

#include "raylib.h"

#include <iostream>	// For debugging purposes
#include <string>
#include <vector>

using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//--------------------------------------------- Class <name> ---------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class ButtonS
{
    //----------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------

    // variables (Private)
    //----------------------------------------------------------------------------------
  
     //---- Font 
    Font font = GetFontDefault();
    float font_size = 32,
          font_spacing = 3.0f;
    Color font_color = BLACK;
    bool is_ray_font = true;

    //---- Text
    string text = "Button";
    Vector2 text_size = MeasureTextEx(font, text.c_str(), font_size, font_spacing),
            one_char_size = MeasureTextEx(font, "C", font_size, font_spacing);
    

    //--- Button position, size, color
    /* 
        The button size is computed from the font size and length of the text
        See mutators to modify the button’s position, 
        the text’s position in the button, and the button’s size. 
    */
    bool resize_btn = true;
    float btn_width = (text_size.x + 3.5f * one_char_size.x),
          btn_height = text_size.y * (float)(2.0f * (text_size.y / font_size));
    Rectangle rec{ 100, 100, btn_width, btn_height };
    // color
    Color btn_color = LIGHTGRAY,
                      // Botton state
                      btn_hover = Color{ 66, 165, 245, 100 },
                      btn_pressed = Color{ 135, 195, 74, 100 },
                      btn_idle = btn_color;

    //---- Button border  position, size, color, thickness
    /* 
        The boder size is computed from the font size and length of the text
        modifying the button's size, we also modify the border's size.
        See mutators for modifying specifically the shadow's size.
    */
    Rectangle border{ rec.x, rec.y, btn_width, btn_height };
    // color
    Color border_color = BLACK,
        // Botton state
        border_hover = Color{ 57, 73, 171, 100 },
        border_pressed = Color{ 0, 105, 92, 100 },
        border_idle = border_color;
    float border_thickness = rec.x / 30;
    bool is_border = true;

    //---- Shaddow
    /*
        The shadow size is computed from the font size andlength of the text
        odifying the button's size, we also modify the shadow's size.
        See mutators for modifying specifically the shadow's size and position.
    */
    double shadow_offset = 0.05;
    Rectangle shadow{ (float)(rec.x + rec.x * shadow_offset), (float)(rec.y + rec.y * shadow_offset), btn_width, btn_height };
    Color shadow_color = Color{ 0, 0, 0, 25 };
    bool is_shadow = true;

    //--- Centers text in button
    /*
        See mutators to change text's position in button
    */
    Vector2 text_pos =
    {
        rec.x + (rec.width - text_size.x) / 2,
        rec.y + (rec.height - text_size.y) / 2
    };

    
public:

    //----------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------

    // variables (Public)
    //----------------------------------------------------------------------------------

    /*---------------------------------------------------

        Default construtor (empty)
        - raylib default font

     ----------------------------------------------------*/
    ButtonS();

    /*---------------------------------------------------

        Constructor-1
        - raylib default font
        text, position

     ----------------------------------------------------*/
    ButtonS(string text, float x, float y);

    /*------------------------------------------------------------

        Constructor-2
        - raylib default font
        text, position, font size

        Note: the font size will modify the size of the button

     -------------------------------------------------------------*/
    ButtonS(string text, float x, float y, float font_size);

    /*---------------------------------------------------

        Constructor-3
        - raylib default font
        text, position, font size, font color, 
        button color

     ----------------------------------------------------*/
    ButtonS(string text, float x, float y, float font_size, Color font_color, Color btn_color);

    /*---------------------------------------------------

        Constructor-4
        - raylib default font
        text, position, font size, font color,
        button color, border color

     ----------------------------------------------------*/
    ButtonS(string text, float x, float y, float font_size, Color font_color, Color btn_color, Color border_color);

    /*---------------------------------------------------

        Constructor-5
        - loaded font
        text, position, font 

     ----------------------------------------------------*/
    ButtonS(string text, float x, float y, Font &font);

    /*---------------------------------------------------

        Constructor-6
        - loaded font
        text, position, font, font size

     ----------------------------------------------------*/
    ButtonS(string text, float x, float y, Font &font, float font_size);

    /*---------------------------------------------------

        Constructor-7
        - loaded font
        text, position, font, font size, font color,
        button color

     ----------------------------------------------------*/
    ButtonS(string text, float x, float y, Font &font, float font_size, Color font_color, Color btn_color);

    /*---------------------------------------------------

        Constructor-8
        - loaded font
        text, position, font, font size, font color,
        button color, border color

     ----------------------------------------------------*/
    ButtonS(string text, float x, float y, Font &font, float font_size, Color font_color, Color btn_color, Color border_color);


    //----------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------

    // Accessors Functions
    //----------------------------------------------------------------------------------

    /*----------------------------------------------------

        draw button

     -----------------------------------------------------*/
    void draw();


    //----------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------

    // Mutators Functions
    //---------------------------------------------------------------------------------

    /*----------------------------------------------------

        Updates button

     -----------------------------------------------------*/
    int update();

    /*----------------------------------------------------

         Modifies is border
         True adds a border
         False removes border

     -----------------------------------------------------*/
    void mod_is_border(bool is_border);

    /*----------------------------------------------------

         Modifies is shadow and
         True adds a shadow
         False removes shadow

     -----------------------------------------------------*/
    void ButtonS::mod_is_shadow(bool is_shadow);

    /*----------------------------------------------------

        Modifies font size and
        Resizes button to fit text
        Takes a string

     -----------------------------------------------------*/
    void mod_font_size(float font_size);

    /*----------------------------------------------------

        Modifies font size and
        does NOT resizes button to fit text
        Takes a string

     -----------------------------------------------------*/
    void mod_font_size_no_resize(float font_size);

    /*----------------------------------------------------

         Modifies text and
         Resizes button to fit text
         Takes a string

     -----------------------------------------------------*/
    void mod_text(string text);

    /*----------------------------------------------------

         Modifies text and
         does NOT resizes button to fit text
         Takes a string

     -----------------------------------------------------*/
    void mod_text_no_resize(string text);

private:

    //----------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------

    // Classe Operation Functions (private)
    //---------------------------------------------------------------------------------
    
    /*----------------------------------------------------------

        Builds the botton,
        computes size from the font size and length of the text

     -----------------------------------------------------------*/
    void build_btn();
    
};
#endif
