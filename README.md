-----------------------------------------------------------------------------------------------------------------------------

						My Button Classes

Button classes in c++ and the raylib library.

 Alejandro (Alex) Ricciardi
 created date: 01/05/2023
 Initialized with MyRaylibTemplate
 https://github.com/Omegapy/MyRaylibTemplate

-----------------------------------------------------------------------------------------------------------------------------
Requirements:

c and c++ 20 or later  
MS Windows 10 or later 
Raylib library: https://www.raylib.com

-----------------------------------------------------------------------------------------------------------------------------
Project description:

The project contains my button classes in c++ and the raylib library.

~~~c++
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
*/
ButtonR button;

/*
    The ButtonO class creates a rounded edges rectangle shaped static-size button, window-resized-not-responsive button.

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
ButtonO button;

/*
    The ButtonP class creates a responsive button from an image.
    (The button resizes with the window)

    The button size is computed from the font size and length of the text;
    the text is automatically centered on the button.
    See mutators to modify the button’s position, the text’s position in the button, and the button’s size.

    The default font is raylib font.
*/
ButtonP button;
~~~

-----------------------------------------------------------------------------------------------------------------------------

Links  :  
Project GitHub: https://github.com/Omegapy/MyButtonClasses  
GitHub: https://github.com/Omegapy  
YouTube: https://www.youtube.com/@omegapy (new)

-----------------------------------------------------------------------------------------------------------------------------
Credits:

Example button image:  
<a href='https://pngtree.com/so/icons'>icons png from pngtree.com/</a>

