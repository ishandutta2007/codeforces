#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
#include <cstring>

using namespace std;

typedef long long ll;
typedef vector <int> vi;

int main()
{
	vi vec;
	int x;
	for(int i = 0; i < 6; i++)
	{
		cin >> x;
		vec.push_back(x);
	}
	sort(vec.begin(), vec.end());
	int answer = 0;
	if(vec.at(0) == vec.at(1) && vec.at(1) == vec.at(2) && vec.at(2) == vec.at(3))
	{
		if(vec.at(4) == vec.at(5))
		{
			answer = 2;
		}
		else
		{
			answer = 1;
		}
	}
	else if(vec.at(1) == vec.at(2) && vec.at(2) == vec.at(3) && vec.at(3) == vec.at(4))
	{
		if(vec.at(0) == vec.at(5))
		{
			answer = 2;
		}
		else
		{
			answer = 1;
		}
	}
	else if(vec.at(2) == vec.at(3) && vec.at(3) == vec.at(4) && vec.at(4) == vec.at(5))
	{
		if(vec.at(0) == vec.at(1))
		{
			answer = 2;
		}
		else
		{
			answer = 1;
		}
	}
	else
	{
		answer = -1;
	}
	if(answer == -1)
	{
		cout << "Alien" << endl;
	}
	else if(answer == 1)
	{
		cout << "Bear" << endl;
	}
	else
	{
		cout << "Elephant" << endl;
	}
	return 0;
}