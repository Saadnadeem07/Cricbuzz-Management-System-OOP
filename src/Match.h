#pragma once
#include"Player.h"
#include"Team.h"
#include"Date.h"
class Match
{
public:
	Match();
	~Match();
	void conductMatch();
	void Upload_Team_Data(Team* obj1, Team* obj2, int c1, int c2);

	void updateWorldRecords();
	void updatePlayerRanking();
	void displayUpcomingMatches();
	void displayRecentMatches();

	void set_Team_01(Team* obj);
	void set_Team_02(Team* obj);
	void get_Team_01();			
	void get_Team_02();			
	void set_Match_Details();
	void get_Match_Details();
	int get_total_overs();
	void set_Date_of_match();		//DATE
	void set_Venue(string x);
	void set_Match_type();			 //ODI,T20,TEST
	void set_Tournament_Name(string x);	 //(T20 World Cup, IPL, PSL, etc.)
	void set_Match_status(string x);	 //(upcoming, recent, etc.)
	void set_num_of_Commentators(int x);
	void set_num_of_Umpires(int x);
	void set_Commentators();
	void set_Umpires();
	void get_Date_of_match();		//datatype Date
	string get_Venue();
	string get_Match_type();		// ODI,T20,TEST
	string get_Tournament_Name();	//(T20 World Cup, IPL, PSL, etc.)
	string get_Match_status();		// (upcoming, recent, etc.)
	int get_num_of_Commentators();
	int get_num_of_Umpires();
	void get_Umpires();
	void get_Commentators();
private:
	Team* Team_01;				//datatype Team
	Team* Team_02;				//datatype Team
	Date Date_of_match;			//datatype Date
	string Venue;
	string Match_type;			// ODI,T20,TEST
	string Tournament_Name;		//(T20 World Cup, IPL, PSL, etc.)
	string Match_status;		// (upcoming, recent, etc.)
	int num_of_Commentators;
	int num_of_Umpires;
	string *Commentators;
	string *Umpires;
	int total_overs;
	int** overs_balls;
};