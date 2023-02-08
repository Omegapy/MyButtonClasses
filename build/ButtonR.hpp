
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /*--------------------------------****************************************----------------------------------
  |                                *                                      *                                 |
  |  Program Button Class         *       ButtonR Class Declarations     *                                 |
  |                                *                                      *                                 |
  ---------------------------------****************************************----------------------------------*/
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

    The ButtonR class creates a rectangle-shaped static-size button, window-resized-not-responsive button.
      
    The button size is computed from the font size and length of the text; 
    the text is automatically centered on the button.
    See mutators to modify the button’s position, the text’s position in the button, and the button’s size.

    The button's border can be turned on and off.
    the border's size is computed from the font size and length of the text;
    modifying the button's size will also modify the border's size.

    The button's shadow can be turned on and off.
    The shadow size is computed from the font size and length of the text;
    modifying the button's size will also modify the shadow's size.

    The default font is raylib font.
      
    Parent class to the ButtonO class

    Requirement
    c and c++ 20 or later
    Raylib library: https://www.raylib.com

*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef BUTTON_R_HPP
#define BUTTON_R_HPP

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
  

    
public:



    //----------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------

    // variables (Public)
    //----------------------------------------------------------------------------------
    


     //---- Font 
    Font font = GetFontDefault();
    float fontSize = 32,
          fontSpacing = 3.0f;
    Color fontColor = BLACK;
    bool isRayFont = true;

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
    bool txtResizeBtn = true;
    float btnWidth = (textSize.x + 3.5f * oneCharSize.x),
          btnHeight = textSize.y * (float)(2.0f * (textSize.y / fontSize));
    Rectangle rect{ 100, 100, btnWidth, btnHeight };
    // colors
    Color btnLiveColor = { 222, 214, 202, 255 },
    // Botton state
          btnHover = { 135, 195, 74, 100 },
          btnPressed = { 66, 165, 245, 100 },
          btnIdle = btnLiveColor; // idle state

    //---- Button border  position, size, color, thickness
    /*
        The boder size is computed from the font size and length of the text
        modifying the button's size, we also modify the border's size.
        See mutators for modifying specifically the shadow's size.
    */
    Rectangle border{ rect.x, rect.y, btnWidth, btnHeight };
    // color
    Color borderLiveColor = BLACK,
    // Botton state
          borderHover = { 57, 73, 171, 100 },
          borderPressed = { 0, 105, 92, 100 },
          borderIdle = borderLiveColor; 
    float borderThickness = (rect.width + rect.height) / 150;
    bool isBorder = true;

    //---- Shaddow
    /*
        The shadow size is computed from the font size andlength of the text
        modifying the button's size, we also modify the shadow's size.
        See mutators for modifying specifically the shadow's size and position.
    */
    double shadowOffset = 0.05;
    Rectangle shadow{ rect.x + 5,  rect.y + 5, btnWidth, btnHeight };
    Color shadowColor = GRAY;
    bool isShadow = true;

    //--- Centers text in button
    Vector2 textPos =
    {
        rect.x + (rect.width - textSize.x) / 2,
        rect.y + (rect.height - textSize.y) / 2
    };


    //----------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------

    // Constructors
    //---------------------------------------------------------------------------------


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
    ButtonR(string text, float x, float y, float fontSize);

    /*---------------------------------------------------

        Constructor-3
        - raylib default font
        text, position, font size, font color, 
        button color

     ----------------------------------------------------*/
    ButtonR(string text, float x, float y, float fontSize, Color fontColor, Color btnColor);

    /*---------------------------------------------------

        Constructor-4
        - raylib default font
        text, position, font size, font color,
        button color, border color

     ----------------------------------------------------*/
    ButtonR(string text, float x, float y, float fontSize, Color fontColor, Color btnColor, Color borderColor);

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
    ButtonR(string text, float x, float y, Font &font, float fontSize);

    /*---------------------------------------------------

        Constructor-7
        - loaded font
        text, position, font, font size, font color,
        button color

     ----------------------------------------------------*/
    ButtonR(string text, float x, float y, Font &font, float fontSize, Color fontColor, Color btnColor);

    /*---------------------------------------------------

        Constructor-8
        - loaded font
        text, position, font, font size, font color,
        button color, border color

     ----------------------------------------------------*/
    ButtonR(string text, float x, float y, Font &font, float fontSize, Color fontColor, Color btnColor, Color borderColor);

    /*---------------------------------------------------

        constructor-9
        - loaded font
        text, font, font size

     ----------------------------------------------------*/
    ButtonR(string text, Font &font, float fontSize);


    //----------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------

    // Accessors Methods
    //----------------------------------------------------------------------------------


    /*----------------------------------------------------

        draw button
        Not inherited by child classes

     -----------------------------------------------------*/
    virtual void draw();


    //----------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------

    // Mutators Methods
    //---------------------------------------------------------------------------------


     /*----------------------------------------------------------

        Builds the botton,
        computes size from the font size and length of the text

     -----------------------------------------------------------*/
    void buildBtn();


    /*----------------------------------------------------

        Updates button

     -----------------------------------------------------*/
    int update();

    /*----------------------------------------------------

        Sets font size and
        Resizes button to fit text
        Takes a string

     -----------------------------------------------------*/
    void setFontSize(float fontSize);

    /*----------------------------------------------------

        Sets font size and
        does NOT resizes button to fit text
        Takes a string

     -----------------------------------------------------*/
    void setFontSizeNoResize(float fontSize);

    /*----------------------------------------------------

         Sets text and
         Resizes button to fit text
         Takes a string

     -----------------------------------------------------*/
    void setText(string text);

    /*----------------------------------------------------

         Sets text and
         does NOT resizes button to fit text
         Takes a string

     -----------------------------------------------------*/
    void setTextNoResize(string text);

    /*----------------------------------------------------

         Sets text position
         does NOT resizes button to fit text

     -----------------------------------------------------*/
    void setTextPosition(float x, float y);
   
    /*----------------------------------------------------

       Sets the button position in the screen

     -----------------------------------------------------*/
    void setBtnPosition(float btnX, float btnY);

    /*----------------------------------------------------

        Sets sizes of the button,
        does not resise fonts

     -----------------------------------------------------*/
    void setBtnSize(float btnWidth, float btnHeight);

private:


    //----------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------

    // Classe Operation Functions (private)
    //---------------------------------------------------------------------------------

  
    
};
#endif
