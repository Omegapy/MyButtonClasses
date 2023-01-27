//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*--------------------------------****************************************----------------------------------
|                                *                                      *                                 |
|  Program Buttons               *       BottonP Class Definitions      *                                 |
|                                *                                      *                                 |
---------------------------------****************************************----------------------------------*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

    The ButtonR class creates a rounded edges rectangle shaped static-size button, window-resized-not-responsive button.

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


#include "ButtonP.hpp"


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
ButtonP::ButtonP()
{
    img = LoadImage("resources/images/button1.png");
    initBtn();
}

//--------------------------------------------------------------------- Constructor-1
/*---------------------------------------------------

    constructor-1
    - raylib default font
    text, position. image path

 ----------------------------------------------------*/
ButtonP::ButtonP(string text, float x, float y, string imgPath)
{
    img = LoadImage(imgPath.c_str());
    this->text = text;
    rect.x = x;
    rect.y = y;

    initBtn();
}

//--------------------------------------------------------------------- Constructor-2
/*------------------------------------------------------------

    Constructor-2
    - raylib default font
    text, position, image path, font size

    Note: the font size will modify the size of the button

 -------------------------------------------------------------*/
ButtonP::ButtonP(string text, float x, float y, string imgPath, float fontSize)
{
    img = LoadImage(imgPath.c_str());
    this->text = text;
    rect.x = x;
    rect.y = y;
    this->fontSize = fontSize;

    initBtn();
}

//--------------------------------------------------------------------- Constructor-3
/*---------------------------------------------------

    constructor-3
    - raylib default font
    text, position, image path, font size, font color

 ----------------------------------------------------*/
ButtonP::ButtonP(string text, float x, float y, string imgPath, float fontSize, Color fontColor)
{
    img = LoadImage(imgPath.c_str());
    this->text = text;
    rect.x = x;
    rect.y = y;
    this->fontSize = fontSize;
    this->fontColor = fontColor;

    initBtn();
}

//--------------------------------------------------------------------- Constructor-5
/*---------------------------------------------------

    constructor-4
    - loaded font
    text, position, image path, font

 ----------------------------------------------------*/
ButtonP::ButtonP(string text, float x, float y, string imgPath, Font &font)
{
    img = LoadImage(imgPath.c_str());
    this->text = text;
    rect.x = x;
    rect.y = y;
    this->font = font;

    isRayFont = false;

    initBtn();
}

//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

// Accessors Functions
//----------------------------------------------------------------------------------

//--------------------------------------------------------------------- Function draw()
/*----------------------------------------------------

    Draws button

 -----------------------------------------------------*/
void ButtonP::draw()
{
   update();
   DrawTexturePro( *btnLive, originalRect, rect, { 0, 0 }, 0.0f, WHITE);
   DrawTexturePro( *textLive, originalRectText, rectText, { 0, 0 }, 0.0f, fontColor);
}


//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

// Mutators Functions
//---------------------------------------------------------------------------------


//--------------------------------------------------------------------- Function update()
/*----------------------------------------------------

    Updates button

 -----------------------------------------------------*/
int ButtonP::update()
{
    int result = -1;

    // Mouse position
    Vector2 mousePos = GetMousePosition();

    if (IsWindowResized())
    {
        // window scale
        windowScale = { (float)GetScreenWidth() / windowWidth, (float)GetScreenHeight() / windowHeight };

        rect = 
        {
            btnPos.x * windowScale.x,
            btnPos.y * windowScale.y,
            originalRect.width * windowScale.x,
            originalRect.height * windowScale.y
        };

        rectText =
        {
            textPos.x * windowScale.x,
            textPos.y * windowScale.y,
            originalRectText.width * windowScale.x,
            originalRectText.height * windowScale.y
        };

    }

    if (CheckCollisionPointRec(mousePos, rect))
    {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            btnLive = &btnPressed;
            textLive = &textPressed;
            result = MOUSE_BUTTON_LEFT;
        }
        else if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
        {
            btnLive = &btnPressed;
            textLive = &textPressed;
            result = MOUSE_BUTTON_RIGHT;
        }
        else if (IsMouseButtonDown(MOUSE_BUTTON_MIDDLE))
        {
            btnLive = &btnPressed;
            textLive = &textPressed;
            result = MOUSE_BUTTON_MIDDLE;
        }
        else
        {
            btnLive = &btnHover;
            textLive = &textHover;
        }
    }
    else
    {
        // state idle
        btnLive = &btnIdle;
        textLive = &textIdle;
    }

    return result;

} // update()


