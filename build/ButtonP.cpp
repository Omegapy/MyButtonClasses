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
    init_btn();
}

//--------------------------------------------------------------------- Constructor-1
/*---------------------------------------------------

    constructor-1
    text, position

 ----------------------------------------------------*/
//ButtonP::ButtonP(string text, float x, float y)
//{
//    this->text = text;
//    rec.x = x;
//    rec.y = y;
//
//    ButtonR::build_btn();
//}

//--------------------------------------------------------------------- Constructor-2
/*------------------------------------------------------------

    Constructor-2
    - raylib default font
    text, position, font size

    Note: the font size will modify the size of the button

 -------------------------------------------------------------*/
//ButtonP::ButtonP(string text, float x, float y, float font_size)
//{
//    this->text = text;
//    rec.x = x;
//    rec.y = y;
//    this->font_size = font_size;
//    btn_live_color = btn_color;
//    border_live_color = border_color;
//
//    ButtonR::build_btn();
//}

//--------------------------------------------------------------------- Constructor-3
/*---------------------------------------------------

    constructor-3
    - raylib default font
    text, position, font size, font color,
    button color

 ----------------------------------------------------*/
//ButtonP::ButtonP(string text, float x, float y, float font_size, Color font_color, Color btn_color)
//{
//    this->text = text;
//    rec.x = x;
//    rec.y = y;
//    this->font_size = font_size;
//
//    ButtonR::build_btn();
//}

//--------------------------------------------------------------------- Constructor-4
/*---------------------------------------------------

    constructor-4
    - raylib default font
    text, position, font size, font color,
    button color, border color

 ----------------------------------------------------*/
//ButtonP::ButtonP(string text, float x, float y, float font_size, Color font_color, Color btn_color, Color border_color)
//{
//    this->text = text;
//    rec.x = x;
//    rec.y = y;
//    this->font_size = font_size;
//    this->font_color = font_color;
//    this->btn_live_color = btn_color;
//    this->border_live_color = border_color;
//
//    ButtonR::build_btn();
//}

//--------------------------------------------------------------------- Constructor-5
/*---------------------------------------------------

    constructor-5
    - loaded font
    text, position, font

 ----------------------------------------------------*/
/*ButtonP::ButtonP(string text, float x, float y, Font &font)
{
    this->text = text;
    rec.x = x;
    rec.y = y;
    this->font = font;
    is_ray_font = false;

    ButtonR::build_btn();
}*/

//--------------------------------------------------------------------- Constructor-6
/*---------------------------------------------------

    constructor-6
    - loaded font
    text, position, font, font size

 ----------------------------------------------------*/
//ButtonP::ButtonP(string text, float x, float y, Font &font, float font_size)
//{
//    this->text = text;
//    rec.x = x;
//    rec.y = y;
//    this->font = font;
//    this->font_size = font_size;
//    is_ray_font = false;
//
//    ButtonR::build_btn();
//}

//--------------------------------------------------------------------- Constructor-7
/*---------------------------------------------------

    constructor-7
    - loaded font
    text, position, font, font size, font color,
    button color

 ----------------------------------------------------*/
/*ButtonP::ButtonP(string text, float x, float y, Font &font, float font_size, Color font_color, Color btn_color)
{
    this->text = text;
    rec.x = x;
    rec.y = y;
    this->font = font;
    this->font_size = font_size;
    this->btn_live_color = btn_color;
    this->font_color = font_color;
    is_ray_font = false;

    ButtonR::build_btn();
}*/

//--------------------------------------------------------------------- Constructor-8
/*---------------------------------------------------

    constructor-8
    - loaded font
    text, position, font, font size, font color,
    button color, border color

 ----------------------------------------------------*/
