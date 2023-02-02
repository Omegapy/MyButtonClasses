///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*--------------------------------****************************************----------------------------------
|                                *                                      *                                 |
|  Program Buttons               *       BottonR Class Definitions      *                                 |
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
    modifying the button's size, we also modify the border's size.

    The button's shadow can be turned on and off.
    The shadow size is computed from the font size and length of the text;
    modifying the button's size, we also modify the shadow's size.

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
    - raylib default font
    text, position

 ----------------------------------------------------*/
ButtonR::ButtonR(string text, float x, float y)
{
    this->text = text;
    rect.x = x;
    rect.y = y;

    buildBtn();
}

//--------------------------------------------------------------------- Constructor-2
/*------------------------------------------------------------

    Constructor-2
    - raylib default font
    text, position, font size

    Note: the font size will modify the size of the button

 -------------------------------------------------------------*/
ButtonR::ButtonR(string text, float x, float y, float fontSize)
{
    this->text = text;
    rect.x = x;
    rect.y = y;
    this->fontSize = fontSize;
   
    buildBtn();
}

//--------------------------------------------------------------------- Constructor-3
/*---------------------------------------------------

    constructor-3
    - raylib default font
    text, position, font size, font color, 
    button color

 ----------------------------------------------------*/
ButtonR::ButtonR(string text, float x, float y, float fontSize, Color fontColor, Color btnColor)
{
    this->text = text;
    rect.x = x;
    rect.y = y;
    this->fontSize = fontSize;
    this->fontColor = fontColor;
    btnIdle = btnColor;

    buildBtn();
}

//--------------------------------------------------------------------- Constructor-4
/*---------------------------------------------------

    constructor-4
    - raylib default font
    text, position, font size, font color,
    button color, border color

 ----------------------------------------------------*/
ButtonR::ButtonR(string text, float x, float y, float fontSize, Color fontColor, Color btnColor, Color borderColor)
{
    this->text = text;
    rect.x = x;
    rect.y = y;
    this->fontSize = fontSize;
    this->fontColor = fontColor;
    btnIdle = btnColor;
    borderIdle = borderColor;

    buildBtn();
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
    rect.x = x;
    rect.y = y;
    this->font = font;

    isRayFont = false;
    
    buildBtn();
}

//--------------------------------------------------------------------- Constructor-6
/*---------------------------------------------------

    constructor-6
    - loaded font
    text, position, font, font size

 ----------------------------------------------------*/
ButtonR::ButtonR(string text, float x, float y, Font &font, float fontSize)
{
    this->text = text;
    rect.x = x;
    rect.y = y;
    this->font = font;
    this->fontSize = fontSize;

    isRayFont = false;

    buildBtn();
}

//--------------------------------------------------------------------- Constructor-7
/*---------------------------------------------------

    constructor-7
    - loaded font
    text, position, font, font size, font color, 
    button color

 ----------------------------------------------------*/
ButtonR::ButtonR(string text, float x, float y, Font &font, float fontSize, Color fontColor, Color btnColor)
{
    this->text = text;
    rect.x = x;
    rect.y = y;
    this->font = font;
    this->fontSize = fontSize;
    this->fontColor = fontColor;
    btnIdle = btnColor;

    isRayFont = false;
    
    buildBtn();
}

//--------------------------------------------------------------------- Constructor-8
/*---------------------------------------------------

    constructor-8
    - loaded font
    text, position, font, font size, font color,
    button color, border color

 ----------------------------------------------------*/
