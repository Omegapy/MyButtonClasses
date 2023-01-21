///////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /*--------------------------------****************************************----------------------------------
  |                                *                                      *                                 |
  |  Program Button Class          *       ButtonP Class Declarations     *                                 |
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

    Parent class to the ButtonO class

    Requirement
    c and c++ 20 or later
    Raylib library: https://www.raylib.com

*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef BUTTON_P_HPP
#define BUTTON_P_HPP

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


class ButtonP
{


    //----------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------

    // variables (Private)
    //----------------------------------------------------------------------------------



public:



    //----------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------

    // variables (Public)
    //----------------------------------------------------------------------------------
    
   
     //---- Font 
    Font font = GetFontDefault(); // Raylib default font
    float font_size = 32,
          font_spacing = 2.0f;
    Color font_color = RAYWHITE;
    bool is_ray_font = true;
    bool is_font = false;
    
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
    Vector2 btn_pos = { 850, 100 };
    Rectangle rec{ btn_pos.x, btn_pos.y, btn_width, btn_height },
              original_rec = rec;
    //--- Centers text in button
    Vector2 text_pos =
    {
        rec.x + (rec.width - text_size.x) / 2,
        rec.y + (rec.height - text_size.y) / 2
    };
    // Text position and size
    Rectangle rec_text{ text_pos.x, text_pos.y, text_size.x, text_size.y },
              original_rec_text = rec_text;

    //---- Button state
    // Button and text image Shading Colors
    Color btn_hover_color = BROWN,
          btn_pressed_color = GRAY;
    // Button Image
    Image img = LoadImage("");    // Load image in CPU memory (RAM) // Load image in CPU memory (RAM)                                  
    // Button textures
    Texture2D btn_idle = LoadTextureFromImage(img);  // Image converted to texture, uploaded to GPU memory (VRAM)
    Texture2D btn_hover = btn_idle;
    Texture2D btn_pressed = btn_idle;
    Texture2D *btn_live = &btn_idle;
    // Text Image
    Image text_img = LoadImage("");
    Texture2D text_idle = LoadTextureFromImage(text_img);
    Texture2D text_hover = text_idle;
    Texture2D text_pressed = text_idle;
    Texture2D *text_live = &text_idle;

    // window
    int window_width = GetScreenWidth();
    int window_height = GetScreenHeight();
    Vector2 window_scale = { (float)GetScreenWidth() / window_width, (float)GetScreenHeight() / window_height };

    //----------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------

    // Constructors
    //---------------------------------------------------------------------------------


    /*---------------------------------------------------

        Default construtor (empty)
        - raylib default font

     ----------------------------------------------------*/
    ButtonP();

    /*---------------------------------------------------

        Constructor-1
        - raylib default font
        text, position

     ----------------------------------------------------*/
    //ButtonP(string text, float x, float y);

    /*------------------------------------------------------------

        Constructor-2
        - raylib default font
        text, position, font size

        Note: the font size will modify the size of the button

     -------------------------------------------------------------*/
    //ButtonP(string text, float x, float y, float font_size);

    /*---------------------------------------------------

        Constructor-3
        - raylib default font
        text, position, font size, font color,
        button color

     ----------------------------------------------------*/
    //ButtonP(string text, float x, float y, float font_size, Color font_color, Color btn_color);

    /*---------------------------------------------------

        Constructor-4
        - raylib default font
        text, position, font size, font color,
        button color, border color

     ----------------------------------------------------*/
    //ButtonP(string text, float x, float y, float font_size, Color font_color, Color btn_color, Color border_color);

    /*---------------------------------------------------

        Constructor-5
        - loaded font
        text, position, font

     ----------------------------------------------------*/
    //ButtonR(string text, float x, float y, Font &font);

    /*---------------------------------------------------

        Constructor-6
        - loaded font
        text, position, font, font size

     ----------------------------------------------------*/
    //ButtonP(string text, float x, float y, Font &font, float font_size);

    /*---------------------------------------------------

        Constructor-7
        - loaded font
        text, position, font, font size, font color,
        button color

     ----------------------------------------------------*/
    //ButtonP(string text, float x, float y, Font &font, float font_size, Color font_color, Color btn_color);

    /*---------------------------------------------------

        Constructor-8
        - loaded font
        text, position, font, font size, font color,
        button color, border color

     ----------------------------------------------------*/
    //ButtonP(string text, float x, float y, Font &font, float font_size, Color font_color, Color btn_color, Color border_color);


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

        Modifies font size and
        Resizes button to fit text
        Takes a string

     -----------------------------------------------------*/
    //void mod_font_size(float font_size);

    /*----------------------------------------------------

        Modifies font size and
        does NOT resizes button to fit text
        Takes a string

     -----------------------------------------------------*/
    //void mod_font_size_no_resize(float font_size);

    /*----------------------------------------------------

         Modifies text and
         Resizes button to fit text
         Takes a string

     -----------------------------------------------------*/
    //void mod_text(string text);

    /*----------------------------------------------------

         Modifies text and
         does NOT resizes button to fit text
         Takes a string

     -----------------------------------------------------*/
    //void mod_text_no_resize(string text);


    /*----------------------------------------------------------

        Builds the botton,
        computes size from the font size and length of the text

     -----------------------------------------------------------*/
    //void build_btn();



private:


    //----------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------

    // Classe Operation Functions (private)
    //---------------------------------------------------------------------------------

    /*----------------------------------------------------------

        Builds the botton,
        computes size from the font size and length of the text

     -----------------------------------------------------------*/
     void init_btn();


};
#endif