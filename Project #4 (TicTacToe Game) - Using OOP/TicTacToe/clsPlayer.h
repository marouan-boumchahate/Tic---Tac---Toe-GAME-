#pragma once

#include <iostream>
#include <vector>
#include "clsUtil.h"

using namespace std;

class clsPlayer
{
private:
	string _PlayerName;
	char _Tool;
	static vector<string> _Pos;
	string _WinOrLoss;

	void _FreeDataFromTable()
	{
		for (char& x : _FillsTable)
			x = ' ';
	}

	void _OriginPositions()
	{
		Pos = { "1A", "1B", "1C", "2A", "2B", "2C", "3A", "3B", "3C" };
	}

public:
	// Variables 
	static char _FillsTable[9];

	// Constructors
	clsPlayer()
	{
		_FreeDataFromTable();
		SetWinLoss("");
		_OriginPositions();
	}

	// Setters
	void SetPlayerName(string PlayerName)
	{
		_PlayerName = PlayerName;
	}
	void SetTool(char tool)
	{
		_Tool = tool;
	}
	void SetPos(vector<string> Pos)
	{
		_Pos = Pos;
	}
	void SetWinLoss(string WinOrLoss)
	{
		_WinOrLoss = WinOrLoss;
	}
	void SetValueToFills(char value, short index)
	{
		_FillsTable[index] = value;
	}

	// Getters
	string GetPlayerName()
	{
		return _PlayerName;
	}
	char GetTool()
	{
		return _Tool;
	}
	vector<string> GetPos()
	{
		return _Pos;
	}
	string GetWinLoss()
	{
		return _WinOrLoss;
	}
	char* GetFills()
	{
		return _FillsTable;
	}

	// Using Equal
	__declspec(property(get = GetPlayerName, put = SetPlayerName)) string PlayerName;
	__declspec(property(get = GetPos, put = SetPos)) vector<string> Pos;
	__declspec(property(get = GetWinLoss, put = SetWinLoss)) string WinLoss;
	__declspec(property(get = GetTool, put = SetTool)) char Tool;

	// Functions
	void PerformThePosition(string pos)
	{
		SetValueToFills(Tool, CancelUsedPosition(pos));
	}

	short CancelUsedPosition(string pos)
	{
		for (short i = 0; i < _Pos.size(); i++)
			if (_Pos[i] == pos)
			{
				_Pos.at(i) = "";
				return i;
			}
	}

	static void PrintTheEmptyPos()
	{
		cout << clsUtil::Tabs(7) << "  Free Positions" << endl;

		cout << clsUtil::Tabs(5);

		for (string& x : _Pos)
			cout << x << "    ";

		cout << endl;
	}

	static bool isPosEnteredTrue(string pos)
	{
		for (string& x : _Pos)
			if (x == pos)
				return true;

		return false;
	}

	static bool isTableFilledAll()
	{
		for (char& x : _FillsTable)
			if (x == ' ')
				return false;

		return true;
	}
};

char clsPlayer::_FillsTable[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
vector<string> clsPlayer::_Pos = {"1A", "1B", "1C", "2A", "2B", "2C", "3A", "3B", "3C"};