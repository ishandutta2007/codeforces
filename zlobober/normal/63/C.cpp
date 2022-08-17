#include <iostream>
#include <string>
#include <vector>
using namespace std;

string str(int q)
{
	string ans;
	ans.resize(4);
	for (int i = 3; i >= 0; i--)
		ans[i] = q % 10 + '0', q /= 10;
	return ans;
}

const int N = 50;

pair<string, pair<int, int> > V[N];

pair<int, int> cmp(string a, string b)
{
	int x = 0, y = 0;
	for (int i = 0; i < 4; i++)
		x += a[i] == b[i];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			if (i == j)
				continue;
			y += a[i] == b[j];
		}
	return make_pair(x, y);
}

bool check(string s)
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < i; j++)
			if (s[i] == s[j])
				return false;
				
	return true;
}

int main()
{
	int n;
	cin >> n;
	string t;
	int a, b;
	for (int i = 0; i < n; i++)
	{
		cin >> t >> a >> b;
		V[i] = make_pair(t, make_pair(a, b));
	}
	
	int col = 0;
	pair<int, int> pr;
	string ustr;
	vector<int> mb;
	for (int u = 0; u < 10000; u++)
	{
		ustr = str(u);
		if (!check(ustr))
			continue;
		for (int i = 0; i < n; i++)
		{
			pr = cmp(ustr, V[i].first);
			if (pr < V[i].second || pr > V[i].second)
				goto nextu;
		}
		mb.push_back(u);
		nextu:;
	}
	if (mb.size() == 0)
	{
		cout << "Incorrect data";
	}
	else if (mb.size() == 1)
	{
		cout << str(mb[0]);
	}
	else
	{
		cout << "Need more data";
	}
	return 0;
}