//	     "C powered Colored Drawing"
//		  www.ucpsystems.com 2018-19
//		Windows only graphic library
//		    CPU based rendering
//				  V4.0.0


#pragma once


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

#pragma comment(lib, "User32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "Gdi32.lib")

#define _CPCD_TRUE 0x1FFF
#define _CPCD_FALSE 0x0FFF

#define _CPCD_USE_FULLRGB			_CPCD_TRUE
#define _CPCD_USE_SINGLEFRAME		_CPCD_FALSE	
#define _CPCD_USE_SHOWCONSOL		_CPCD_TRUE		
#define _CPCD_USE_DYNAMICQUALITY	_CPCD_FALSE
#define _CPCD_USE_EVENTS			_CPCD_TRUE


#define _CPCD_QUALITY		0.001F
#define _CPCD_PIXELQUALITY	3

#define _CPCD_NULL			(void*)0x0
#define _CPCD_STRING		char*
#define _CPCD_INT			short int
#define _CPCD_UINT			unsigned int

#define _CPCD_WINDOW_WINAME	"win32"
#define _CPCD_WINDOW_WIDTH	16*80
#define _CPCD_WINDOW_HEIGHT	9*80

#define _CPCD_DATA_HINTS	HINSTANCE
#define _CPCD_DATA_LPSTR	LPSTR
#define _CPCD_DATA_WPARAM	WPARAM
#define _CPCD_DATA_LPARAM	LPARAM
#define _CPCD_DATA_HWND		HWND
#define _CPCD_DATA_MSG		MSG
#define _CPCD_DATA_WNDC		WNDCLASSEX
#define _CPCD_DATA_HBRUSH	HBRUSH
#define _CPCD_DATA_HDC		HDC
#define _CPCD_DATA_COLR		COLORREF
#define _CPCD_DATA_HBITM	HBITMAP
#define _CDD_DATA_TIME		time_t


#if _CPCD_USE_DYNAMICQUALITY == _CPCD_TRUE
#define _CPCD_USEDYNAMICQUALITY
#endif

#if _CPCD_USE_SHOWCONSOL == _CPCD_TRUE
#define _CPCD_SHOWCONSOL
#endif

#if _CPCD_USE_SINGLEFRAME == _CPCD_TRUE
#define _CPCD_SINGLEFRAME
#endif

#if _CPCD_USE_FULLRGB == _CPCD_TRUE
#define _CPCD_FULLRGB
#endif

#if _CPCD_USE_EVENTS == _CPCD_TRUE
#define _CPCD_EVENTUSAGE
#endif


#define _CPCD_DM_FILLED		0x1FF
#define _CPCD_DM_OUTLINE	0x0FF

#define _CPCD_DATA_DRAWMODE CPCD_BOOL
typedef _CPCD_INT _CPCD_DATA_DRAWMODE;

#ifdef _CPCD_FULLRGB
#define _CPCD_COLOR	CPCD_COLOR	
#else
#define _CPCD_COLOR _CPCD_INT
#endif

#ifdef _CPCD_FULLRGB
typedef struct _CPCD_COLOR _CPCD_COLOR;
struct _CPCD_COLOR {
	_CPCD_INT		
		R, 
		G, 
		B;
};
#endif

#define _CPCD_MAP			CPCD_CANVAS
typedef struct _CPCD_MAP _CPCD_MAP;
struct _CPCD_MAP {
	_CPCD_COLOR**		C_COLOR;
	_CPCD_INT			USI_WIDTH;
	_CPCD_INT			USI_HEIGHT;
};


#define _CPCD_VECTOR	CPCD_VECTOR
typedef struct _CPCD_VECTOR _CPCD_VECTOR;
struct _CPCD_VECTOR {
	_CPCD_INT			X, Y;
};

#define _CPCD_LEFTUP	(_CPCD_VECTOR){0,0}
#define _CPCD_LEFTDOWN	(_CPCD_VECTOR){0,_CPCD_WINDOW_HEIGHT}
#define _CPCD_RIGHTDOWN (_CPCD_VECTOR){_CPCD_WINDOW_WIDTH,_CPCD_WINDOW_HEIGHT}
#define _CPCD_RIGHTUP	(_CPCD_VECTOR){_CPCD_WINDOW_WIDTH,0}
#define _CPCD_CENTER	(_CPCD_VECTOR){_CPCD_WINDOW_WIDTH/2,_CPCD_WINDOW_HEIGHT/2}

#define _CPCD_DM_LINE		0x22c
#define _CPCD_DM_TRI		0x33c
#define _CPCD_DM_RECT		0x44c

