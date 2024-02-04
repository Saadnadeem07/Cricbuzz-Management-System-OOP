#include"Match.h"
#include"Team.h"
//Constructor
Match::Match()
{
	Team_01 = nullptr;
	Team_02 = nullptr;
	Venue = "NULL";
	Match_type = "NULL";			// ODI,T20,TEST
	Tournament_Name = "NULL";		//(T20 World Cup, IPL, PSL, etc.)
	Match_status = "NULL";		// (upcoming, recent, etc.)
	num_of_Commentators = 0;
	num_of_Umpires = 0;
	Date_of_match = { 0,0,0 };
	Commentators = nullptr;
	Umpires = nullptr;
	overs_balls = new int* [20];
	for (int i = 0; i < 20; i++)
	{
		overs_balls[i] = new int[6];	//6 balls in 20 overs
	}
}
Match::~Match()
{
	//cout << "\n\t Destructor of Player Called.";
}
void Match::conductMatch()
{
	int num = 0, input = 0, tempcount = 0, s = 0, w = 0, t1 = 0, t2 = 0;
	bool second_team_innings = 0;
	bool first_team_innings = 0;
	get_Match_Details();
	Team_01->displayTeam(1);
	Team_02->displayTeam(2);
	cout << "\n\t ********************************* MATCH INNINGS ARE *********************************";
	cout << "\n\t\t\tCHOSE BATTING BOWLING : ";
	cout << "\n\n\t\t\t--->TEAM-01 is " << Team_01->get_Team_Name();
	cout << "\n\n\t\t\t--->TEAM-02 is " << Team_02->get_Team_Name();
	cout << "\n\tENTER NUMBER OF BATTING TEAM : ";
	do
	{
		cin >> input;
		check_int_Input(input);
		if (input < 0 || input >2)
		{
			cout << "\n\n\tEnter correct choice : ";
		}
	} while (input < 0 || input >2);
	if (input == 1)
	{
		t1 = 1;
		t2 = 0;
	}
	else if (input == 2)
	{
		t2 = 1;
		t1 = 0;
	}
	do
	{
		if ((t1 == 1 && t2 == 0) && (first_team_innings == 0))
		{
			for (int i = 0; i < get_total_overs(); i++)
			{
				for (int j = 0; j < 6; j++)
				{
					overs_balls[i][j] = 0;
				}
			}
			cout << "\n\tTeam-01 Batting";
			cout << "\n\tTeam-02 Bowling";
			//srand(time(0));
			cout << endl;
			for (int i = 0; i < get_total_overs(); i++)
			{
				if (Team_02->get_Total_wickets() < 10)
				{
					for (int j = 0; j < 6; j++)
					{
						s = (rand() % 6) + 1;
						overs_balls[i][j] = s;
						int runs = Team_01->get_total_runs() + overs_balls[i][j];
						Team_01->Players[Team_02->get_Total_wickets()].set_Total_runs_of_Player(runs);
					//	Team_01->Players.set_Total_runs_of_Player(runs)];
						Team_01->set_total_runs(runs);
					}
					w = (rand() % 1) + 1;
					int temp2 = Team_02->get_Total_wickets() + w;
					Team_02->set_Total_wickets(temp2);
				}
				if (Team_02->get_Total_wickets() == 10)
				{
					for (int j = 0; j < 6; j++)
					{
						overs_balls[i][j] = 0;
					}
				}
			}
			int count = 0;
			for (int i = 0; i < get_total_overs(); i++)
			{
				for (int j = 0; j < 6; j++)
				{
					if (overs_balls[i][j] == 0)
					{
						count++;
					}
				}
				if (count > 5)
				{
					cout << "\n\tWickwts = 10 so match ended.\n";
					break;
				}
				cout << "\t" << i + 1 << " over = ";
				for (int j = 0; j < 6; j++)
				{
					cout << overs_balls[i][j] << " ";
				}
				if (i % 2 == 1)
				{
					cout << endl;
				}
			}
			cout << "\n\n\tTotal Score of Team 01 = " << Team_01->get_total_runs();
			cout << "\n\n\tTotal Wicket's = " << Team_02->get_Total_wickets();
			tempcount++;
			first_team_innings = 1;
			t1 = 0;
			t2 = 1;

		}
		else if ((t1 == 0 && t2 == 1) && (second_team_innings == 0))
		{
			for (int i = 0; i < get_total_overs(); i++)
			{
				for (int j = 0; j < 6; j++)
				{
					overs_balls[i][j] = 0;
				}
			}
			//srand(time(0));
			cout << "\n\tTeam-02 Batting";
			cout << "\n\tTeam-01 Bowling";

			//srand(time(0));
			cout << endl;
			for (int i = 0; i < get_total_overs(); i++)
			{
				if (Team_01->get_Total_wickets() < 10)
				{
					for (int j = 0; j < 6; j++)
					{
						s = (rand() % 6) + 1;
						overs_balls[i][j] = s;
						int runs = Team_02->get_total_runs() + overs_balls[i][j];
						Team_02->Players[Team_01->get_Total_wickets()].set_Total_runs_of_Player(runs);

						Team_02->set_total_runs(runs);
					}
					w = (rand() % 1) + 1;
					int temp2 = Team_01->get_Total_wickets() + w;
					Team_01->set_Total_wickets(temp2);
				}
				if (Team_01->get_Total_wickets() == 10)
				{
					for (int j = 0; j < 6; j++)
					{
						overs_balls[i][j] = 0;
					}
				}
			}
			int count = 0;
			for (int i = 0; i < get_total_overs(); i++)
			{
				for (int j = 0; j < 6; j++)
				{
					if (overs_balls[i][j] == 0)
					{
						count++;
					}
				}
				if (count > 5)
				{
					cout << "\n\tWickwts = 10 so match ended.\n";
					break;
				}
				cout << "\t" << i + 1 << " over = ";
				for (int j = 0; j < 6; j++)
				{
					cout << overs_balls[i][j] << " ";
				}
				if (i % 2 == 1)
				{
					cout << endl;
				}
			}
			cout << "\n\n\tTotal Score of Team 02 = " << Team_02->get_total_runs();
			cout << "\n\n\tTotal Wicket's = " << Team_01->get_Total_wickets();
			tempcount++;
			second_team_innings = 1;
			t2 = 0;
			t1 = 1;
		}
	} while (tempcount != 2);
	int rank,rank2;
	if (Team_01->get_total_runs() > Team_02->get_total_runs())
	{
		cout << "\n\n\t\t\t--->WINNER is " << Team_01->get_Team_Name();
		cout << "\n\n\t\t\t--->" << Team_01->get_Team_Name() << "\tRanking Uploaded.";
		//update team ranking
		if (get_total_overs() == 20)
		{
			rank = Team_01->get_T20_ranking_of_Team();
			rank2 = Team_02->get_T20_ranking_of_Team();
			Team_01->set_T20_ranking_of_Team(rank + 1);
			Team_02->set_T20_ranking_of_Team(rank2 - 1);

		}
		else if (get_total_overs() == 50)
		{
			rank = Team_01->get_ODI_ranking_of_Team();
			rank2 = Team_02->get_ODI_ranking_of_Team();
			Team_01->set_ODI_ranking_of_Team(rank + 1);
			Team_02->set_ODI_ranking_of_Team(rank2 - 1);
		}
		else if (get_total_overs() > 100)
		{
			rank = Team_01->get_Test_ranking_of_Team();
			rank2 = Team_02->get_Test_ranking_of_Team();
			Team_01->set_Test_ranking_of_Team(rank + 1);
			Team_02->set_Test_ranking_of_Team(rank2 - 1);
		}
		
	}
	else if (Team_02->get_total_runs() > Team_01->get_total_runs())
	{
		cout << "\n\n\t\t\t--->WINNER is " << Team_02->get_Team_Name();
		cout << "\n\n\t\t\t--->" << Team_02->get_Team_Name() << "\tRanking Uploaded.";
		if (get_total_overs() == 20)
		{
			rank = Team_02->get_T20_ranking_of_Team();
			rank2 = Team_01->get_T20_ranking_of_Team();
			Team_02->set_T20_ranking_of_Team(rank + 1);
			Team_01->set_T20_ranking_of_Team(rank2 - 1);
		}
		else if (get_total_overs() == 50)
		{
			rank = Team_02->get_ODI_ranking_of_Team();
			rank2 = Team_01->get_ODI_ranking_of_Team();
			Team_02->set_ODI_ranking_of_Team(rank + 1);
			Team_01->set_ODI_ranking_of_Team(rank2 - 1);
		}
		else if (get_total_overs() > 100)
		{
			rank = Team_02->get_Test_ranking_of_Team();
			rank2 = Team_01->get_Test_ranking_of_Team();
			Team_02->set_Test_ranking_of_Team(rank + 1);
			Team_01->set_Test_ranking_of_Team(rank2 - 1);
		}
	}
	else if (Team_02->get_total_runs() == Team_01->get_total_runs())
	{
		cout << "\n\n\t\t\t--->MATCH TIE";
	}
}
void Match::Upload_Team_Data(Team* obj1, Team* obj2, int c1, int c2)
{
	ifstream write;
	{
		if (c1 == 1)
		{
			obj1->Upload_Team_01_info(c1);
			cout << "\n\t\tTEAM 01 - PAKISTAN DATA UPLOADED";
		}
		else if (c1 == 2)
		{
			obj1->Upload_Team_01_info(c1);
			cout << "\n\t\tTEAM 01 - INDIA DATA UPLOADED";
		}
		else if (c1 == 3)
		{
			obj1->Upload_Team_01_info(c1);
			cout << "\n\t\tTEAM 01 - ENGLAND DATA UPLOADED";
		}
		else if (c1 == 4)
		{
			obj1->Upload_Team_01_info(c1);
			cout << "\n\t\tTEAM 01 - NEWZEALAND DATA UPLOADED";
		}
	}
	{
		if (c2 == 1)
		{
			obj2->Upload_Team_02_info(c2);
			cout << "\n\t\tTEAM 02 - PAKISTAN DATA UPLOADED";
		}
		else if (c2 == 2)
		{
			obj2->Upload_Team_02_info(c2);
			cout << "\n\t\tTEAM 02 - INDIA DATA UPLOADED";
		}
		else if (c2 == 3)
		{
			obj2->Upload_Team_02_info(c2);
			cout << "\n\t\tTEAM 02 - ENGLAND DATA UPLOADED";
		}
		else if (c2 == 4)
		{
			obj2->Upload_Team_02_info(c2);
			cout << "\n\t\tTEAM 02 - NEWZEALAND DATA UPLOADED";
		}
	}
}
void Match::set_Team_01(Team* obj)
{
	Team_01 = obj;
}
void Match::set_Team_02(Team* obj)
{
	Team_02 = obj;
}
void Match::set_Date_of_match()
{
	int x;
	cout << "\n\tEnter Date : ";
	do
	{
		cin >> x;
		check_int_Input(x);
		if (x <= 0 || x > 31)
		{
			cout << "\n\tEnter correct Date 1-31 : ";
		}
	} while (x <= 0 || x > 31);
	Date_of_match.set_date(x);
	cout << "\tEnter Month: ";
	do
	{
		cin >> x;
		if (x <= 0 || x > 12)
		{
			cout << "\n\tEnter correct MONTH 1-12 : ";
		}
	} while (x <= 0 || x > 12);
	Date_of_match.set_month(x);
	cout << "\tEnter Year  : ";
	do
	{
		cin >> x;
		if (x < 2022 || x > 2024)
		{
			cout << "\n\tEnter correct YEAR 2022 to 2024 : ";
		}
	} while (x < 2022 || x > 2024);
	Date_of_match.set_year(x);
}
void Match::set_Venue(string x)
{
	Venue = x;
}
void Match::set_Match_type()
{
	int x;
	cout << "\n\t01- T20";
	cout << "\n\t02- ODI";
	cout << "\n\t03- TEST ";
	cout << "\n\tEnter Choice : ";
	do
	{
		cin >> x;
		check_int_Input(x);
		if (x < 0 || x>3)
		{
			cout << "\n\tEnter correct choice : ";
		}
	} while (x < 0 || x>3);

	if (x == 1)
	{
		Match_type = "T20";
		total_overs = 20;
		overs_balls = new int* [total_overs];
		for (int i = 0; i < total_overs; i++)
		{
			overs_balls[i] = new int[6];	//6 balls in 20 overs
		}
	}
	else if (x == 2)
	{
		Match_type = "ODI";
		total_overs = 50;
		overs_balls = new int* [total_overs];
		for (int i = 0; i < total_overs; i++)
		{
			overs_balls[i] = new int[6];	//6 balls in 20 overs
		}
	}
	else if (x == 3)
	{
		Match_type = "TEST";
		total_overs = 400;
		overs_balls = new int* [total_overs];
		for (int i = 0; i < total_overs; i++)
		{
			overs_balls[i] = new int[6];	//6 balls in 20 overs
		}
	}
}
void Match::set_Tournament_Name(string x)
{
	Tournament_Name = x;
}
void Match::set_Match_status(string x)
{
	Match_status = x;
}
void Match::set_num_of_Commentators(int x)
{
	num_of_Commentators = x;
}
void Match::set_num_of_Umpires(int x)
{
	num_of_Umpires = x;
}
void Match::set_Commentators()
{
	string s;
	Commentators = new string[get_num_of_Commentators()];
	for (int i = 0; i < get_num_of_Commentators(); i++)
	{
		cout << "\n\t Enter Name of " << i + 1 << " Commentator : ";
		getline(cin, s);
		check_string_Input(s);
		Commentators[i] = s;
	}
}
void Match::set_Umpires()
{
	string s;
	Umpires = new string[get_num_of_Umpires()];
	for (int i = 0; i < get_num_of_Umpires(); i++)
	{
		cout << "\n\t Enter Name of " << i + 1 << " Umpires : ";
		getline(cin, s);
		check_string_Input(s);
		Umpires[i] = s;
	}
}
void Match::set_Match_Details()
{
	string s;
	int x;
	cin.ignore();
	cout << "\n\t ENTER MATCH DETAILS";
	cout << "\n\tEnter Match Venue : ";
	getline(cin, s);
	check_string_Input(s);
	set_Venue(s);
	check_string_Input(s);
	set_Date_of_match();
	cin.ignore();
	cout << "\n\tEnter Match Type (ODI,T20,TEST) : ";
	set_Match_type();			 //ODI,T20,TEST
	cin.ignore();
	cout << "\n\tEnter Tournament Name : ";
	getline(cin, s);
	check_string_Input(s);
	set_Tournament_Name(s);	 //(T20 World Cup, IPL, PSL, etc.)
	cout << "\n\tEnter Numbers of Commentators : ";
	cin >> x;
	check_int_Input(x);
	set_num_of_Commentators(x);
	cout << "\n\tEnter Numbers of Umpires : ";
	cin >> x;
	check_int_Input(x);
	set_num_of_Umpires(x);
	cin.ignore();
	set_Commentators();
	set_Umpires();
}
void Match::get_Team_01()
{
	Team_01->displayTeam(1);
}
void Match::get_Team_02()
{
	Team_02->displayTeam(2);
}
string Match::get_Venue()
{
	return Venue;
}
string Match::get_Match_type()
{
	return Match_type;
}
string Match::get_Tournament_Name()
{
	return Tournament_Name;
}
string Match::get_Match_status()
{
	return Match_status;
}
int Match::get_num_of_Commentators()
{
	return num_of_Commentators;
}
int Match::get_num_of_Umpires()
{
	return num_of_Umpires;
}
void Match::get_Umpires()
{
	for (int i = 0; i < get_num_of_Umpires(); i++)
	{
		cout << "\n\tName of " << i + 1 << " Umpire = " << Umpires[i];
	}
}
void Match::get_Commentators()
{
	for (int i = 0; i < get_num_of_Umpires(); i++)
	{
		cout << "\n\tName of " << i + 1 << " Commentator = " << Commentators[i];
	}
}
void Match::get_Match_Details()
{
	cout << "\n\t\tMatch Venue = " << get_Venue();
	get_Date_of_match();		//datatype Date
	cout << "\n\t\tMatch Type= " << get_Match_type();		// ODI,T20,TEST
	cout << "\n\t\tMatch Name = " << get_Tournament_Name();	//(T20 World Cup, IPL, PSL, etc.)
	cout << "\n\t\tMatch Commentators = " << get_num_of_Commentators();
	cout << "\n\t\tMatch Umpires = " << get_num_of_Umpires();
	get_Umpires();
	get_Commentators(); cout << endl;
}
int Match::get_total_overs()
{
	return total_overs;
}
void Match::get_Date_of_match()
{
	cout << "\n\t\tMatch Date  =  " << Date_of_match.get_date() << " - " << Date_of_match.get_month() << " - " << Date_of_match.get_year();
}