/*ButtonP::ButtonP(string text, float x, float y, Font &font, float font_size, Color font_color, Color btn_color, Color border_color)
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

    ButtonR::build_btn();
}*/

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
   DrawTexturePro( *btn_live, original_rec, rec, { 0, 0 }, 0.0f, WHITE);
   DrawTexturePro( *text_live, original_rec_text, rec_text, { 0, 0 }, 0.0f, WHITE);
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
    Vector2 mouse_pos = GetMousePosition();

    if (IsWindowResized())
    {
        // window scale
        window_scale = { (float)GetScreenWidth() / window_width, (float)GetScreenHeight() / window_height };

        rec = 
        {
            btn_pos.x * window_scale.x,
            btn_pos.y * window_scale.y,
            original_rec.width * window_scale.x,
            original_rec.height * window_scale.y
        };

        rec_text =
        {
            text_pos.x * window_scale.x,
            text_pos.y * window_scale.y,
            original_rec_text.width * window_scale.x,
            original_rec_text.height * window_scale.y
        };

    }

    if (CheckCollisionPointRec(mouse_pos, rec))
    {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            btn_live = &btn_pressed;
            text_live = &text_pressed;
            result = MOUSE_BUTTON_LEFT;
        }
        else if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
        {
            btn_live = &btn_pressed;
            text_live = &text_pressed;
            result = MOUSE_BUTTON_RIGHT;
        }
        else if (IsMouseButtonDown(MOUSE_BUTTON_MIDDLE))
        {
            btn_live = &btn_pressed;
            text_live = &text_pressed;
            result = MOUSE_BUTTON_MIDDLE;
        }
        else
        {
            btn_live = &btn_hover;
            text_live = &text_hover;
        }
    }
    else
    {
        // state idle
        btn_live = &btn_idle;
        text_live = &text_idle;
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
void ButtonP::init_btn()
{
    //----------------------------------------------------------------------------------

    // Variables
    //----------------------------------------------------------------------------------
    
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

    //--- Button size
    rec.width = (text_size.x + ratio_width * one_char_size.x);
    rec.height = text_size.y * (float)(ratio_height * (text_size.y / font_size));
    // Init original rectangle
    btn_pos = { rec.x, rec.y };
    original_rec = rec; // for width and height
    original_rec.x = 0;
    original_rec.y = 0;

    //--- Centers text in button
    text_pos =
    {
        rec.x + (rec.width - text_size.x) / 2,
        rec.y + (rec.height - text_size.y) / 2
    };
    
    // Text position and size
    rec_text = { text_pos.x, text_pos.y, text_size.x, text_size.y },
    // Init original rectangle text
    original_rec_text = rec_text; // for width and height
    original_rec_text.x = 0;
    original_rec_text.y = 0;

    //---- Image
    // Button image
    ImageResize(&img, (int)rec.width, (int)rec.height); // Resize image (Bicubic scaling algorithm)
    // Text image
    text_img =  ImageTextEx(font, text.c_str(), font_size, font_spacing, font_color);
    ImageResize(&text_img, (int)rec_text.width, (int)rec_text.height);

    //---- Button state, idle, hover, pressed, Shades button image
    Image tint_img = ImageCopy(img);
    // Idle
    btn_idle = LoadTextureFromImage(img);  // Image converted to texture, uploaded to GPU memory (VRAM)
    // Hover
    ImageColorTint(&tint_img, btn_hover_color);
    Color *pixels = LoadImageColors(tint_img);    // Load pixel data from image (RGBA 32bit)
    // Update button texture
    btn_hover = LoadTextureFromImage(img);
    UpdateTexture(btn_hover, pixels);
    // Pressed
    ImageColorTint(&tint_img, btn_pressed_color);
    pixels = LoadImageColors(tint_img);
    // Update button texture
    btn_pressed = LoadTextureFromImage(img);
    UpdateTexture(btn_pressed, pixels);

    //---- Text state, idle, hover, pressed, Shades button image
    tint_img = ImageCopy(text_img);
    // Idle
    text_idle = LoadTextureFromImage(text_img);  // Image converted to texture, uploaded to GPU memory (VRAM)
    // Hover
    ImageColorTint(&tint_img, btn_hover_color);
    pixels = LoadImageColors(tint_img);    // Load pixel data from image (RGBA 32bit)
    // Update button texture
    text_hover = LoadTextureFromImage(text_img);
    UpdateTexture(text_hover, pixels);
    // Pressed
    ImageColorTint(&tint_img, btn_pressed_color);
    pixels = LoadImageColors(tint_img);
    // Update button texture
    text_pressed = LoadTextureFromImage(text_img);
    UpdateTexture(text_pressed, pixels);

    //--------------------------------------------------------------------------------------

   // De-Initialization
   //--------------------------------------------------------------------------------------

    UnloadImage(img); // Once image has been converted to texture and uploaded to VRAM, it can be unloaded from RAM
    UnloadImage(text_img);
    UnloadImageColors(pixels);
    
}
