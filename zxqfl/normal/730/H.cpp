#include <bits/stdc++.h>

using namespace std;

void fail()
{
	cout << "No" << endl;
	exit(0);
}

bool matches(string pat, string cand)
{
	if (pat.length() != cand.length())
	{
		return false;
	}
	for (int i = 0; i < pat.length(); i++)
	{
		if (pat[i] != '?' && pat[i] != cand[i])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<string> names(n);
	vector<int> rem(m);
	for (int i = 0; i < n; i++)
	{
		cin >> names[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> rem[i];
		--rem[i];
	}
	int len = names[rem[0]].length();
	for (int x : rem)
	{
		if (names[x].length() != len)
		{
			fail();
		}
	}
	string pattern = names[rem[0]];
	for (int x : rem)
	{
		for (int i = 0; i < len; i++)
		{
			if (pattern[i] != names[x][i])
			{
				pattern[i] = '?';
			}
		}
	}

	set<int> all;
	for (int i = 0; i < n; i++)
	{
		all.insert(i);
	}
	for (int x : rem)
	{
		all.erase(x);
	}

	for (int other : all)
	{
		if (matches(pattern, names[other]))
		{
			fail();
		}
	}
	cout << "Yes" << endl;
	cout << pattern << endl;
}