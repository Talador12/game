#include "Source.h"

//Game Coding Project ©2014
//Keith Adler
//Michael Carter
//Devon Finninger

//Standard Namespace
using namespace std;

//Global Variables
const float FPS = 60;
const int SCREEN_W = 640;
const int SCREEN_H = 480;
const int BOUNCER_SIZE = 32;
float bouncer_x = SCREEN_W / 2.0 - BOUNCER_SIZE / 2.0;
float bouncer_y = SCREEN_H / 2.0 - BOUNCER_SIZE / 2.0;
bool key[4] = { false, false, false, false };
bool redraw = true;
bool doExit = false;
ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_TIMER *timer = NULL;
ALLEGRO_BITMAP *bouncer = NULL;
ALLEGRO_SAMPLE *sample = NULL;

//Enums
enum MYKEYS {
	KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
};

//Functions TODO, I'm not really using the header file am I
void allegroInit();
void allegroDestroy();
void game();
void movement(ALLEGRO_EVENT ev);

//Main Function
void main(int argc, char **argv)
{
	//Allegro intialization function
	allegroInit();
	
	// Loop the sample until the display closes. TODO AUDIO
	//al_play_sample(sample, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);

	//Loop game until exit
	game();

	//Allegro Deconstructor
	allegroDestroy();
}

#pragma region Allegro
//Allegro intialization function
void allegroInit()
{
	if (!al_init())
	{
		fprintf(stderr, "failed to initialize allegro!\n");
		exit(1);
	}
	if (!al_install_keyboard())
	{
		fprintf(stderr, "failed to initialize the keyboard!\n");
		exit(1);
	}
	if (!al_install_mouse())
	{
		fprintf(stderr, "failed to initialize the mouse!\n");
		exit(1);
	}
	timer = al_create_timer(1.0 / FPS);
	if (!timer)
	{
		fprintf(stderr, "failed to create timer!\n");
		exit(1);
	}

	/* //TODO AUDIO
	if (!al_install_audio())
	{
	fprintf(stderr, "failed to initialize audio!\n");
	exit(1);
	}

	if (!al_init_acodec_addon())
	{
	fprintf(stderr, "failed to initialize audio codecs!\n");
	exit(1);
	}

	if (!al_reserve_samples(1))
	{
	fprintf(stderr, "failed to reserve samples!\n");
	exit(1);
	}

	sample = al_load_sample("Audio\george.wav");
	if (!sample)
	{
	printf("Audio clip sample not loaded!\n");
	exit(1);
	}*/

	al_set_new_display_flags(ALLEGRO_FULLSCREEN);
	display = al_create_display(SCREEN_W, SCREEN_H);
	if (!display)
	{
		fprintf(stderr, "failed to create display!\n");
		al_destroy_timer(timer);
		exit(1);
	}

	bouncer = al_create_bitmap(BOUNCER_SIZE, BOUNCER_SIZE);
	if (!bouncer)
	{
		fprintf(stderr, "failed to create bouncer bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		exit(1);
	}

	al_set_target_bitmap(bouncer);
	al_clear_to_color(al_map_rgb(255, 0, 255));
	al_set_target_bitmap(al_get_backbuffer(display));

	event_queue = al_create_event_queue();
	if (!event_queue)
	{
		fprintf(stderr, "failed to create event_queue!\n");
		al_destroy_bitmap(bouncer);
		al_destroy_display(display);
		al_destroy_timer(timer);
		exit(1);
	}

	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_mouse_event_source());

	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();
	al_start_timer(timer);

}

//Allegro Deconstructor
void  allegroDestroy()
{
	al_destroy_bitmap(bouncer);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	al_destroy_sample(sample);
}
#pragma endregion Allegro Initilization/Desconstructor

#pragma region Game
void  game()
{
	while (!doExit)
	{
		//Allegro Event Handling
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		//All Input Devices
		movement(ev);

		//Redraw Screen
		if (redraw && al_is_event_queue_empty(event_queue))
		{
			redraw = false;

			al_clear_to_color(al_map_rgb(0, 0, 0));

			al_draw_bitmap(bouncer, bouncer_x, bouncer_y, 0);

			al_flip_display();
		}
	}
}

#pragma region Game Functions
//Keyboard and Mouse controls
void  movement(ALLEGRO_EVENT ev)
{
	if (ev.type == ALLEGRO_EVENT_TIMER)
	{
		if (key[KEY_UP] && bouncer_y >= 4.0)
		{
			bouncer_y -= 4.0;
		}

		if (key[KEY_DOWN] && bouncer_y <= SCREEN_H - BOUNCER_SIZE - 4.0)
		{
			bouncer_y += 4.0;
		}

		if (key[KEY_LEFT] && bouncer_x >= 4.0)
		{
			bouncer_x -= 4.0;
		}

		if (key[KEY_RIGHT] && bouncer_x <= SCREEN_W - BOUNCER_SIZE - 4.0)
		{
			bouncer_x += 4.0;
		}

		redraw = true;
	}
	else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
	{
		doExit = true;
	}
	else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		switch (ev.keyboard.keycode)
		{
		case ALLEGRO_KEY_UP:
			key[KEY_UP] = true;
			break;

		case ALLEGRO_KEY_DOWN:
			key[KEY_DOWN] = true;
			break;

		case ALLEGRO_KEY_LEFT:
			key[KEY_LEFT] = true;
			break;

		case ALLEGRO_KEY_RIGHT:
			key[KEY_RIGHT] = true;
			break;
		}
	}
	else if (ev.type == ALLEGRO_EVENT_KEY_UP)
	{
		switch (ev.keyboard.keycode)
		{
		case ALLEGRO_KEY_UP:
			key[KEY_UP] = false;
			break;

		case ALLEGRO_KEY_DOWN:
			key[KEY_DOWN] = false;
			break;

		case ALLEGRO_KEY_LEFT:
			key[KEY_LEFT] = false;
			break;

		case ALLEGRO_KEY_RIGHT:
			key[KEY_RIGHT] = false;
			break;

		case ALLEGRO_KEY_ESCAPE:
			break;
		}
	}
	else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES ||
		ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY)
	{

		bouncer_x = ev.mouse.x - 15;
		bouncer_y = ev.mouse.y - 15;
	}
	else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
	{
		doExit = true;
	}
}
#pragma endregion Game Functions
#pragma endregion Game Loop