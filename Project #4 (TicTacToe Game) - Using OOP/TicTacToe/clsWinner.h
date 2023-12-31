#pragma once

class clsWinner
{
private:
    static bool _CheckVerticalLines(clsPlayer& Player)
    {
        for (short i = 0; i < 3; i++)
        {
            if ((Player._FillsTable[i] == Player.Tool) && (Player._FillsTable[i + 3] == Player.Tool) && (Player._FillsTable[i + 6] == Player.Tool))
            {
                Player.WinLoss = "Win";
                return true;
            }
        }

        return false;
    }

    static bool _CheckHorizontalLines(clsPlayer& Player)
    {
        for (short i = 0; i < 7; i += 3)
        {
            if ((Player._FillsTable[i] == Player.Tool) && (Player._FillsTable[i + 1] == Player.Tool) && (Player._FillsTable[i + 2] == Player.Tool))
            {
                Player.WinLoss = "Win";
                return true;
            }
        }

        return false;
    }

    static bool _CheckDiagonalLines(clsPlayer& Player)
    {
        if (((Player._FillsTable[0] == Player.Tool) && (Player._FillsTable[4] == Player.Tool) && (Player._FillsTable[8] == Player.Tool)))
        {
            Player.WinLoss = "Win";
            return true;
        }

        if ((Player._FillsTable[2] == Player.Tool) && (Player._FillsTable[4] == Player.Tool) && (Player._FillsTable[6] == Player.Tool))
        {
            Player.WinLoss = "Win";
            return true;
        }

        return false;
    }

    static bool _isTableFilled()
    {
        return clsPlayer::isTableFilledAll();
    }

public:
	static bool isThereAnyWinner(clsPlayer& Player)
	{
         
        if (_CheckVerticalLines(Player) || _CheckHorizontalLines(Player) || _CheckDiagonalLines(Player))
            return true;

        if (_isTableFilled())
        {
            Player.WinLoss = "No One";
            return true;
        }

         return false;
	}
};