//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

// Class Methods Operations (private)
//---------------------------------------------------------------------------------


//--------------------------------------------------------------------- Method build_btn()
/*----------------------------------------------------------

    Builds the botton,
    computes size from the font size and length of the text

 -----------------------------------------------------------*/
void ButtonP::initBtn()
{
    //----------------------------------------------------------------------------------

    // Variables
    //----------------------------------------------------------------------------------
    
    float ratioWidth = (isRayFont) ? 3.5f : 4.0f,
          ratioHeight = (isRayFont) ? 2.2f : 2.0f;

    //--- Button size
    /*
        The button size is computed from the font size and length of the text
        See mutators to modify the button’s position,
        the text’s position in the button, and the button’s size.
    */
    textSize = MeasureTextEx(font, text.c_str(), fontSize, fontSpacing);
    oneCharSize = MeasureTextEx(font, "C", fontSize, fontSpacing);

    //--- Button size
    rect.width = (textSize.x + ratioWidth * oneCharSize.x);
    rect.height = textSize.y * (float)(ratioHeight * (textSize.y / fontSize));
    // Init original rectangle
    btnPos = { rect.x, rect.y };
    originalRect = rect; // for width and height
    originalRect.x = 0;
    originalRect.y = 0;

    //--- Centers text in button
    textPos =
    {
        rect.x + (rect.width - textSize.x) / 2,
        rect.y + (rect.height - textSize.y) / 2
    };
    
    // Text position and size
    rectText = { textPos.x, textPos.y, textSize.x, textSize.y },
    // Init original rectangle text
    originalRectText = rectText; // for width and height
    originalRectText.x = 0;
    originalRectText.y = 0;

    //---- Image
    // Button image
    ImageResize(&img, (int)rect.width, (int)rect.height); // Resize image (Bicubic scaling algorithm)
    // Text image
    textImg =  ImageTextEx(font, text.c_str(), fontSize, fontSpacing, fontColor);
    ImageResize(&textImg, (int)rectText.width, (int)rectText.height);

    //---- Button state, idle, hover, pressed, Shades button image
    Image tintImg = ImageCopy(img);
    // Idle
    btnIdle = LoadTextureFromImage(img);  // Image converted to texture, uploaded to GPU memory (VRAM)
    // Hover
    ImageColorTint(&tintImg, btnHoverColor);
    Color *pixels = LoadImageColors(tintImg);    // Load pixel data from image (RGBA 32bit)
    // Update button texture
    btnHover = LoadTextureFromImage(img);
    UpdateTexture(btnHover, pixels);
    // Pressed
    tintImg = ImageCopy(img);
    ImageColorTint(&tintImg, btnPressedColor);
    pixels = LoadImageColors(tintImg);
    // Update button texture
    btnPressed = LoadTextureFromImage(img);
    UpdateTexture(btnPressed, pixels);

    //---- Text state, idle, hover, pressed, Shades button image
    tintImg = ImageCopy(textImg);
    // Idle
    textIdle = LoadTextureFromImage(textImg);  // Image converted to texture, uploaded to GPU memory (VRAM)
    // Hover
    ImageColorTint(&tintImg, btnHoverColor);
    pixels = LoadImageColors(tintImg);    // Load pixel data from image (RGBA 32bit)
    // Update button texture
    textHover = LoadTextureFromImage(textImg);
    UpdateTexture(textHover, pixels);
    // Pressed
    tintImg = ImageCopy(textImg);
    ImageColorTint(&tintImg, btnPressedColor);
    pixels = LoadImageColors(tintImg);
    // Update button texture
    textPressed = LoadTextureFromImage(textImg);
    UpdateTexture(textPressed, pixels);

    //--------------------------------------------------------------------------------------

   // De-Initialization
   //--------------------------------------------------------------------------------------

    UnloadImage(img); // Once image has been converted to texture and uploaded to VRAM, it can be unloaded from RAM
    UnloadImage(textImg);
    UnloadImage(tintImg);
    UnloadImageColors(pixels);
    
}
