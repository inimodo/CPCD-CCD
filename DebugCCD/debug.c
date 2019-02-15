#include"CPCD.h"
#include <math.h>
_CPCD_ALIAS c_canvas;
_CPCD_SPRITE spr_canvas;
_CPCD_ELEMENT_LIST e_list;

_CPCD_ELEMENT_FIELD f_field;
_CPCD_ELEMENT e_element;

_CPCD_ALIASCOLOR c_testcolor = {0,255,0};

#define _P_DEGTORAD 0.01745329f

void _drawsequenze(_CPCD_ALIAS * c_render, _CPCD_ALIASVECTOR v_middle, int i_count, int i_length);
void _draw(_CPCD_ALIAS * c_render, _CPCD_ALIASVECTOR v_middle, int i_count);


void _testclick(_CPCD_EVENT e_event);
void _testhover(_CPCD_EVENT e_event);
void _testedit_idle(_CPCD_SPRITE * s_sprite);
void _testedit_hover(_CPCD_SPRITE * s_sprite);
void _testedit_clicked(_CPCD_SPRITE * s_sprite);
void _trigger();

_CPCD_ELEMENTSTYLE es_styletest = {
	{ { 255,255,255 },{ 66, 134, 244 },{ 255,255,255 } },
	{33,33,33}
};

_CPCD_MAIN{
	srand(time(0));
	c_canvas = _CPCD_CREATE(_CPCD_WINDOW_WIDTH, _CPCD_WINDOW_HEIGHT);
	spr_canvas = _CPCD_SPR_CREATE(_CPCD_WINDOW_WIDTH, _CPCD_WINDOW_HEIGHT,0);




	f_field.F_EVENT_CLICKED= _testclick;
	f_field.F_EVENT_HOVER = _testhover;


	f_field.F_EVENT_STYLE_CLICKED = _testedit_clicked ;
	f_field.F_EVENT_STYLE_HOVER = _testedit_hover;
	f_field.F_EVENT_STYLE_IDLE = _testedit_idle;

	e_element.USI_HEIGHT = 50;
	e_element.USI_WIDTH = 100;
	e_element.V_ELEMENT = &f_field;
	e_element.USI_ELEMENT = _CPCD_EI_FIELD;
	e_element.V_POSITION = _CPCD_CENTER;

	e_element.S_DISPLAY = _CPCD_SPR_CREATE(e_element.USI_WIDTH, e_element.USI_HEIGHT, 0);

	e_list.F_TRIGGER = _trigger;

	_CPCD_PUSHELEMENT(&e_list, e_element);

	_CPCD_CLEAR(&(e_element.S_DISPLAY), (_CPCD_ALIASCOLOR) { 0, 0, 0 });
	
	

	return 0;
}
_CPCD_ALIASCOLOR cpushader(_CPCD_ALIASCOLOR c_pixelvalue, _CPCD_ALIASVECTOR v_pixelvector)
{
	return c_pixelvalue;
}
_CPCD_UPDATE{
	_CPCD_ALIASVECTOR v_cpos = _CPCD_CURSORPOS();
	printf("%d %d\n", v_cpos.X, v_cpos.Y);

	int t_time = clock();

	e_element.V_POSITION = v_cpos;


	for (int i = 0; i < e_list.USI_ELEMENTS; i++)
	{
		_CPCD_ELEMENTRENDER(&c_canvas, es_styletest, e_list.E_ELEMENTS[i]);
		
	}

	_CPCD_DRAWBUFFER(&c_canvas);
	_CPCD_CLEAR(&c_canvas, (_CPCD_ALIASCOLOR) { 0, 0, 0 });


	printf("%d ms @ ", clock() - t_time);
	printf("%d fps\n\n", 1000 / (clock() - t_time));
	return 0;
}
_CPCD_END{
	free(e_list.E_ELEMENTS);
	_CPCD_DELETE(&c_canvas);
}
_CPCD_EVENTS{

	return &e_list;
}

void _testclick(_CPCD_EVENT e_event) {
	printf("\nCLICK\n");
}
void _testhover(_CPCD_EVENT e_event) {
	printf("\nHOVER\n");
}
void _trigger() {
	printf("RENDER\n");
	for (int i = 0; i < e_list.USI_ELEMENTS; i++)
	{
		_CPCD_ELEMENTRENDER(&c_canvas, es_styletest, e_list.E_ELEMENTS[i]);

	}
	_CPCD_DRAWBUFFER(&c_canvas);
}





void _testedit_idle(_CPCD_SPRITE * s_sprite) {
	_CPCD_CLEAR(s_sprite, (_CPCD_ALIASCOLOR) { 30, 30, 30 });

}
void _testedit_hover(_CPCD_SPRITE * s_sprite) {
	_CPCD_CLEAR(s_sprite, (_CPCD_ALIASCOLOR) { 255, 0, 0 });

}
void _testedit_clicked(_CPCD_SPRITE * s_sprite) {
	_CPCD_CLEAR(s_sprite, (_CPCD_ALIASCOLOR) { 0, 255, 0 });

}







_CPCD_ALIASVECTOR v_offsets[4] = { {0,1}, {-1,0}, {0,-1} ,{1,0} };

void _draw(_CPCD_ALIAS * c_render, _CPCD_ALIASVECTOR v_middle, int i_count) {
	_CPCD_ALIASVECTOR v_offset = {0,0};
	for (int i_index = 1; i_index < i_count; i_index++)
	{
		v_offset =_CPCD_VECADD(v_offset,
			_CPCD_VECMULTI(
				(_CPCD_ALIASVECTOR) { _getfibo(i_index-2) , _getfibo(i_index-2)}, v_offsets[i_index % 4]
			)
		);
		_drawsequenze(c_render, _CPCD_VECADD(v_offset, v_middle), i_index-1, _getfibo(i_index));
	}
}

void _drawsequenze(_CPCD_ALIAS * c_render, _CPCD_ALIASVECTOR v_middle, int i_count, int i_length) {
	_CPCD_ALIASVECTOR v_outpost,v_first,v_last;
	for (int i_index = 0; i_index <= 90; i_index++)
	{
		v_outpost.X = v_middle.X + cos(_P_DEGTORAD*(float)(i_index+ ((float)i_count*90.f)))*(float)i_length;
		v_outpost.Y = v_middle.Y + sin(_P_DEGTORAD*(float)(i_index + ((float)i_count * 90.f)))*(float)i_length;

		if (i_index == 0)v_last = v_outpost;

		_CPCD_DRAWLINE(c_render, v_last, v_outpost, (_CPCD_ALIASCOLOR) { 255, 255*(i_count%2), 255 });

		if (i_index == 0)v_first = v_outpost;
		v_last = v_outpost;

	}
	_CPCD_DRAWRECT(c_render, v_first, v_last, (_CPCD_ALIASCOLOR) { 255, 255 * (i_count % 2), 255 },_CPCD_DM_OUTLINE);
}
int _getfibo(int i_def) {
	int i_last = 1,i_beforelast = 1,i_current = 1 ;
	for (int i_index = 0; i_index < i_def; i_index++)
	{
		i_current = i_beforelast + i_last;
		i_beforelast = i_last;
		i_last = i_current;
	}
	return i_current;
}