#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include <stdlib.h>     
#include <time.h> 
using namespace std;
//Abstract Class Player
class Player_Class
{
public:
	Player_Class();
	~Player_Class();
	//pure virtual functions
	virtual void addPlayer(int Team_number){}
	virtual void removePlayer(string s){}
	virtual void searchPlayer(string s){}
	virtual void updatePlayer(string s){}
	//setter
	void set_Name_of_Player(string x);
	void set_Average(double x);
	void set_Shirt_Num(int x);
	void set_T20_ranking_of_Player(int x);
	void set_ODI_ranking_of_Player(int x);
	void set_Test_ranking_of_Player(int x);
	void set_Total_runs_of_Player(int x);
	void set_Matches_played_by_Player(int x);
	void set_Total_wickets(int x);
	void set_Player();
	//getter
	string get_Name_of_Player();
	double get_Average_of_Player();
	int get_Shirt_Num();
	int get_T20_ranking_of_Player();
	int get_ODI_ranking_of_Player();
	int get_Test_ranking_of_Player();
	int get_Total_runs_of_Player();
	int get_Matches_played_by_Player();
	int get_Total_wickets();
	void get_Player();
private:
	string Name;
	double Average;
	int Shirt_Num;
	int T20_ranking_of_Player;
	int ODI_ranking_of_Player;
	int Test_ranking_of_Player;
	int Total_runs;
	int Matches_played;
	int Total_wickets;
};
void check_int_Input(int& i);
void check_string_Input(string& s);