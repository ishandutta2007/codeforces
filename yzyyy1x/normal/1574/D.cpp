#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define sc second
#define pb push_back
#define ll long long
#define trav(v,x) for(auto v:x)
#define ull unsigned long long
using namespace std;
const int N = 4e5 + 100;
const int  inf = 2e9;

int n;
int a[11][N], num[11], rnk[11][N];
map<string, bool>viss;
map<string, bool>used;

struct gg{
	int ps[11];
	int val;
	friend bool operator<(const gg &x, const gg &y)
	{
		if(x.val == y.val)
		{
			for(int i= 1; i <= n;i++)
				if(x.ps[i] != y.ps[i])
					return x.ps[i] < y.ps[i];
		}
		return x.val < y.val;
	}
};

int TP;

bool cmp(int x, int y)
{
	return a[TP][x] > a[TP][y];
}

int m;

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> num[i];
		for(int j = 1; j <= num[i]; j++)
			cin >> a[i][j];
		iota(rnk[i], rnk[i] + num[i] + 1, 0);
		TP = i;
		sort(rnk[i] + 1, rnk[i] + num[i] + 1, cmp);
	}
	gg nw;
	set<gg> pq;
	nw.val  = 0;
	for(int i = 1; i <= n; i++)
	{
		nw.ps[i] = 1;
		nw.val += a[i][rnk[i][1]];
	}
	pq.insert(nw);
	cin >> m;
	for(int i = 1; i <= m; i++)
	{
		string s = "";
		int x;
		for(int j = 1; j <= n; j++)
			cin >> x,  s += to_string(x), s += ',';
		viss[s] = 1;
	}
	vector<gg> hav;
	set<gg>::iterator ii;
	while(!pq.empty())
	{
		ii = prev(pq.end());
		nw = (*ii);
		pq.erase(ii);
		string s = "";
		for(int j = 1; j <= n; j++)
			s += to_string(rnk[j][nw.ps[j]]), s += ',';
		if(!viss[s])
		{
			for(int j = 1; j <= n; j++)
				cout << rnk[j][nw.ps[j]] << ' ';
			cout << '\n';
			return 0;
		}
		--m;
		int tmp = 0;
		for(int i = 1; i <= n; i++)
		{
			if(nw.ps[i] == num[i])
				continue;
			tmp = a[i][rnk[i][nw.ps[i] + 1]] - a[i][rnk[i][nw.ps[i]]];
			nw.val += tmp;
			nw.ps[i]++;
			pq.insert(nw);
			nw.val -= tmp;
			nw.ps[i]--;
		}
		while(pq.size() > m + 1)
			pq.erase(pq.begin());
	}
}
/*
3
2 1 1
2 1 1
2 1 1
1
2 2 2
*/