#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	string p1, p2;
	cin >> p1;
	cin >> p2;
	int scorea = 0, scoreb = 0;
	for(int i = 0; i < p1.length(); i += 2)
	{
		if(p1.at(i) != p2.at(i))
		{
			if(p1.at(i) < p2.at(i))
			{
				if(p1.at(i) == '(' && p2.at(i) == '[')
				{
					scoreb++;
				}
				else
				{
					scorea++;
				}
			}
			else
			{
				if(p1.at(i) == '[' && p2.at(i) == '(')
				{
					scorea++;
				}
				else
				{
					scoreb++;
				}
			}
		}
	}
	if(scorea == scoreb)
	{
		cout << "TIE";
	}
	else if(scorea > scoreb)
	{
		cout << "TEAM 1 WINS";
	}
	else
	{
		cout << "TEAM 2 WINS";
	}
	return 0;
}