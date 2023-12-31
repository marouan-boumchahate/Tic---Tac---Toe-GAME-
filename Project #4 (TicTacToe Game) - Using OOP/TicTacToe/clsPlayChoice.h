#pragma once

#include "clsUtil.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsPlayer.h"

class clsPlayChoice : protected clsScreen
{
private:
	static string ChoosingPosition()
	{
		bool isTrue;
		string pos;

		do
		{
			clsPlayer::PrintTheEmptyPos();

			pos = clsInputValidate::ReadString("\n" + clsUtil::Tabs(5) + "Enter a free position from above choices: ");

			if (!(isTrue = clsPlayer::isPosEnteredTrue(pos)))
			{
				cout << "The position (Filled or Not exist)\nTry Again\n\n";
			}

		} while (!isTrue);

		return pos;
	}

	static void PlacingPosition(clsPlayer& Player, string pos)
	{
		Player.PerformThePosition(pos);
	}

public:
	static void PLay(clsPlayer& Player)
	{
		cout << clsUtil::Tabs(8) << Player.PlayerName << endl;
		cout << clsUtil::Tabs(8) << clsUtil::Design('-', Player.PlayerName.length()) << endl << endl;

		string pos = ChoosingPosition();

		PlacingPosition(Player, pos);
	}

};

