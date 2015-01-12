#include <string>
#include <allegro5/allegro.h>
using namespace std;

class Unit{
public:
	//Public Variables
	string name, desc;
	int HP, movement, atk, def, mgAtk, mgDef = 1;
	bool moving;

	struct location{
		float X = 0;
		float Y = 0;
	};
	//Location of the unit
	location loc;
	//Destination of the unit
	location dest;

	//Public constructor
	Unit()
	{
		name = "Unit Name";
		desc = "Unit Desc";
		HP = 10;
		movement = 1;
		atk = 1;
		def = 1;
		mgAtk = 1;
		mgDef = 1;
		moving = false;
	}

	//Arrival check
	bool arrived()
	{
		if (loc.X == dest.X && loc.Y == dest.Y)
		{
			moving = false;
			return true;
		}
		return false;
	}
	void move(ALLEGRO_EVENT ev, int display_width, int display_height)
	{
		moving = true;
		dest.X = (ev.mouse.x < 15) ? 0 : ev.mouse.x - 15;
		dest.X = ((ev.mouse.x + 15) > display_width) ? (display_width - 30) : dest.X;
		dest.Y = (ev.mouse.y < 15) ? 0 : ev.mouse.y - 15;
		dest.Y = ((ev.mouse.y + 15) > display_height) ? (display_height - 30) : dest.Y;
		loc.X = dest.X;
		loc.Y = dest.Y;
		/*
		moving = true;
		dest.X = (ev.mouse.x < 15) ? 0 : ev.mouse.x - 15;
		dest.X = ((ev.mouse.x + 15) > display_width) ? (display_width - 30) : dest.X;
		dest.Y = (ev.mouse.y < 15) ? 0 : ev.mouse.y - 15;
		dest.Y = ((ev.mouse.y + 15) > display_height) ? (display_height - 30) : dest.Y;
		loc.X = dest.X;
		loc.Y = dest.Y;
		int distanceX = (sgn(dest.X - loc.X) * (abs(dest.X) - abs(loc.X)));
		int distanceY = (sgn(dest.Y - loc.Y) * (abs(dest.Y) - abs(loc.Y)));
		if (distanceX != 0)
		{
		//loc.X += (1 * movement) / distanceX;
		}
		else
		{
		//loc.X = dest.X;
		}
		if (distanceY != 0)
		{
		//loc.Y += (1 * movement) / distanceY;
		}
		else
		{
		//loc.Y = dest.Y;
		}
		loc.X = dest.X;
		loc.Y = dest.Y;*/
	}
private:
	//Private information functions
	//Sign num function
	template <typename T> int sgn(T val)
	{
		return (T(0) < val) - (val < T(0));
	}
};