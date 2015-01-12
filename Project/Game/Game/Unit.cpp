#include <string>
using namespace std;

class Unit{
	public:
		//Public Variables
		string name, desc;
		int HP, movement, atk, def, mgAtk, mgDef;
		bool moving;

		struct location{
			int X = 0;
			int Y = 0;
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
	private:
		//Private information functions
};