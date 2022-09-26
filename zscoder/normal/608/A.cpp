#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <string>

using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
vii vec;
bool compare(ii a, ii b)
{
	if(a.first > b.first)
	{
		return true;
	}
	else if(a.first < b.first)
	{
		return false;
	}
	else
	{
		if(a.second < b.second)
		{
			return true;
		}
		return false;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n, s;
	cin >> n >> s;
	int x, y;
	for(int i = 0 ; i < n; i++)
	{
		cin >> x >> y;
		vec.push_back(make_pair(x, y));
	}
	sort(vec.begin(), vec.end(), compare);
	int floor = s;
	int time = 0;
	//int waited = 0;
	for(int i = 0; i < n; i++)
	{
		//cout << time << endl;
		if(floor != vec.at(i).first)
		{
			time += floor - vec.at(i).first;
			floor = vec.at(i).first;
			time = max(time, vec.at(i).second);
		}
		else
		{
			time = max(time, vec.at(i).second);
		}
	}
	cout << time + floor << endl;
	return 0;
}