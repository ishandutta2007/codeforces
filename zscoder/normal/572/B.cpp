#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <cstdlib>

using namespace std;

#define INF = 200000000;
typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
/*
int main()
{
	int n, m;
	cin >> n >> m;
	int a, b;
	cin >> a >> b;
	vi A;
	vi B;
	int x;
	for(int i = 0; i < n; i++)
	{
		cin >> x;
		A.push_back(x);
	}
	for(int i = 0; i < m; i++)
	{
		cin >> x;
		B.push_back(x);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	if(A.at(a - 1) < B.at(m - b))
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	return 0;
}*/
bool compare(pair<int, int> x, pair<int, int> y)
{
	if(x.first < y.first)
	{
		return false;
	}
	else if(x.first == y.first)
	{
		if(x.second < y.second)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		return true;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vii buy;
	vii sell;
	char x;
	int a, b;
	pair<int, int> cost;
	for(int i = 0; i < n; i++)
	{
		cin >> x >> a >> b;
		cost.first = a;
		cost.second = b;
		if(x == 'S')
		{
			sell.push_back(cost);
		}
		else
		{
			buy.push_back(cost);
		}
	}
	sort(sell.begin(), sell.end(), compare);
	sort(buy.begin(), buy.end(), compare);
	int temp = -1;
	for(int i = 0; i < sell.size(); i++)
	{
		if(sell.at(i).first == temp)
		{
			sell.at(i).second += sell.at(i - 1).second;
			sell.at(i - 1).second = 0;
		}
		temp = sell.at(i).first;
	}
	temp = -1;
	for(int i = 0; i < buy.size(); i++)
	{
		if(buy.at(i).first == temp)
		{
			buy.at(i).second += buy.at(i - 1).second;
			buy.at(i - 1).second = 0;
		}
		temp = buy.at(i).first;
	}
	int j = 0;
	int idx = sell.size() - 1;
	vii ans;
	while(j < k && idx >= 0)
	{
		while(idx >= 0 && sell.at(idx).second == 0)
		{
			idx--;
		}
		if(idx >= 0 && sell.at(idx).second > 0)
		{
			ans.push_back(sell.at(idx));
			idx--;
		}
		j++;
	}
	reverse(ans.begin(), ans.end());
	for(int i = 0; i < ans.size(); i++)
	{
		cout << "S" << " " << ans.at(i).first << " " << ans.at(i).second << endl;
	}
	j = 0;
	idx = 0;
	while(j < k && idx < buy.size())
	{
		while(buy.at(idx).second == 0 && idx < buy.size() - 1)
		{
			idx++;
		}
		if(buy.at(idx).second > 0)
		{
			cout << "B" << " " << buy.at(idx).first << " " << buy.at(idx).second << endl;
			idx++;
		}
		j++;
	}
	return 0;
}