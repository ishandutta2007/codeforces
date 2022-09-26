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
/*A
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
}*/

int main()
{
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	int h[100001] = {0};
	int a[100001] = {0};
	//int arrh[100001];
	int arra[100001];
	
	int x, y;
	
	for(int i = 0; i < n; i++)
	{
		cin >> x >> y;
		h[x - 1]++;
		a[y - 1]++;
		//cout << x << " " << y << endl;
		//arrh[i] = x;
		arra[i] = y;
	}
	
	for(int i = 0; i < n; i++)
	{
		cout << n - 1 + h[arra[i] - 1] << " " << n - 1 - h[arra[i] - 1] << endl;
	}
	return 0;
}