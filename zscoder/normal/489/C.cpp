#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;
/*A
struct pairs
{
	int a;
	int b;
};

bool compare(pairs x, pairs y)
{
	if(x.a < y.a)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	
	cin >> n;
	
	vector <pairs> vec;
	
	pairs x;
	
	for(int i = 0; i < n; i++)
	{
		cin >> x.a;
		x.b = i;
		vec.push_back(x);
	}
	
	sort(vec.begin(), vec.end(), compare);
	
	cout << n << endl;
	
	for(int i = 0; i < n; i++)
	{
		cout << vec.at(i).b << " ";
		for(int j = 0; j < n; j++)
		{
			if(vec.at(j).b == i)
			{
				cout << vec.at(j).b << endl;
				int temp = vec.at(j).b;
				vec.at(j).b = vec.at(i).b;
				vec.at(i).b = temp;
				break;
			}
		}
	}
	return 0;
}*/

int main()
{
	ios_base::sync_with_stdio(false);
	int m, s;
	cin >> m >> s;
	if(s == 0 && m == 1)
	{
		cout << "0 0" << endl;
	}
	else if(s > 9*m || s == 0)
	{
		cout << "-1 -1" << endl;
	}
	else
	{
		int remain = s%9;
		int number = floor((double)s/9);
		if(number == m)
		{
			for(int i = 0; i < number; i++)
			{
				cout << "9";
			}
		}
		else if(number == m - 1)
		{
			if(remain > 0)
			{
				cout << remain;
				for(int i = 0; i < number; i++)
				{
					cout << "9";
				}
			}
			else
			{
				cout << "18";
				for(int i = 0; i < number - 10; i++)
				{
					cout << "9";
				}
			}

		}
		else
		{
			if(remain > 0)
			{
				cout << "1";
				for(int i = 0; i < m - number - 2; i++)
				{
					cout << "0";
				}
				cout << remain - 1;
				for(int i = 0; i < number; i++)
				{
					cout << "9";
				}
			}
			else
			{
				cout << "1";
				for(int i = 0; i < m - number - 1; i++)
				{
					cout << "0";
				}
				cout << "8";
				for(int i = 0; i < number - 1; i++)
				{
					cout << "9";
				}
			}

		}
		cout << " ";
		if(number == m)
		{
			for(int i = 0; i < number; i++)
			{
				cout << "9";
			}
		}
		else
		{
			for(int i = 0; i < number; i++)
			{
				cout << "9";
			}
			cout << remain;
			for(int i = number + 1; i < m; i++)
			{
				cout << "0";
			}
		}
	}
	return 0;
}