#include"Team.h"
#include"Player.h"
//Constructor
Team::Team()
{
	Team_Name = "NULL";
	Team_Captain = "NULL";
	Team_Coach = "NULL";
	Admin_Username = "Admin";
	Admin_Password = "M123";
	T20_ranking_of_Team = 0;
	ODI_ranking_of_Team = 0;
	Test_ranking_of_Team = 0;
	Total_matches_won = 0;
	Total_matches_lost = 0;
	Num_of_Players = 11;//standard match has 11 players
	//team = new Player_Class[Num_of_Players];//dynamic array of objects(11players)
	Players = new Player_Class[Num_of_Players];
}
//Destructor
Team::~Team()
{
	//delete array of players
}
//defination of pure virtual functions having prototype in Player
void Team::addPlayer(int Team_number)
{
	string s;
	double d;
	int x;
	ifstream write;
	if (Team_number == 1)
	{
		write.open("Players Team 01.txt");
		cout << "\n\t\tTEAM NUMBER 01 PLAYERS DATA UPLOADED";
	}
	else if (Team_number == 2)
	{
		write.open("Players Team 02.txt");
		cout << "\n\t\tTEAM NUMBER 02 PLAYERS DATA UPLOADED";
	}
	else if (Team_number == 3)
	{
		write.open("Players Team 03.txt");
		cout << "\n\t\tTEAM NUMBER 03 PLAYERS DATA UPLOADED";
	}
	else if (Team_number == 4)
	{
		write.open("Players Team 04.txt");
		cout << "\n\t\tTEAM NUMBER 04 PLAYERS DATA UPLOADED";
	}

	for (int i = 0; i < 11; i++)
	{
		write >> s;
		Players[i].set_Name_of_Player(s);
		write >> d;
		Players[i].set_Average(d);
		write >> x;
		Players[i].set_Shirt_Num(x);
		write >> x;
		Players[i].set_T20_ranking_of_Player(x);
		write >> x;
		Players[i].set_ODI_ranking_of_Player(x);
		write >> x;
		Players[i].set_Test_ranking_of_Player(x);
		write >> x;
		Players[i].set_Total_runs_of_Player(x);
		write >> x;
		Players[i].set_Matches_played_by_Player(x);
		write >> x;
		Players[i].set_Total_wickets(x);
	}
}
void Team::removePlayer(string s)
{
	int x = 0;

	for (int i = 0; i < 11; i++)
	{
		if (s == Players[i].get_Name_of_Player())
		{
			cout << "\n\t\t\t******* PLAYER FOUND ******* ";
			Players[i].set_Name_of_Player("PLAYER DELETED");
			Players[i].set_Average(0.0);
			Players[i].set_Shirt_Num(x);
			Players[i].set_T20_ranking_of_Player(x);
			Players[i].set_ODI_ranking_of_Player(x);
			Players[i].set_Test_ranking_of_Player(x);
			Players[i].set_Total_runs_of_Player(x);
			Players[i].set_Matches_played_by_Player(x);
			Players[i].set_Total_wickets(x);
			Players[i].get_Player();
		}
	}
}
void Team::searchPlayer(string s)
{
	for (int i = 0; i < 11; i++)
	{
		if (s == Players[i].get_Name_of_Player())
		{
			cout << "\n\t\t\t******* PLAYER FOUND ******* \n";
			Players[i].get_Player();
			cout << endl;
			//cout matched player data
		}
	}
}
void Team::updatePlayer(string s)
{
	for (int i = 0; i < 11; i++)
	{
		if (s == Players[i].get_Name_of_Player())
		{
			cout << "\n\t\t\t******* PLAYER FOUND ******* ";
			cout << "\n\tOLD DETAILS OF THIS USER ARE ";
			Players[i].get_Player();
			cout << "\n\n\tENTER NEW DETAILS OF THIS USER \n";
			Players[i].set_Player();
		}
	}
}
//********** Non Virtual Functions Definations **************
void Team::displayMatches()
{
}
void Team::updateCaptain()
{
	string s;
	cout << "\n\tEnter Name of New Captain : ";
	getline(cin, s);
	set_Team_Captain(s);
}
void Team::displayTeam(int x)
{
	if (x == 1)
	{
		cout << "\n\t\t\t************************* TEAM - 01 DETAILS ARE AS FOLLOW *************************\n";
	}
	else if (x == 2)
	{
		cout << "\n\t\t\t************************* TEAM - 02 DETAILS ARE AS FOLLOW *************************\n";
	}
	cout << "\n\t\t\tTeam Name = " << get_Team_Name();
	cout << "\n\t\t\tTeam Coach = " << get_Team_Coach();
	cout << "\n\t\t\tTeam Captain = " << get_Team_Captain();
	cout << "\n\t\t\tTeam T20 ranking = " << get_T20_ranking_of_Team();
	cout << "\n\t\t\tTeam ODI ranking = " << get_ODI_ranking_of_Team();
	cout << "\n\t\t\tTeam Test ranking = " << get_Test_ranking_of_Team();
	cout << "\n\t\t\tTotal Player in Team = " << get_Num_of_Players();
	cout << "\n\t\t\tTotal Matches won by Team = " << get_Total_matches_won();
	cout << "\n\t\t\tTotal Matches loss by Team = " << get_Total_matches_lost();
	cout << "\n\n\t\t\t**************************** TEAM PLAYERS ARE **************************** \n";
	for (int i = 0; i < 11; i++)
	{
		cout << "\t\t\t" << i + 1 << "- " << Players[i].get_Name_of_Player();
		if (i % 2 == 0)
		{
			cout << endl;
		}
	}
	if (Players[0].get_Name_of_Player() == "NULL")
	{
		cout << "\n\n\t--->Kindly UPLOAD DATA OF PLAYERS IN THIS TEAM.\n\tTHANKS!";
	}
	cout << endl;
}
void Team::updateCoach()
{
	string s;
	cout << "\n\tEnter Name of New Coach : ";
	getline(cin, s);
	set_Team_Coach(s);
}
//********** Normal Functions Definations **************
void Team::Upload_Team_01_info(int x)
{
	ifstream write;
	if (x == 1)
	{
		write.open("Pakistan.txt");

	}
	else if (x == 2)
	{
		write.open("India.txt");

	}
	else if (x == 3)
	{
		write.open("England.txt");

	}
	else if (x == 4)
	{
		write.open("Newzeland.txt");

	}
	string s;
	write >> s;
	set_Team_Name(s);
	write >> s;
	set_Team_Captain(s);
	write >> s;
	set_Team_Coach(s);
	write >> x;
	set_T20_ranking_of_Team(x);
	write >> x;
	set_ODI_ranking_of_Team(x);
	write >> x;
	set_Test_ranking_of_Team(x);
	write >> x;
	set_Num_of_Players(x);
	write >> x;
	set_Total_matches_won(x);
	write >> x;
	set_Total_matches_lost(x);
}
void Team::Upload_Team_02_info(int x)
{
	ifstream write;
	if (x == 1)
	{
		write.open("Pakistan.txt");

	}
	else if (x == 2)
	{
		write.open("India.txt");

	}
	else if (x == 3)
	{
		write.open("England.txt");

	}
	else if (x == 4)
	{
		write.open("Newzeland.txt");

	}
	string s;
	write >> s;
	set_Team_Name(s);
	write >> s;
	set_Team_Captain(s);
	write >> s;
	set_Team_Coach(s);
	write >> x;
	set_T20_ranking_of_Team(x);
	write >> x;
	set_ODI_ranking_of_Team(x);
	write >> x;
	set_Test_ranking_of_Team(x);
	write >> x;
	set_Num_of_Players(x);
	write >> x;
	set_Total_matches_won(x);
	write >> x;
	set_Total_matches_lost(x);
}
void Team::set_Team_Name(string x)
{
	Team_Name = x;
}
void Team::set_Team_Captain(string x)
{
	Team_Captain = x;
}
void Team::set_Team_Coach(string x)
{
	Team_Coach = x;
}
void Team::set_Admin_Username(string x)
{
	Admin_Username = x;
}
void Team::set_Admin_Password(string x)
{
	Admin_Password = x;
}
void Team::set_T20_ranking_of_Team(int x)
{
	T20_ranking_of_Team = x;
}
void Team::set_ODI_ranking_of_Team(int x)
{
	ODI_ranking_of_Team = x;
}
void Team::set_Test_ranking_of_Team(int x)
{
	Test_ranking_of_Team = x;
}
void Team::set_Num_of_Players(int x)
{
	Num_of_Players = x;
}
void Team::set_Total_matches_won(int x)
{
	Total_matches_won = x;
}
void Team::set_Total_matches_lost(int x)
{
	Total_matches_lost = x;
}
void Team::get_Team_Players()
{
	for (int i = 0; i < 11; i++)
	{
		cout << "\n\n\t ******PLAYER NUMBER " << i + 1 << " DATA *********\n";
		cout << "\n\tPlayer Name = " << Players[i].get_Name_of_Player();
		cout << "\n\tPlayer Average = " << Players[i].get_Average_of_Player();
		cout << "\n\tPlayer Total Runs =  " << Players[i].get_Total_runs_of_Player();
		cout << "\n\tPlayer T20 Ranking =  " << Players[i].get_T20_ranking_of_Player();
		cout << "\n\tPlayer ODI Ranking =  " << Players[i].get_ODI_ranking_of_Player();
		cout << "\n\tPlayer Shirt Number =  " << Players[i].get_Shirt_Num();
		cout << "\n\tPlayer Test Ranking =  " << Players[i].get_Test_ranking_of_Player();
		cout << "\n\tPlayer Total Matches =  " << Players[i].get_Matches_played_by_Player();
		cout << "\n\tPlayer Total Wickets =  " << Players[i].get_Total_wickets();
	}
	cout << endl;
}
void Team::set_wickets(int x)
{
	wickets = x;
}
void Team::set_total_runs(int x)
{
	total_runs = x;
}
int Team::get_wickets()
{
	return wickets;
}
int Team::get_total_runs()
{
	return total_runs;
}
string Team::get_Team_Name()
{
	return Team_Name;
}
string Team::get_Team_Captain()
{
	return Team_Captain;
}
string Team::get_Team_Coach()
{
	return Team_Coach;
}
string Team::get_Admin_Username()
{
	return Admin_Username;
}
string Team::get_Admin_Password()
{
	return Admin_Password;
}
int Team::get_T20_ranking_of_Team()
{
	return T20_ranking_of_Team;
}
int Team::get_ODI_ranking_of_Team()
{
	return ODI_ranking_of_Team;
}
int Team::get_Test_ranking_of_Team()
{
	return Test_ranking_of_Team;
}
int Team::get_Total_matches_won()
{
	return Total_matches_won;
}
int Team::get_Total_matches_lost()
{
	return Total_matches_lost;
}
void Team::get_Team_Data()
{
	cout << "\n\t Team Name= " << get_Team_Name();
	cout << "\n\t Team Captain Name = " << get_Team_Captain();
	cout << "\n\t Team Coach = " << get_Team_Coach();
	cout << "\n\t Team = " << get_Admin_Username();
	cout << "\n\t Team = " << get_Admin_Password();
	cout << "\n\t Team T20_ranking = " << get_T20_ranking_of_Team();
	cout << "\n\t Team ODI_ranking = " << get_ODI_ranking_of_Team();
	cout << "\n\t Team Test_ranking = " << get_Test_ranking_of_Team();
	cout << "\n\t Team Players = " << get_Num_of_Players();
	cout << "\n\t Team Matches Won = " << get_Total_matches_won();
	cout << "\n\t Team Matches Lost = " << get_Total_matches_lost();
}
int Team::get_Num_of_Players()
{
	return Num_of_Players;
}