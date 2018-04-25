/***********************************************************************
************************************************************************
**                                                                    **
**       --------------Sparking Bitmap Converter--------------        **
**     Developed for I2C LCD, an easy-to-use display tool for makers. **
**                       Joney.S@foxmail.com                          **
**                                                                    **
************************************************************************
************************************************************************
*
* Code generated by
*
*        Sparking-BitmapConverter v1.0
*        Compiled May 15 2015
*        Sparking Work Speace
*
************************************************************************
*
* Source file: logo.bmp
* Dimensions:  39 * 64
*
************************************************************************
*/

#include "I2C_LCD.h"


#ifndef GUI_STORAGE_PTR
  #define GUI_STORAGE_PTR PROGMEM
#endif


const unsigned char GUI_STORAGE_PTR aclogo[] = {
  ________, ________, XXXXXXXX, ________, ________,
  ________, _____XXX, XXXXXXXX, XXXX____, ________,
  ________, ___XXXXX, XXXXX_XX, XXXXX___, ________,
  ________, __XXXXXX, XXXX____, XXXXXXX_, ________,
  ________, _XXX__XX, XXX_____, ____XXXX, ________,
  ________, _XXXXXXX, XXX_____, ______XX, X_______,
  _____XX_, XXXXXXXX, XX______, _______X, X_______,
  _____XXX, XXXXXXXX, XXXX____, ________, XX______,
  _____XXX, XXXXXXXX, XXXXXX__, ________, _X______,
  _____XXX, XXXXXXXX, XXXXXX_X, XXXXX___, _XX_____,
  _____XXX, XXXXXX__, _XXXX__X, XXXXXX_X, XXX_____,
  ______XX, XX___X__, _XXXX__X, XXXXXX_X, XXX_____,
  ______XX, XXXXXX__, _XXXX__X, XXXXXX_X, XXX_____,
  ______X_, __X_____, __XX__XX, XXXXXX_X, XXX_____,
  ______XX, XXXXXXXX, _______X, XXXXXX_X, XXX_____,
  ______X_, ________, XXXXXXX_, ___XXX_X, XXX_____,
  ______X_, ________, X____XXX, XXXXXX__, XXX_____,
  ______X_, ________, X____X_X, X____XXX, _XX_____,
  ______X_, ________, X___X__X, ______XX, XX______,
  ______X_, ________, X___X___, __XX___X, _X______,
  ______X_, ________, X___X_X_, _XX_X__X, _X______,
  _____XX_, ________, X_____X_, XX___X_X, _X______,
  _____X__, ________, ________, X____X_X, _X______,
  _____X__, ________, ________, X____X_X, _X______,
  _____X__, _______X, ______X_, _X__XX_X, _X______,
  _____XXX, ___XX_XX, ______X_, _XXXXX_X, XX______,
  _____X__, _______X, ______X_, _XXXXX_X, XX______,
  _____X__, ________, ______X_, _XXXXX_X, X_______,
  _____XX_, ___X___X, ______X_, _XXXXX_X, X_______,
  ______X_, ___X___X, ____X_X_, _XXXXX_X, X_______,
  ______X_, _______X, ____X_X_, _XXXX__X, X_______,
  ____XXX_, _______X, ____X__X, _XXX__X_, X_______,
  ____XXX_, ________, _____XXX, _XXX_X__, X_______,
  ____X___, __X_____, _____X__, _XXX_X__, X_______,
  ____X_X_, __X___X_, _____X__, _XXX_X__, X_______,
  ____X_X_, __X___X_, _____X__, XXXX_X__, X_______,
  ____X___, __X___X_, _____X__, XXXX_X_X, X_______,
  ____X___, __X_____, _____X__, XXXXXX_X, ________,
  ____XX_X, __X___X_, _____X__, XXXXXX_X, ________,
  ____X___, ___XXXX_, X____X__, XXXX_X_X, ________,
  ____X___, ______X_, _____X__, XXXXXXXX, ________,
  ________, ________, ________, XXXXX__X, ________,
  ____X___, ________, ________, XXXXXX_X, ________,
  ____XXXX, X_______, ______X_, XXXXXXXX, ________,
  _____XX_, _XXXXXXX, _____XXX, XXXXXXXX, ________,
  ______X_, ________, XXXXXXX_, X____XX_, ________,
  _______X, XXXX____, __XXXXX_, X____XX_, ________,
  _______X, _XXXXXXX, XXXXXXX_, X____XX_, ________,
  _______X, ____XXXX, XX__XXX_, X____XX_, ________,
  ____XXXX, ________, _X__X_X_, XX___XX_, ________,
  ____X_XX, ________, _X__X_XX, XXXXXXXX, ________,
  ___X_XXX, ________, _X_XXXXX, XXXXXXXX, X_______,
  ___X_XXX, ________, _XXX_XX_, X_XXXXXX, XX______,
  __X__XXX, _X______, _XX_XXX_, X_XXXXXX, XX______,
  __X____X, _X______, _XX_XX__, X_XXX__X, XXX_____,
  _XX____X, _XX_XXXX, XX__XX_X, XXXXX___, XXXX____,
  _X_____X, XXXXXX__, XX_____X, _XXX____, XX_X____,
  XX_____X, ________, X______X, __XX____, _X_XX___,
  XXXXX__X, __XXXXXX, X______X, __XX____, _XXXXX__,
  ____XXXX, XXX____X, X_____XX, _XXX____, ____XX__,
  ________, _______X, ______XX, XXX_____, XXXXXXX_,
  ________, ______XX, X_____X_, ___XXXXX, XXX_____,
  ________, ________, _XXXXXXX, XXXXX___, ________,
  ________, ________, _____XXX, ________, ________

};

GUI_Bitmap_t bmlogo = {
  39, /* XSize */
  64, /* YSize */
  5, /* BytesPerLine */
  1, /* BitsPerPixel */
  aclogo,  /* Pointer to picture data (indices) */
};

/* *** End of file *** */
