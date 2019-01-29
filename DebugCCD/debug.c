#include"CPCD.h"

_CPCD_ALIAS c_canvas;

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

	int t_time = clock();

	_CPCD_CLEAR(&c_canvas);

	_CPCD_DRAWRECT(&c_canvas, _CPCD_LEFTUP, _CPCD_CENTER, (_CPCD_ALIASCOLOR) {255,0,0}, _CPCD_DM_FILLED);
	_CPCD_DRAWRECT(&c_canvas, _CPCD_CENTER, _CPCD_RIGHTUP, (_CPCD_ALIASCOLOR) {0,255,0}, _CPCD_DM_FILLED);
	_CPCD_DRAWRECT(&c_canvas, _CPCD_LEFTDOWN, _CPCD_CENTER, (_CPCD_ALIASCOLOR) {255,255,0}, _CPCD_DM_FILLED);
	_CPCD_DRAWRECT(&c_canvas, _CPCD_CENTER, _CPCD_RIGHTDOWN, (_CPCD_ALIASCOLOR) { 255, 0, 255 }, _CPCD_DM_FILLED);


	_CPCD_DRAWLINE(&c_canvas, _CPCD_LEFTUP, _CPCD_CENTER, (_CPCD_ALIASCOLOR) { 0, 255, 0 });
	_CPCD_DRAWLINE(&c_canvas, _CPCD_CENTER, _CPCD_RIGHTUP, (_CPCD_ALIASCOLOR) { 0, 0, 255 });
	_CPCD_DRAWLINE(&c_canvas, _CPCD_LEFTDOWN, _CPCD_CENTER, (_CPCD_ALIASCOLOR) { 255, 0, 255 });
	_CPCD_DRAWLINE(&c_canvas, _CPCD_CENTER, _CPCD_RIGHTDOWN, (_CPCD_ALIASCOLOR) { 255, 255, 0 });


	_CPCD_DRAWSTRING(&c_canvas, "Mein ALLAsad sadsadsadasdAsd", 42, _CPCD_CENTER, 2, (_CPCD_ALIASCOLOR) { 255, 255, 255 });


	_CPCD_DRAWBUFFER(&c_canvas);



	printf("%d ms @ ", clock() - t_time);
	printf("%d fps\n", 1000 / (clock() - t_time));

	return 0;
}
_CPCD_END{
	_CPCD_DELETE(&c_canvas);
}
