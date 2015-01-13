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
		float distance = getDistance(loc.X, loc.Y, dest.X, dest.Y);

		if (distance != 0)
		{
			if (loc.X != dest.X)
			{
				loc.X = (loc.X - ((loc.X - dest.X) / distance) * movement);
			}

			if (loc.Y != dest.Y)
			{
				loc.Y = (loc.Y - ((loc.X - dest.Y) / distance) * movement);
			}
		}
		else
		{
			arrived();
		}
	}
private:
	//Private information functions
	//Sign num function
	template <typename T> int sgn(T val)
	{
		return (T(0) < val) - (val < T(0));
	}
	double getDistance(double dX0, double dY0, double dX1, double dY1)
	{
		return sqrt((dX1 - dX0)*(dX1 - dX0) + (dY1 - dY0)*(dY1 - dY0));
	}
};