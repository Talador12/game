#include <string>
#include <allegro5/allegro.h>
#include <iostream>
using namespace std;

class Unit{
public:
	//Public Variables
	string name, desc;
	float HP, movement, atk, def, mgAtk, mgDef = 1;
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
		movement = 10;
		atk = 1;
		def = 1;
		mgAtk = 1;
		mgDef = 1;
		moving = false;
		cout << "harhar";
	}

	//Arrival check
	bool arrived()
	{
		if ((abs(dest.X) - abs(loc.X)) < 1 && (abs(dest.Y) - abs(loc.Y)) < 1)
		{
			loc.X = dest.X;
			loc.Y = dest.Y;
			moving = false;
			return true;
		}
		return false;
	}
	void move(int display_width, int display_height)
	{
		//This part is breaking "Click to move"
		int distanceX = (sgn(dest.X - loc.X) * (abs(dest.X) - abs(loc.X)));
		int distanceY = (sgn(dest.Y - loc.Y) * (abs(dest.Y) - abs(loc.Y)));
		
		if (distanceX != 0)
		{
			loc.X += (sgn(dest.X - loc.X)*5 + distanceX) / (1000 * movement);
		}
		else
		{
			loc.X = dest.X;
		}
		if (distanceY != 0)
		{
			loc.Y += (sgn(dest.Y - loc.Y)*5 + distanceY) / (1000 * movement);
		}
		else
		{
			loc.Y = dest.Y;
		}

		//If arrived at destination
		if (arrived())
		{

		}
	}
private:
	//Private information functions
	//Sign num function
	template <typename T> int sgn(T val)
	{
		return (T(0) < val) - (val < T(0));
	}
};