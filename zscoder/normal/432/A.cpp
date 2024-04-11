#include <iostream>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <list>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false);
	
	int n, k;
	cin >> n >> k;
	
	vector <int> vec;
	
	int x;
	
	for(int i = 0; i < n; i++)
	{
		cin >> x;
		vec.push_back(x);
	}
	
	sort(vec.begin(), vec.end());
	
	
	int count = 0;
	int count2 = 0;
	
	for(int i = 0; i < n; i++)
	{
		if(5 - vec.at(i) >= k)
		{
			count2++;
		}
		else
		{
			break;
		}
		if(count2 == 3)
		{
			count++;
			count2 = 0;
		}
	}
	
	cout << count;
	return 0;
}