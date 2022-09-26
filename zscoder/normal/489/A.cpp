#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

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
}