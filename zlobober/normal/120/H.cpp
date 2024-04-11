#include <iostream>
#include <cstdlib>
#include <memory.h>
#include <cstdio>
#include <string>
#include <map>
#include <vector>
using namespace std;

const int N = 100000;

map<string, int> M;

int n;

vector<int> E[N];

string T[N];

int get(string s)
{
	int t = M.size();
	if (M.find(s) != M.end())
		return M[s];
	else
		return (T[t] = s, M[s] = t);
}

void edge(int a, int b)
{
	E[a].push_back(b);
}

string S[N];
int c[N];
int d[N];

bool was[N];

bool dfs(int v){
	was[v]=1;
	int tmp;
	for (vector<int>::iterator it=E[v].begin(); it!=E[v].end(); ++it){
		if (d[*it]!=-1 && !was[d[*it]]){
			tmp=d[*it];
			d[*it]=v;
			if (dfs(tmp)){
				d[v]=*it;
				return true;
			}
			d[*it]=tmp;
		}
		if (d[*it] == -1)
		{
			d[*it] = v;
			d[v] = *it;
			return true;
		}
	}
	return false;
}

void build()
{
	memset(d, -1, sizeof(d));
	while (true){
		bool breaked=false;
		for (int i=0; i<n; ++i)
			if (d[i]==-1)
			{
				if (dfs(i))
				{
					breaked = true;
					break;
				}
			}
		if (!breaked)
			break;
		memset(was, 0, sizeof(was));
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	string s;
		
	if (1)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> s;
			S[i] = s;
			int l = s.size();
			s.push_back('#');
			int sn = get(s);
		}
	}
	else
	{
		int n = 200;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 10; j++)
				cout << (char)('a' + rand() % 26);
			cout << endl;
		}
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		s = S[i];
		int l = s.size();
		string t;
		t.resize(4);
		int sn = i;
		for (int a = 0; a < l; a++)
		{
			t[0] = s[a];
			edge(sn, get(t.substr(0, 1)));
			for (int b = a + 1; b < l; b++)
			{
				t[1] = s[b];
				edge(sn, get(t.substr(0, 2)));
				for (int c = b + 1; c < l; c++)
				{
					t[2] = s[c];
					edge(sn, get(t.substr(0, 3)));
					for (int d = c + 1; d < l; d++)
					{
						t[3] = s[d];
						edge(sn, get(t.substr(0, 4)));
					}
				}
			}
		}
	}
	build();
	bool bad = false;
	for (int i = 0; i < n; i++)
		if (d[i] == -1)
			bad = true;
	if (bad)
		cout << -1;
	else
		for (int i = 0; i < n; i++)
			cout << T[d[i]] << endl;
}