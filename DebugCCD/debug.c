#include"CPCD.h"
#include <math.h>
_CPCD_ALIAS c_canvas;
_CPCD_ELEMENT_LIST e_list;

_CPCD_ELEMENT_FIELD f_field;
_CPCD_ELEMENT e_element;


#define _P_DEGTORAD 0.01745329f

void _drawsequenze(_CPCD_ALIAS * c_render, _CPCD_ALIASVECTOR v_middle, int i_count, int i_length);
void _draw(_CPCD_ALIAS * c_render, _CPCD_ALIASVECTOR v_middle, int i_count);
_CPCD_MAIN{
	srand(time(0));
	c_canvas = _CPCD_CREATE(_CPCD_WINDOW_WIDTH, _CPCD_WINDOW_HEIGHT);




	return 0;
}
_CPCD_ALIASCOLOR cpushader(_CPCD_ALIASCOLOR c_pixelvalue, _CPCD_ALIASVECTOR v_pixelvector)
{
	return c_pixelvalue;
}
_CPCD_UPDATE{



	if (ui_frame == 0) {
	
		e_element.V_ELEMENT = &f_field;
		e_element.USI_ELEMENT = _CPCD_EI_FIELD;

		printf("_->%p\n_#>%p\n", &f_field, e_element.V_ELEMENT);

		printf("MAIN\n");

		_CPCD_PUSHELEMENT(&e_list, e_element);

	}

	//system("cls");

	int t_time = clock();

	_CPCD_CLEAR(&c_canvas);

	printf("F>%p\nM>%p\nA>%p\n",&f_field, e_element.V_ELEMENT, e_list.E_ELEMENTS[0].V_ELEMENT);


	_CPCD_ALIASVECTOR v_cpos = _CPCD_CURSORPOS();
	printf("%d %d\n", v_cpos.X, v_cpos.Y);


	_draw(&c_canvas, _CPCD_CENTER, 13);



	_CPCD_DRAWBUFFER(&c_canvas);



	printf("%d ms @ ", clock() - t_time);
	printf("%d fps\n", 1000 / (clock() - t_time));


	return 0;
}
_CPCD_END{
	free(e_list.E_ELEMENTS);
	_CPCD_DELETE(&c_canvas);
}
_CPCD_EVENTS{

	return &e_list;
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