#define _CPCD_VECGRAPHIC	CPCD_VECTORGRAPHIC
#define _CPCD_UNIONTRANS	CPCD_TRANSFORM
#define _CPCD_UNIONLINE		CPCD_LINE

typedef struct _CPCD_VECGRAPHIC _CPCD_VECGRAPHIC;
typedef struct _CPCD_UNIONTRANS _CPCD_UNIONTRANS;
typedef struct _CPCD_UNIONLINE _CPCD_UNIONLINE;
struct _CPCD_UNIONTRANS {
	_CPCD_INT			USI_ROTATION;
	_CPCD_VECTOR		V_POSITION;
	_CPCD_VECTOR		V_SCALE;
};
struct _CPCD_UNIONLINE {
	_CPCD_VECTOR		V_POS_ONE;
	_CPCD_VECTOR		V_POS_TWO;
	_CPCD_COLOR		C_COLOR;
	_CPCD_INT			USI_MODE;
	_CPCD_INT			USI_DRAWMODE;
};
struct _CPCD_VECGRAPHIC {
	_CPCD_UNIONLINE*		L_LINES;
	_CPCD_INT			USI_SIZE;
	_CPCD_UNIONTRANS		T_TRANSFORM;
};

#define _CPCD_SPRITE		CPCD_SPRITE
typedef struct _CPCD_SPRITE _CPCD_SPRITE;
struct _CPCD_SPRITE {
	_CPCD_COLOR**		C_COLOR;
	_CPCD_INT			USI_WIDTH;
	_CPCD_INT			USI_HEIGHT;
	_CPCD_VECTOR		V_POSITION;
};

#define _CPCD_SBM_OVERRIDE	0x0CC 
#define _CPCD_SBM_COMPINE	0xCCC
#define _CPCD_SBM_BLEND		0xBCC
#define _CPCD_SBM_ADD		0xACC
#define _CPCD_C_RED			0x01C	
#define _CPCD_C_GREEN		0x02C	
#define _CPCD_C_BLUE		0x03C	
#define _CPCD_C_REDGREEN	0x12C	
#define _CPCD_C_REDBLUE		0x13C	
#define _CPCD_C_BLUEGRN		0x23C	

#define _CPCD_C_CHAR		CPCD_C_CHAR
#define _CPCD_CHARWIDTH		4
#define _CPCD_CHARHEIGTH	5
#define _CPCD_SPACING		1

typedef struct _CPCD_C_CHAR _CPCD_C_CHAR;
struct _CPCD_C_CHAR {
	_CPCD_STRING C_VALUE;
};
static _CPCD_C_CHAR C_CHARLIST[255];


#define _CPCD_CHARTRUE	'1'
#define _CPCD_CHARFALSE	'0'




#define _CPCD_EI_EMPTY 0xF00
#define _CPCD_EI_FIELD 0xF01
#define _CPCD_ELEMENT_FIELD CPCD_EI_FIELD
typedef struct _CPCD_ELEMENT_FIELD _CPCD_ELEMENT_FIELD;
struct _CPCD_ELEMENT_FIELD {

	void(*F_EVENT_STYLE_IDLE)	(_CPCD_SPRITE*);
	void(*F_EVENT_CLICKED)	(_CPCD_EVENT);
	void(*F_EVENT_STYLE_CLICKED)	(_CPCD_SPRITE*);
	void(*F_EVENT_HOVER)	(_CPCD_EVENT);
	void(*F_EVENT_STYLE_HOVER)	(_CPCD_SPRITE*);

};

#define _CPCD_EI_BUTTON 0xF02
#define _CPCD_ELEMENT_BUTTON CPCD_BUTTON
typedef struct _CPCD_ELEMENT_BUTTON _CPCD_ELEMENT_BUTTON;
struct _CPCD_ELEMENT_BUTTON {


	_CPCD_STRING		C_TEXT;
	_CPCD_INT			USI_LENGTH;

	void(*F_EVENT_CLICK)	(_CPCD_EVENT);
};

#define _CPCD_EI_INPUT 0xF03
#define _CPCD_ELEMENT_INPUT CPCD_INPUT

#define _CPCD_EI_PROGRESS 0xF04
#define _CPCD_ELEMENT_PROGRESS CPCD_PROGRESS

#define _CPCD_EI_SLIDER 0xF05
#define _CPCD_ELEMENT_SLIDER CPCD_SLIDER


#define _CPCD_ELEMENTSTYLE CPCD_ELEMENTSTYLE
typedef struct _CPCD_ELEMENTSTYLE _CPCD_ELEMENTSTYLE;
struct _CPCD_ELEMENTSTYLE {
	_CPCD_COLOR		C_DIVIDER[_CPCD_PIXELQUALITY];
	_CPCD_COLOR		C_MIDDLE;
};

