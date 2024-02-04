//header files
#include"Date.h"
#include"Player.h"
#include"Team.h"
#include"Match.h"
#include<string>
#include<time.h>
using namespace std;
//prototypes
void format();
void login();
void main_menu();
void display_format(int x);
void select_teams(int& c1, int& c2);
void match_menu(Match& match_obj, Team& team_01, Team& team_02, int& select_team_01, int& select_team_02);
void check_int_Input(int &i);
void check_string_Input(string &s);
//int main
int main()
{
	//01- login-->username & password -->main_menu()
	//02- main_menu()-->enter match-->upload all type of match data 
	//03- main_menu()-->conduct match
	
	login();
	cout << "\n\n\n\n\n";
	system("pause");
	return 0;
}

//function prototypes
void login()
{
	string username, password;
	Team Team_obj;
	system("cls");
	display_format(1);
	cout << "\n\n\t******ENTER USERNAME & PASSWORD TO PROCEED *******";
	do
	{
		cout << "\n\tEnter Username : ";
		getline(cin, username);
		check_string_Input(username);
		cout << "\tEnter Password: ";
		getline(cin, password);
		check_string_Input(password);
		if (username == Team_obj.get_Admin_Username() && password == Team_obj.get_Admin_Password())
		{
			cout << "\n\t\t******** LOGIN APPROVED ***************";
			system("pause");
			main_menu();	//function call
		}
		else
		{
			if (username != Team_obj.get_Admin_Username() && password == Team_obj.get_Admin_Password())
			{
				cout << "\n\tINVALID USERNAME ! TRY AGAIN";
			}
			else if (username == Team_obj.get_Admin_Username() && password != Team_obj.get_Admin_Password())
			{
				cout << "\n\tINVALID PASSWORD ! TRY AGAIN";
			}
			else if (username != Team_obj.get_Admin_Username() && password != Team_obj.get_Admin_Password())
			{
				cout << "\n\tINVALID USERNAME AND PASSWORD ! TRY AGAIN";
			}
			//cout << "\n\tInvalid Input! Enter Again\n";
		}
	} while (username != Team_obj.get_Admin_Username() || password != Team_obj.get_Admin_Password());

}
void main_menu()
{
	Match match_obj;
	Team team_01, team_02;
	int choice = 0, select_team_01 = 0, select_team_02 = 0;
	string s;
	do
	{
		cout << "\n\n\t";
		system("pause");
		system("cls");
		display_format(1);
		display_format(2);
		cout << "\n\t\t\t-->>>>>INSTRUCTIONS";
		cout << "\n\t\t\t--->>> SET MATCH --->>> SET TEAM ---->>> SET PLAYERS ";
		cout << "\n\t\t\tWhat do you want to perform : ";
		cout << "\n\t\t\t 01- ENTER MATCH DETAILS";
		cout << "\n\t\t\t 02- CONDUCT MATCH";
		cout << "\n\t\t\t 03- CLEAR SCREEN";
		cout << "\n\t\t\t 04- EXIT";
		cout << "\n\t\tChoose any option : ";
		cin >> choice;
		check_int_Input(choice);
		format();
		if (choice == 1)//ENTER MATCH DETAILS
		{
			cout << "\n\n\t";
			system("pause");
			match_menu(match_obj, team_01, team_02, select_team_01, select_team_02);
		}
		else if (choice == 2)//CONDUCT MATCH
		{
			if (select_team_01 > 0 && select_team_02 > 0)
			{
				cout << "\n\n\t";
				system("pause");
				match_obj.conductMatch();
			}
			else
			{
				cout << "\n\t\tKINDLY ENTER MATCH DETAILS FIRST!";
			}
		}
		else if (choice == 3)//CLEAR SCREEN
		{
			system("pause");
			system("cls");
		}
		else
		{
			cout << "\n\n\t Enter correct option.";
		}
	} while (choice != 4);
}
void match_menu(Match& match_obj, Team& team_01, Team& team_02, int& select_team_01, int& select_team_02)
{
	int choice = 0;
	bool team_data = 0;
	string s;

	do
	{
		cout << endl << endl;
		system("pause");
		system("cls");
		display_format(1);
		display_format(4);
		cout << "\n\t\t\tWhat do you want to perform : ";
		cout << "\n\t\t\t 01- SET MATCH DETAILS ";
		cout << "\n\t\t\t 02- SELECT TEAMS";
		cout << "\n\t\t\t 03- UPLOAD TEAMS DATA ";
		cout << "\n\t\t\t 04- UPLOAD PLAYERS DATA " << endl;
		cout << "\n\t\t\t 05- DISPLAY MATCH DETAILS";
		cout << "\n\t\t\t 06- DISPLAY PLAYERS DATA";
		cout << "\n\t\t\t 07- DISPLAY TEAM 01";
		cout << "\n\t\t\t 08- DISPLAY TEAM 02" << endl;
		cout << "\n\t\t\t 09- SEARCH PLAYERS";
		cout << "\n\t\t\t 10- UPDATE PLAYERS" << endl;
		cout << "\n\t\t\t 11- CLEAR SCREEN";
		cout << "\n\t\t\t 12- EXIT";
		cout << "\n\t\tChoose any option : ";
		cin >> choice;
		check_int_Input(choice);
		format();
		if (choice == 1)//SET MATCH DETAILS
		{
			match_obj.set_Match_Details();
		}
		else if (choice == 2)//SELECT TEAMS
		{
			select_teams(select_team_01, select_team_02);
		}
		else if (choice == 3)//UPLOAD TEAMS DATA
		{
			if (select_team_01 > 0 && select_team_02 > 0)
			{
				match_obj.Upload_Team_Data(&team_01, &team_02, select_team_01, select_team_02);
				match_obj.set_Team_01(&team_01);
				match_obj.set_Team_02(&team_02);
				team_data = 1;
			}
			else
			{
				cout << "\n\tPLEASE SELECT TEAMS FIRST!\n";
			}
		}
		else if (choice == 4)//UPLOAD PLAYERS DATA
		{
			if (select_team_01 > 0 && select_team_02 > 0)
			{
				team_01.addPlayer(select_team_01);
				team_02.addPlayer(select_team_02);
				cout << endl;
				match_obj.set_Team_01(&team_01);
				match_obj.set_Team_02(&team_02);
			}
			else
			{
				cout << "\n\tPLEASE SELECT TEAMS FIRST!\n";
			}
		}
		else if (choice == 5)//DISPLAY MATCH DETAILS
		{
			if (select_team_01 > 0 && select_team_02 > 0)
			{
				match_obj.get_Match_Details();
			}
			else
			{
				cout << "\n\tPLEASE SELECT TEAMS FIRST!\n";
			}
		}
		else if (choice == 6)//DISPLAY PLAYERS DATA
		{
			if (select_team_01 > 0 && select_team_02 > 0)
			{
				cout << "\n\t\t\tTEAM 01 PLAYERS";
				team_01.get_Team_Players();
				format();
				cout << "\n\t\t\tTEAM 02 PLAYERS";
				team_02.get_Team_Players();
				match_obj.set_Team_01(&team_01);
				match_obj.set_Team_02(&team_02);
			}
			else
			{
				cout << "\n\tPLEASE SELECT TEAMS FIRST!\n";
			}
		}
		else if (choice == 7)//DISPLAY TEAM 01
		{
			if ((select_team_01 > 0 && select_team_02 > 0) && team_data == 1)
			{
				match_obj.get_Team_01();	//DISPLAY TEAM 01
			}
			else if ((select_team_01 > 0 && select_team_02 > 0) && team_data == 0)
			{
				cout << "\n\tPLEASE UPLOAD TEAMS DATA FIRST!\n";
			}
			else
			{
				cout << "\n\tPLEASE SELECT TEAMS FIRST!\n";
			}
		}
		else if (choice == 8)//DISPLAY TEAM 02
		{
			if ((select_team_01 > 0 && select_team_02 > 0) && team_data == 1)
			{
				match_obj.get_Team_02();	//DISPLAY TEAM 02
			}
			else if ((select_team_01 > 0 && select_team_02 > 0) && team_data == 0)
			{
				cout << "\n\tPLEASE UPLOAD TEAMS DATA FIRST!\n";
			}
			else
			{
				cout << "\n\tPLEASE SELECT TEAMS FIRST!\n";
			}
		}
		else if (choice == 9)//SEARCH PLAYERS
		{
			if (select_team_01 > 0 && select_team_02 > 0)
			{
				cout << "\n\tEnter Player Name you want to SEARCH : ";
				cin.ignore();
				getline(cin, s);
				cout << "\nbefore search";
				team_01.searchPlayer(s);
				team_02.searchPlayer(s);
				match_obj.set_Team_01(&team_01);
				match_obj.set_Team_02(&team_02);
			}
			else
			{
				cout << "\n\tPLEASE SELECT TEAMS FIRST!\n";
			}
		}
		else if (choice == 10)//UPDATE PLAYERS
		{
			if (select_team_01 > 0 && select_team_02 > 0)
			{
				cout << "\n\tEnter Player Name you want to UPDATE: ";
				cin.ignore();
				getline(cin, s);
				team_01.updatePlayer(s);
				team_02.updatePlayer(s);
				match_obj.set_Team_01(&team_01);
				match_obj.set_Team_02(&team_02);
			}
			else
			{
				cout << "\n\tPLEASE SELECT TEAMS FIRST!\n";
			}
		}
		else if (choice == 11)//CLEAR SCREEN
		{
			system("pause");
			system("cls");
		}
	} while (choice != 12);

}
void select_teams(int& c1, int& c2)
{
	do
	{
		cout << "\n\t\t\tCurrently Available Teams are : ";
		cout << "\n\t\t\t01- PAKISTAN";
		cout << "\n\t\t\t02- INDIA";
		cout << "\n\t\t\t03- ENGLAND";
		cout << "\n\t\t\t04- NEW-ZELAND";
		do
		{
			cout << "\n\t\tENTER YOUR FIRST TEAM  : ";
			cin >> c1;
			check_int_Input(c1);
			cout << "\t\tENTER YOUR SECOND TEAM  : ";
			cin >> c2;
			check_int_Input(c2);
			if (c1 == c2)
			{
				cout << "\n\t--->Both teams must be different. Enter Data Again!";
			}
		} while (c1 >= 5 || c2 >= 5);
	} while (c1 == c2);

	{
		if (c1 == 1)
		{
			cout << "\n\t\tTEAM 01 is PAKISTAN.";
		}
		else if (c1 == 2)
		{
			cout << "\n\t\tTEAM 01 is INDIA.";
		}
		else if (c1 == 3)
		{
			cout << "\n\t\tTEAM 01 is ENGLAND.";
		}
		else if (c1 == 4)
		{
			cout << "\n\t\tTEAM 01 is NEWZEALAND.";
		}
	}
	{
		if (c2 == 1)
		{
			cout << "\n\t\tTEAM 02 is PAKISTAN.";
		}
		else if (c2 == 2)
		{
			cout << "\n\t\tTEAM 02 is INDIA.";
		}
		else if (c2 == 3)
		{
			cout << "\n\t\tTEAM 02 is ENGLAND.";
		}
		else if (c2 == 4)
		{
			cout << "\n\t\tTEAM 02 is NEWZEALAND.";
		}
	}
	cout << endl;
}
void format()
{
	cout << endl;
	for (int i = 0; i < 51; i++)
	{
		cout << " * ";
	}
	cout << endl;
}
void display_format(int x)
{
	format();
	if (x == 1)
	{
		cout << "\n\t\t\t\t\t********************************************************************";
		cout << "\n\t\t\t\t\t*			CRICBUZZ MANAGEMENT SYSTEM		   *";
		cout << "\n\t\t\t\t\t********************************************************************";
	}
	else if (x == 2)
	{
		cout << "\n\t\t\t\t\t********************************************************************";
		cout << "\n\t\t\t\t\t*			\tMAIN MENU			   *";
		cout << "\n\t\t\t\t\t********************************************************************";
	}
	else if (x == 3)
	{
		cout << "\n\t\t\t\t\t********************************************************************";
		cout << "\n\t\t\t\t\t*			\tMATCH MENU			   *";
		cout << "\n\t\t\t\t\t********************************************************************";
	}
	else if (x == 4)
	{
		cout << "\n\t\t\t\t\t********************************************************************";
		cout << "\n\t\t\t\t\t*			\tTEAM MENU			   *";
		cout << "\n\t\t\t\t\t********************************************************************";
	}
	format();
}
