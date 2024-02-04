#include"Player.h"
//Constructor
Player_Class::Player_Class()
{
	Name = "NULL";
	Average = 0.0;
	Shirt_Num = 0;
	T20_ranking_of_Player = 0;
	ODI_ranking_of_Player = 0;
	Test_ranking_of_Player = 0;
	Total_runs = 0;
	Matches_played = 0;
	Total_wickets = 0;
}
//Destructor
Player_Class::~Player_Class()
{
	//cout << "\n\t Destructor of Player Called.";
}
void Player_Class::set_Name_of_Player(string x)
{
	Name = x;
}
void Player_Class::set_Average(double x)
{
	Average = x;
}
void Player_Class::set_Shirt_Num(int x)
{
	Shirt_Num = x;
}
void Player_Class::set_T20_ranking_of_Player(int x)
{
	T20_ranking_of_Player = x;
}
void Player_Class::set_ODI_ranking_of_Player(int x)
{
	ODI_ranking_of_Player = x;
}
void Player_Class::set_Test_ranking_of_Player(int x)
{
	Test_ranking_of_Player = x;
}
void Player_Class::set_Total_runs_of_Player(int x)
{
	Total_runs = x;
}
void Player_Class::set_Matches_played_by_Player(int x)
{
	Matches_played = x;
}
void Player_Class::set_Total_wickets(int x)
{
	Total_wickets = x;
}
string Player_Class::get_Name_of_Player()
{
	return Name;
}
double Player_Class::get_Average_of_Player()
{
	return Average;
}
int Player_Class::get_Shirt_Num()
{
	return Shirt_Num;
}
int Player_Class::get_T20_ranking_of_Player()
{
	return T20_ranking_of_Player;
}
int Player_Class::get_ODI_ranking_of_Player()
{
	return ODI_ranking_of_Player;
}
int Player_Class::get_Test_ranking_of_Player()
{
	return Test_ranking_of_Player;
}
int Player_Class::get_Total_runs_of_Player()
{
	return Total_runs;
}
int Player_Class::get_Matches_played_by_Player()
{
	return Matches_played;
}
int Player_Class::get_Total_wickets()
{
	return Total_wickets;
}
void Player_Class::get_Player()
{
	cout << "\n\tPlayer Name = " << get_Name_of_Player();
	cout << "\n\tPlayer Average = " << get_Average_of_Player();
	cout << "\n\tPlayer Total Runs =  " << get_Total_runs_of_Player();
	cout << "\n\tPlayer T20 Ranking =  " << get_T20_ranking_of_Player();
	cout << "\n\tPlayer ODI Ranking =  " << get_ODI_ranking_of_Player();
	cout << "\n\tPlayer Shirt Number =  " << get_Shirt_Num();
	cout << "\n\tPlayer Test Ranking =  " << get_Test_ranking_of_Player();
	cout << "\n\tPlayer Total Matches =  " << get_Matches_played_by_Player();
	cout << "\n\tPlayer Total Wickets =  " << get_Total_wickets();
}
void Player_Class::set_Player()
{
	string s;
	double d;
	int x;
	cout << "\n\tEnter Player Name = ";
	getline(cin, s);
	set_Name_of_Player(s);
	cout << "\n\tEnter Player Average = ";
	cin >> d;
	set_Average(d);
	cout << "\n\tEnter Player Total Runs =  ";
	cin >> x;
	set_Total_runs_of_Player(x);
	cout << "\n\tEnter Player T20 Ranking =  ";
	cin >> x;
	set_T20_ranking_of_Player(x);
	cout << "\n\tEnter Player ODI Ranking =  ";
	cin >> x;
	set_ODI_ranking_of_Player(x);
	cout << "\n\tEnter Player Shirt Number =  ";
	cin >> x;
	set_Shirt_Num(x);
	cout << "\n\tEnter Player Test Ranking =  ";
	cin >> x;
	set_Test_ranking_of_Player(x);
	cout << "\n\tEnter Player Total Matches =  ";
	cin >> x;
	set_Matches_played_by_Player(x);
	cout << "\n\tEnter Player Total Wickets =  ";
	cin >> x;
	set_Total_wickets(x);
}

void check_int_Input(int& i)
{
	while (1)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "\n\t\t\t****** Invalid Datatype Input ****** \n\n";
			cout << "\n\t-->Enter Input Again = ";
			cin >> i; //taking that int  input again
		}
		else
		{
			break;
		}
	}
}
void check_string_Input(string& s)
{
	while (1)
	{
		if (cin.fail() )
		{
			cin.clear();
			cin.ignore();
			cout << "\n\t\t\t****** Invalid Datatype Input ****** \n\n";
			cout << "\n\t-->Enter Input Again = ";
			cin >> s; //taking that string input again
		}
		else
		{
			break;
		}
	}
}