#define _CPCD_EVENT CPCD_EVENT
typedef struct _CPCD_EVENT _CPCD_EVENT;
struct _CPCD_EVENT {
	_CPCD_INT			USI_ELEMENT;
	_CPCD_INT			USI_INDEX;
	_CPCD_UINT			UI_MSG;
};


#define _CPCD_ELEMENT CPCD_ELEMENT
typedef struct _CPCD_ELEMENT _CPCD_ELEMENT;
struct _CPCD_ELEMENT {
	_CPCD_INT			USI_WIDTH;
	_CPCD_INT			USI_HEIGHT;

	_CPCD_INT			USI_STATE;

	_CPCD_INT			USI_ELEMENT;
	_CPCD_VECTOR		V_POSITION;
	_CPCD_SPRITE			S_DISPLAY;

	void *		V_ELEMENT;
};
#define _CPCD_ELEMENT_LIST CPCD_ELEMENT_LIST
typedef struct _CPCD_ELEMENT_LIST _CPCD_ELEMENT_LIST;
struct _CPCD_ELEMENT_LIST {
	_CPCD_INT			USI_ELEMENTS;
	_CPCD_ELEMENT *			E_ELEMENTS;
	void(*F_TRIGGER)		();

};



#define _CPCD_MAIN_F		cdd_main
#define _CPCD_END_F			cdd_end
#define _CPCD_UPDATE_F		cdd_update
#define _CPCD_ELEMENT_F		cdd_element

#define _CPCD_UPDATE		_CPCD_INT		_CPCD_UPDATE_F	(_CPCD_INT ui_frame,_CPCD_INT ui_time)
#define _CPCD_MAIN		    _CPCD_INT		_CPCD_MAIN_F	(_CPCD_DATA_HWND hwnd_handle)
#define _CPCD_END			void				_CPCD_END_F		()
#define _CPCD_EVENTS		_CPCD_ELEMENT_LIST	*			_CPCD_ELEMENT_F ()

_CPCD_UPDATE;
_CPCD_MAIN;
_CPCD_END;
_CPCD_EVENTS;

_CPCD_MAP			_CPCD_CREATE		(_CPCD_INT			USI_WIDTH,
										_CPCD_INT			USI_HEIGHT);

_CPCD_SPRITE		_CPCD_SPR_CREATE	(_CPCD_INT			USI_WIDTH,
										_CPCD_INT			USI_HEIGHT,
										_CPCD_VECTOR*		V_POSITION);

_CPCD_VECGRAPHIC	_CPCD_VG_CREATE		(_CPCD_UNIONTRANS*		T_TRANFORM);

void				_CPCD_CLEAR			(_CPCD_MAP*			CPCD_CANVAS, 
										_CPCD_COLOR		C_COLOR);

void				_CPCD_DELETE		(_CPCD_MAP*			CPCD_CANVAS);

void				_CPCD_VG_PUSHLINE	(_CPCD_VECGRAPHIC *		VG_GRAPHIC,
										_CPCD_UNIONLINE			L_LINE);

void				_CPCD_DRAWBUFFER	(_CPCD_MAP*			CPCD_CANVAS);

void				_CPCD_VG_DRAW		(_CPCD_MAP*			CPCD_CANVAS,
										_CPCD_VECGRAPHIC		VG_GRAPHIC);

void				_CPCD_CPUSHADER		(_CPCD_MAP*			CPCD_CANVAS,
										_CPCD_COLOR(*cpu_shader)
										(_CPCD_COLOR,_CPCD_VECTOR));

void				_CPCD_DRAWSPRITE	(_CPCD_MAP*			CPCD_CANVAS,
										_CPCD_SPRITE			SPR_SPRITE,
										_CPCD_DATA_DRAWMODE		DM_MODE,
										_CPCD_DATA_DRAWMODE		DM_VALUE);

void				_CPCD_DRAWRECT		(_CPCD_MAP*			CPCD_CANVAS,
										_CPCD_VECTOR		V_LEFTUPPER,
										_CPCD_VECTOR		V_RIGHTBOT,
										_CPCD_COLOR		C_COLOR,
										_CPCD_DATA_DRAWMODE		DM_MODE);

void				_CPCD_DRAWTRI		(_CPCD_MAP*			CPCD_CANVAS,
										_CPCD_VECTOR		V_ONE,
										_CPCD_VECTOR		V_TWO,
										_CPCD_VECTOR		V_THREE,
										_CPCD_COLOR		C_COLOR,
										_CPCD_DATA_DRAWMODE		DM_MODE);

