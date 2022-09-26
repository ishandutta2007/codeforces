#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>
#include <queue>
#include <map>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
/*
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int bear = 0;
	vi candidates;
	int x;
	cin >> bear;
	if(n == 1)
	{
		cout << 0 << endl;
		return 0;
	}
	for(int i = 0; i < n - 1; i++)
	{
		cin >> x;
		candidates.push_back(x);
	}
	int candy = 0;
	sort(candidates.begin(), candidates.end());
	while(bear <= candidates.at(n - 2))
	{
		candidates.at(n - 2)--;
		candy++;
		bear++;
		sort(candidates.begin(), candidates.end());
	}
	
	cout << candy << endl;
	return 0;
}*/

int divide(int n)
{
	while(n % 2 == 0)
	{
		n /= 2;
	}
	while(n % 3 == 0)
	{
		n /= 3;
	}
	return n;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int current = -1;
	bool ans = true;
	int x;
	for(int i = 0; i < n; i++)
	{
		cin >> x;
		if(i > 0)
		{
			if(current != divide(x))
			{
				ans = false;
			}
		}
		current = divide(x);
	}
	if(ans)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;
}