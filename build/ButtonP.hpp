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
    float fontSize = 32,
          fontSpacing = 2.0f;
    Color fontColor = RAYWHITE;
    bool isRayFont = true;
    bool is_font = false;
    
    //---- Text
    string text = "Button";
    Vector2 textSize = MeasureTextEx(font, text.c_str(), fontSize, fontSpacing),
            oneCharSize = MeasureTextEx(font, "C", fontSize, fontSpacing);
    
    //--- Button position, size, color
    /*
        The button size is computed from the font size and length of the text
        See mutators to modify the button’s position,
        the text’s position in the button, and the button’s size.
    */
    bool resize_btn = true;
    float btn_width = (textSize.x + 3.5f * oneCharSize.x),
          btn_height = textSize.y * (float)(2.0f * (textSize.y / fontSize));
    Vector2 btnPos = { 750, 100 };
    Rectangle rect{ btnPos.x, btnPos.y, btn_width, btn_height },
              originalRect = rect;
    //--- Centers text in button
    Vector2 textPos =
    {
        rect.x + (rect.width - textSize.x) / 2,
        rect.y + (rect.height - textSize.y) / 2
    };
    // Text position and size
    Rectangle rectText{ textPos.x, textPos.y, textSize.x, textSize.y },
              originalRectText = rectText;

    //---- Button state
    // Button and text image Shading Colors
    Color btnHoverColor = GRAY,
          btnPressedColor = DARKGRAY;
    // Button Image
    Image img = LoadImage("");    // Load image in CPU memory (RAM) // Load image in CPU memory (RAM)                                  
    // Button textures
    Texture2D btnIdle = LoadTextureFromImage(img);  // Image converted to texture, uploaded to GPU memory (VRAM)
    Texture2D btnHover = btnIdle;
    Texture2D btnPressed = btnIdle;
    Texture2D *btnLive = &btnIdle;
    // Text Image
    Image textImg = LoadImage("");
    Texture2D textIdle = LoadTextureFromImage(textImg);
    Texture2D textHover = textIdle;
    Texture2D textPressed = textIdle;
    Texture2D *textLive = &textIdle;

    // window
    int windowWidth = GetScreenWidth();
    int windowHeight = GetScreenHeight();
    Vector2 windowScale = { (float)GetScreenWidth() / windowWidth, (float)GetScreenHeight() / windowHeight };

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
        text, position, image path

     ----------------------------------------------------*/
    ButtonP(string text, float x, float y, string imgPath);

    /*------------------------------------------------------------

        Constructor-2
        - raylib default font
        text, position, image path, font size

        Note: the font size will modify the size of the button

     -------------------------------------------------------------*/
    ButtonP(string text, float x, float y, string imgPath, float fontSize);

    /*---------------------------------------------------

        Constructor-3
        - raylib default font
        text, position, font size, font color,

     ----------------------------------------------------*/
    ButtonP(string text, float x, float y, string imgPath, float fontSize, Color fontColor);


    /*---------------------------------------------------

        Constructor-4
        - loaded font
        text, position, image path, font

     ----------------------------------------------------*/
    ButtonP(string text, float x, float y, string imgPath, Font &font);


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

    

private:


    //----------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------

    // Classe Operation Functions (private)
    //---------------------------------------------------------------------------------

    /*----------------------------------------------------------

        Builds the botton,
        computes size from the font size and length of the text

     -----------------------------------------------------------*/
     void initBtn();


};
#endif