void				_CPCD_DRAWLINE		(_CPCD_MAP*			CPCD_CANVAS,
										_CPCD_VECTOR		V_LEFT,
										_CPCD_VECTOR		V_RIGH,
										_CPCD_COLOR		C_COLOR);

void				_CPCD_VG_DRAWRECT	(_CPCD_VECGRAPHIC*		VG_GRAPHIC,
										_CPCD_VECTOR		V_LEFTUPPER,
										_CPCD_VECTOR		V_RIGHTBOT,
										_CPCD_COLOR		C_COLOR,
										_CPCD_DATA_DRAWMODE		DM_MODE);

void				_CPCD_VG_DRAWTRI	(_CPCD_VECGRAPHIC*		VG_GRAPHIC,
										_CPCD_VECTOR		V_ONE,
										_CPCD_VECTOR		V_TWO,
										_CPCD_VECTOR		V_THREE,
										_CPCD_COLOR		C_COLOR,
										_CPCD_DATA_DRAWMODE		DM_MODE);

void				_CPCD_VG_DRAWLINE	(_CPCD_VECGRAPHIC*		VG_GRAPHIC,
										_CPCD_VECTOR		V_LEFT,
										_CPCD_VECTOR		V_RIGH,
										_CPCD_COLOR		C_COLOR);

void				_CPCD_SETPIXEL		(_CPCD_MAP*			CPCD_CANVAS,
										_CPCD_VECTOR		V_POINT,
										_CPCD_COLOR			C_COLOR);

void				_CPCD_DRAWSTRING	(_CPCD_MAP*			CPCD_CANVAS,
										_CPCD_STRING		C_TEXT,
										_CPCD_INT			USI_LENGTH,
										_CPCD_VECTOR		V_POINT,
										_CPCD_INT			I_SCALE,
										_CPCD_COLOR		C_COLOR);

_CPCD_COLOR	_CPCD_GETPIXEL		(_CPCD_MAP*			CPCD_CANVAS,
										_CPCD_VECTOR		V_POINT);

int					_CPCD_COLORCMP		(_CPCD_COLOR		C_ONE,
										_CPCD_COLOR		C_TWO);
_CPCD_COLOR	_CPCD_COLORSUB		(_CPCD_COLOR		C_ONE,
										_CPCD_COLOR		C_TWO);	

_CPCD_COLOR	_CPCD_COLORDIV		(_CPCD_COLOR		C_ONE,
										_CPCD_COLOR		C_TWO);

_CPCD_COLOR	_CPCD_COLORMULTI	(_CPCD_COLOR		C_ONE,
										_CPCD_COLOR		C_TWO);

_CPCD_COLOR	_CPCD_COLORADD		(_CPCD_COLOR		C_ONE,
										_CPCD_COLOR		C_TWO);

int					_CPCD_VECCMP		(_CPCD_VECTOR		V_ONE,
										_CPCD_VECTOR		V_TWO);

_CPCD_VECTOR	_CPCD_VECADD		(_CPCD_VECTOR		V_ONE,
										_CPCD_VECTOR		V_TWO);

_CPCD_VECTOR	_CPCD_VECSUB		(_CPCD_VECTOR		V_ONE,
										_CPCD_VECTOR		V_TWO);

_CPCD_VECTOR	_CPCD_VECMULTI		(_CPCD_VECTOR		V_ONE,
										_CPCD_VECTOR		V_TWO);

_CPCD_VECTOR	_CPCD_VECDIV		(_CPCD_VECTOR		V_ONE,
										_CPCD_VECTOR		V_TWO);

_CPCD_VECTOR	_CPCD_CURSORPOS		();



void				_CPCD_PROCESSEVENT	(_CPCD_ELEMENT_LIST *	EL_LIST,
										_CPCD_UINT			UI_MSG);

void				_CPCD_PUSHELEMENT	(_CPCD_ELEMENT_LIST *	EL_LIST,
										_CPCD_ELEMENT			E_ELEMENT);

_CPCD_ELEMENT		_CPCD_FILLELEMENT	(_CPCD_INT			USI_ELEMENT, 
										_CPCD_VECTOR		V_POSITION, 
										_CPCD_INT			USI_WIDTH,
										_CPCD_INT			USI_HEIGHT,
										void* V_ELEMENT);

void				_CPCD_ELEMENTRENDER	(_CPCD_MAP*			CPCD_CANVAS,
										_CPCD_ELEMENTSTYLE		ES_STYLE,
										_CPCD_ELEMENT			E_ELEMENT);

int					_CPCD_INREAGION		(_CPCD_VECTOR		V_POS, 
										_CPCD_INT			USI_WIDTH,
										_CPCD_INT			USI_HEIGHT, 
										_CPCD_VECTOR		V_ANCHOR);
