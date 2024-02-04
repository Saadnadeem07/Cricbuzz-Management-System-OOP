#pragma once
#pragma once
#include"Player.h"
class Team :public Player_Class
{
public:
	Team();
	~Team();
	//defination of pure virtual functions having prototype in Player
	void addPlayer(int Team_number);
	void removePlayer(string s);
	void searchPlayer(string s);
	void updatePlayer(string s);
	//****** Non Virtual Functions ******
	void displayMatches();
	void updateCaptain();
	void displayTeam(int x);
	void updateCoach();

	void Upload_Team_01_info(int x);
	void Upload_Team_02_info(int x);
	string get_Admin_Username();
	string get_Admin_Password();
	void get_Team_Data();
	void get_Team_Players();
	void set_wickets(int x);
	void set_total_runs(int x);
	int get_wickets();
	int get_total_runs();
	string get_Team_Name();

	Player_Class* Players;
	void set_T20_ranking_of_Team(int x);
	void set_ODI_ranking_of_Team(int x);
	void set_Test_ranking_of_Team(int x);
	int get_T20_ranking_of_Team();
	int get_ODI_ranking_of_Team();
	int get_Test_ranking_of_Team();
protected:
	void set_Team_Name(string x);
	void set_Team_Captain(string x);
	void set_Team_Coach(string x);
	void set_Admin_Username(string x);
	void set_Admin_Password(string x);
	void set_Num_of_Players(int x);
	void set_Total_matches_won(int x);
	void set_Total_matches_lost(int x);
	string get_Team_Captain();
	string get_Team_Coach();
	int get_Num_of_Players();
	int get_Total_matches_won();
	int get_Total_matches_lost();
private:
	string Team_Name;
	string Team_Captain;
	string Team_Coach;
	string Admin_Username;
	string Admin_Password;
	int Num_of_Players;		//size of array
	int T20_ranking_of_Team;
	int ODI_ranking_of_Team;
	int Test_ranking_of_Team;
	int Total_matches_won;
	int Total_matches_lost;
	int wickets;
	int total_runs;
};