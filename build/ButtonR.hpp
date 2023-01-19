
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /*--------------------------------****************************************----------------------------------
  |                                *                                      *                                 |
  |  Program ButtonR Class         *       ButtonR Class Declarations     *                                 |
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


class ButtonR
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
    Color btn_color = { 222, 214, 202, 255 },
                      // Botton state
                      btn_hover = { 135, 195, 74, 100 },
                      btn_pressed = { 66, 165, 245, 100 },
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
        border_hover = { 57, 73, 171, 100 },
        border_pressed = { 0, 105, 92, 100 },
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
    Color shadow_color = LIGHTGRAY;
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
    ButtonR();

    /*---------------------------------------------------

        Constructor-1
        - raylib default font
        text, position

     ----------------------------------------------------*/
    ButtonR(string text, float x, float y);

    /*------------------------------------------------------------

        Constructor-2
        - raylib default font
        text, position, font size

        Note: the font size will modify the size of the button

     -------------------------------------------------------------*/
    ButtonR(string text, float x, float y, float font_size);

    /*---------------------------------------------------

        Constructor-3
        - raylib default font
        text, position, font size, font color, 
        button color

     ----------------------------------------------------*/
    ButtonR(string text, float x, float y, float font_size, Color font_color, Color btn_color);

    /*---------------------------------------------------

        Constructor-4
        - raylib default font
        text, position, font size, font color,
        button color, border color

     ----------------------------------------------------*/
    ButtonR(string text, float x, float y, float font_size, Color font_color, Color btn_color, Color border_color);

    /*---------------------------------------------------

        Constructor-5
        - loaded font
        text, position, font 

     ----------------------------------------------------*/
    ButtonR(string text, float x, float y, Font &font);

    /*---------------------------------------------------

        Constructor-6
        - loaded font
        text, position, font, font size

     ----------------------------------------------------*/
    ButtonR(string text, float x, float y, Font &font, float font_size);

    /*---------------------------------------------------

        Constructor-7
        - loaded font
        text, position, font, font size, font color,
        button color

     ----------------------------------------------------*/
    ButtonR(string text, float x, float y, Font &font, float font_size, Color font_color, Color btn_color);

    /*---------------------------------------------------

        Constructor-8
        - loaded font
        text, position, font, font size, font color,
        button color, border color

     ----------------------------------------------------*/
    ButtonR(string text, float x, float y, Font &font, float font_size, Color font_color, Color btn_color, Color border_color);


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
    void ButtonR::mod_is_shadow(bool is_shadow);

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

    /*----------------------------------------------------

        Modifies button color

     -----------------------------------------------------*/
    void mod_button_color(Color btn_color);

    /*----------------------------------------------------

        Modifies button hover color

     -----------------------------------------------------*/
    void mod_button_hover_color(Color btn_hover);

    /*----------------------------------------------------

        Modifies button pressed color

     -----------------------------------------------------*/
    void mod_button_pressed_color(Color btn_hover);

    /*----------------------------------------------------

        Modifies border color

     -----------------------------------------------------*/
    void mod_border_color(Color border_color);

    /*----------------------------------------------------

        Modifies border hover color

     -----------------------------------------------------*/
    void mod_border_hover_color(Color border_hover);

    /*----------------------------------------------------

        Modifies border pressed color

     -----------------------------------------------------*/
    void mod_border_pressed_color(Color border_hover);

    /*----------------------------------------------------

        Modifies border thickness color

     -----------------------------------------------------*/
    void mod_border_thickness(float border_thickness);

    /*----------------------------------------------------

        Modifies shadow color

     -----------------------------------------------------*/
    void mod_shadow_color(Color shadow_color);


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
