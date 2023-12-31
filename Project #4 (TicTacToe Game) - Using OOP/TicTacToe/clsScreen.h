#pragma once

#include <iostream>
#include "clsUtil.h"

class clsScreen
{
private:
	static void _DrawTable(char pos[9])
	{
		cout << clsUtil::Tabs(6) << "    " << "    A     " << "      B     " << "      C     " << endl << endl;
							  
		cout << clsUtil::Tabs(6) << "    " << "          " << "* " << "          " << "* " << "          " << endl;
		cout << clsUtil::Tabs(6) << "1   " << "    " << pos[0] << "     " << "* " << "    " << pos[1] << "     " << "* " << "    " << pos[2] << "     " << endl;
		cout << clsUtil::Tabs(6) << "    " << "          " << "* " << "          " << "* " << "          " << endl;
							  	
		cout << clsUtil::Tabs(6) << "    " << "* * * * * " << "* " << "* * * * * " << "* " << "* * * * * " << endl;
							  
		cout << clsUtil::Tabs(6) << "    " << "          " << "* " << "          " << "* " << "          " << endl;
		cout << clsUtil::Tabs(6) << "2   " << "    " << pos[3] << "     " << "* " << "    " << pos[4] << "     " << "* " << "    " << pos[5] << "     " << endl;
		cout << clsUtil::Tabs(6) << "    " << "          " << "* " << "          " << "* " << "          " << endl;
							 
		cout << clsUtil::Tabs(6) << "    " << "* * * * * " << "* " << "* * * * * " << "* " << "* * * * * " << endl;
							  
		cout << clsUtil::Tabs(6) << "    " << "          " << "* " << "          " << "* " << "          " << endl;
		cout << clsUtil::Tabs(6) << "3   " << "    " << pos[6] << "     " << "* " << "    " << pos[7] << "     " << "* " << "    " << pos[8] << "     " << endl;
		cout << clsUtil::Tabs(6) << "    " << "          " << "* " << "          " << "* " << "          " << endl;
	}						  

	static void _DrawHeader(string Title)
	{
		cout << clsUtil::Tabs(5) << clsUtil::Design('_', 50) << endl << endl;
		cout << clsUtil::Tabs(7) << "   " << Title << endl;
		cout << clsUtil::Tabs(5) << clsUtil::Design('_', 50) << endl << endl << endl;
	}

protected:
	static void _DrawTicTacToe(char pos[9], string Title)
	{
		_DrawHeader(Title);

		_DrawTable(pos);

		cout << clsUtil::Tabs(5) << clsUtil::Design('_', 50) << endl << endl << endl;
	}
};

