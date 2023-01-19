///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*--------------------------------****************************************----------------------------------
|                                *                                      *                                 |
|  Program Buttons               *       BottonO Class Declarations     *                                 |
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
      
    Child class of ButtonR class

*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef BUTTON_O_HPP
#define BUTTON_O_HPP

#ifdef _MSC_VER
#pragma once
#endif  // _MSC_VER

#include "ButtonR.hpp"

class ButtonO : public ButtonR 
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
    
    // Button rectangle rounded edges outline
    float roundness = 1.0f;


    //----------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------

    // Constructors
    //---------------------------------------------------------------------------------


    /*---------------------------------------------------

        Default construtor (empty)
        - raylib default font

     ----------------------------------------------------*/
    ButtonO();

    /*---------------------------------------------------

        Constructor-1
        - raylib default font
        text, position

     ----------------------------------------------------*/
    ButtonO(string text, float x, float y);

    /*------------------------------------------------------------

        Constructor-2
        - raylib default font
        text, position, font size

        Note: the font size will modify the size of the button

     -------------------------------------------------------------*/
    ButtonO(string text, float x, float y, float font_size);

    /*---------------------------------------------------

        Constructor-3
        - raylib default font
        text, position, font size, font color,
        button color

     ----------------------------------------------------*/
    ButtonO(string text, float x, float y, float font_size, Color font_color, Color btn_color);

    /*---------------------------------------------------

        Constructor-4
        - raylib default font
        text, position, font size, font color,
        button color, border color

     ----------------------------------------------------*/
    ButtonO(string text, float x, float y, float font_size, Color font_color, Color btn_color, Color border_color);

    /*---------------------------------------------------

        Constructor-5
        - loaded font
        text, position, font

     ----------------------------------------------------*/
    ButtonO(string text, float x, float y, Font &font);

    /*---------------------------------------------------

        Constructor-6
        - loaded font
        text, position, font, font size

     ----------------------------------------------------*/
    ButtonO(string text, float x, float y, Font &font, float font_size);

    /*---------------------------------------------------

        Constructor-7
        - loaded font
        text, position, font, font size, font color,
        button color

     ----------------------------------------------------*/
    ButtonO(string text, float x, float y, Font &font, float font_size, Color font_color, Color btn_color);

    /*---------------------------------------------------

        Constructor-8
        - loaded font
        text, position, font, font size, font color,
        button color, border color

     ----------------------------------------------------*/
    ButtonO(string text, float x, float y, Font &font, float font_size, Color font_color, Color btn_color, Color border_color);


    //----------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------

    // Accessors Functions
    //----------------------------------------------------------------------------------

    /*----------------------------------------------------

        draw button
        Not inherited by child classes

     -----------------------------------------------------*/
    void draw();


    //----------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------

    // Mutators Functions
    //---------------------------------------------------------------------------------

    /*----------------------------------------------------

        Updates button

     -----------------------------------------------------*/
    //int update();

private:

    //----------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------

    // Classe Operation Functions (private)
    //---------------------------------------------------------------------------------

};

#endif