ButtonR::ButtonR(string text, float x, float y, Font &font, float fontSize, Color fontColor, Color btnColor, Color borderColor)
{
    this->text = text;
    rect.x = x;
    rect.y = y;
    this->font = font;
    this->fontSize = fontSize;
    this->fontColor = fontColor;
    btnIdle = btnColor;
    borderIdle = borderColor;

    isRayFont = false;

    buildBtn();
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

    if (isShadow) DrawRectangleRec(shadow, shadowColor);
    DrawRectangleRec(rect, btnLiveColor);
    if (isBorder) DrawRectangleLinesEx(border, borderThickness, borderLiveColor);
    DrawTextEx(font, text.c_str(), textPos, fontSize, fontSpacing, fontColor); 

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

    if (CheckCollisionPointRec(mouse_pos, rect))
    {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            btnLiveColor = btnPressed;
            borderLiveColor = borderPressed;
            result = MOUSE_BUTTON_LEFT;
        }
        else if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
        {
            btnLiveColor = btnPressed;
            borderLiveColor = borderPressed;
            result = MOUSE_BUTTON_RIGHT;
        }
        else if (IsMouseButtonDown(MOUSE_BUTTON_MIDDLE))
        {
            btnLiveColor = btnPressed;
            borderLiveColor = borderPressed;
            result = MOUSE_BUTTON_MIDDLE;
        }
        else
        {
            btnLiveColor = btnHover;
            borderLiveColor = borderHover;
        }
    }
    else
    {
        // state idle
        btnLiveColor = btnIdle;
        borderLiveColor = borderIdle;
    }

    return result;

} // update()


//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

// Mutators Functions
//---------------------------------------------------------------------------------


//--------------------------------------------------------------------- Method buildBtn()
/*----------------------------------------------------------

    Builds the botton,
    computes size from the font size and length of the text

 -----------------------------------------------------------*/
void ButtonR::buildBtn()
{
    //--- Button size
    /*
        The button size is computed from the font size and length of the text
        See mutators to modify the button’s position,
        the text’s position in the button, and the button’s size.
    */
    float ratioWidth = (isRayFont) ? 3.5f : 4.0f,
          ratioHeight = (isRayFont) ? 2.0f : 1.4f;
    textSize = MeasureTextEx(font, text.c_str(), fontSize, fontSpacing);
    oneCharSize = MeasureTextEx(font, "C", fontSize, fontSpacing);
  
    if (resizeBtn)
    {
        //--- Button size
        rect.width = (textSize.x + ratioWidth * oneCharSize.x);
        rect.height = textSize.y * (float)(ratioHeight * (textSize.y / fontSize));
    }
    //--- Centers text in button
    textPos =
    {
        rect.x + (rect.width - textSize.x) / 2,
        rect.y + (rect.height - textSize.y) / 2
    };

    //---- Button border  
    border = rect;
    borderThickness = (rect.width + rect.height) / 150;

    //---- Button shadow
    shadow = { rect.x + 5,  rect.y + 5, rect.width, rect.height };

} // build_btn()

//--------------------------------------------------------------------- Method setFontSize()
/*----------------------------------------------------

     Sets font size and
     Resizes button to fit text
     Takes a string

 -----------------------------------------------------*/
void ButtonR::setFontSize(float fontSize)
{
    this->fontSize = fontSize;
    resizeBtn = true;
    buildBtn();
}

//--------------------------------------------------------------------- Method setFontSizeNoResize()
/*----------------------------------------------------

     Sets font size and
     does NOT resizes button to fit text
     Takes a string

 -----------------------------------------------------*/
void ButtonR::setFontSizeNoResize(float fontSize)
{
    this->fontSize = fontSize;
    resizeBtn = false;
    buildBtn();
}

//--------------------------------------------------------------------- Method setText()
/*----------------------------------------------------

     Sets text and
     Resizes button to fit text
     Takes a string

 -----------------------------------------------------*/
void ButtonR::setText(string text) 
{
    this->text = text;
    resizeBtn = true;
    buildBtn();
}

//--------------------------------------------------------------------- Method setTextNoResize()
/*----------------------------------------------------

     Sets text and 
     does NOT resizes button to fit text
     Takes a string

 -----------------------------------------------------*/
void ButtonR::setTextNoResize(string text) 
{
    this->text = text;
    resizeBtn = false;
    buildBtn();
}

//--------------------------------------------------------------------- Method setTextPosition()
/*----------------------------------------------------

     Sets text position
     does NOT resizes button to fit text

 -----------------------------------------------------*/
void ButtonR::setTextPosition(float x, float y)
{
    textPos.x = x;
    textPos.y = y;
}


//--------------------------------------------------------------------- Method setBtnPosition()
/*----------------------------------------------------

     Sets the button position in the screen

 -----------------------------------------------------*/
void ButtonR::setBtnPosition(float btnX, float btnY)
{
    rect.x = btnX;
    rect.y = btnY;
    buildBtn();
}


//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

// Class Methods Operations (private)
//---------------------------------------------------------------------------------



