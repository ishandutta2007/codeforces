#include <iostream>
#include <string>
#include <queue>
#include <cstdio>
using namespace std;

//#define TASK ""

queue<pair<string, int> > Q;

int main(int argc, char **argv)
{
#ifdef TASK
	freopen(TASK".in", "r", stdin);
	freopen(TASK".out", "w", stdout);
#endif
	int n;
	cin >> n;
	string s;
	Q.push(make_pair("Sheldon", 1));
	Q.push(make_pair("Leonard", 1));
	Q.push(make_pair("Penny", 1));
	Q.push(make_pair("Rajesh", 1));
	Q.push(make_pair("Howard", 1));
	int t;
	while (1)
	{
		if (n > Q.front().second)
		{
			s = Q.front().first;
			t = Q.front().second;
			Q.pop();
			n -= t;
			Q.push(make_pair(s, 2 * t));
		}
		else
		{
			cout << Q.front().first;
			return 0;
		}
	}
}