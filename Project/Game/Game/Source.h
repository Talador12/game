#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <string>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

class Source
{
public:
	void allegroInit();
	void allegroDestroy();
	void game();
	void movement(ALLEGRO_EVENT ev);
};