#pragma once

#include "clsScreen.h"
#include "clsPlayer.h"
#include "clsPlayChoice.h"
#include "clsWinner.h"
#include "clsInputValidate.h"
#include <iomanip>

class clsManageGame : protected clsScreen
{
private:
	static string ReadPlayerName(string msg)
	{
		return clsInputValidate::ReadString(msg);
	}

	static char ReadPlayerTool(string msg)
	{
		char value;
		bool isTrue;

		do
		{
			value = toupper(clsInputValidate::ReadCharacter(msg));

			if ((isTrue = (value != 'X' && value != 'O')))
				cout << "Only two options (X | O)\nTry Again\n\n";

		} while (isTrue);

		return value;
	}

	static void ReadPlayersInfo(clsPlayer& Pl1, clsPlayer& Pl2)
	{
		system("cls");
		_DrawTicTacToe(Pl1._FillsTable, "TicTacToe");

		Pl1.PlayerName = ReadPlayerName(clsUtil::Tabs(5) + "Enter Your name: ");
		Pl2.PlayerName = ReadPlayerName(clsUtil::Tabs(5) + "Opponent Name: ");

		cout << endl;

		Pl1.Tool = ReadPlayerTool(clsUtil::Tabs(5) + "Enter The tool you will play by (X | O): ");
		Pl2.Tool = (Pl1.Tool == 'X' ? 'O' : 'X');
	}

	static bool DisplayPlayersInfo(clsPlayer Pl1, clsPlayer Pl2)
	{
		system("cls");
		_DrawTicTacToe(Pl1._FillsTable, "TicTacToe");

		cout << clsUtil::Tabs(6) << setw(21) << left << "Player_1" << setw(21) << left << "Player_2" << endl << endl;
		cout << clsUtil::Tabs(6) << setw(21) << left << Pl1.PlayerName << setw(21) << left << Pl2.PlayerName << endl;
		cout << clsUtil::Tabs(6) << setw(21) << left << Pl1.Tool << setw(21) << left << Pl2.Tool << endl << endl;

		return clsUtil::isYes(clsUtil::Tabs(5) + "Do you confirm these info to start playing (Y/N): ");
	}

	static void DisplayFinallyPlayersInfo(clsPlayer Pl1, clsPlayer Pl2)
	{
		system("cls");
		_DrawTicTacToe(Pl1._FillsTable, "TicTacToe");

		cout << clsUtil::Tabs(6) << setw(21) << left << "Player_1" << setw(21) << left << "Player_2" << endl << endl;
		cout << clsUtil::Tabs(6) << setw(21) << left << Pl1.PlayerName << setw(21) << left << Pl2.PlayerName << endl;
		cout << clsUtil::Tabs(6) << setw(21) << left << Pl1.Tool << setw(21) << left << Pl2.Tool << endl;
		cout << clsUtil::Tabs(6) << setw(21) << left << Pl1.WinLoss << setw(21) << left << Pl2.WinLoss << endl << endl;
	}

	static void ManageThePlay()
	{
		clsPlayer Player_1;
		clsPlayer Player_2;

		bool isTrue;

		do
		{
			ReadPlayersInfo(Player_1, Player_2);

		} while (!DisplayPlayersInfo(Player_1, Player_2));

		do
		{
			system("cls");
			_DrawTicTacToe(Player_1._FillsTable, "TicTacToe");

			clsPlayChoice::PLay(Player_1);
			isTrue = clsWinner::isThereAnyWinner(Player_1);

			if (!isTrue)
			{
				system("cls");
				_DrawTicTacToe(Player_2._FillsTable, "TicTacToe");

				clsPlayChoice::PLay(Player_2);
				isTrue = clsWinner::isThereAnyWinner(Player_2);
			}

		} while (!isTrue);

		if (Player_1.WinLoss == "")
			Player_1.WinLoss = (Player_2.WinLoss == "Win" ? "Loss" : "No One");
		else if (Player_2.WinLoss == "")
			Player_2.WinLoss = (Player_1.WinLoss == "Win" ? "Loss" : "No One");

		DisplayFinallyPlayersInfo(Player_1, Player_2);
	}

public:
	static void PlayTheGame()
	{
		do
		{
			ManageThePlay();

		} while (clsUtil::isYes(clsUtil::Tabs(5) + "Do You wanna Play A new Round (Y/N): "));
	}
};

