#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

vi a[500001];
vector<ii> interval;
int nxt[1000001];

bool comp(int u, int v)
{
	int l1 = a[u].size(); int l2 = a[v].size();
	int c = -1; int d = -1;
	for(int i = 0; i < l1; i++)
	{
		if(i >= l2)
		{
			//this means x > y
			return false;
		}
		if(a[u][i] != a[v][i])
		{
			c = a[u][i]; d = a[v][i];
			break;
		}
	}
	//c < d
	if(c == -1 && d == -1)
	{
		return true;
	}
	//We know c < d
	interval.pb(mp(c, d));
	return true;
}

bool used[1000001];
int nex[1000001];

int main()
{
	//ios_base::sync_with_stdio(0); cin.tie(0);
	int n, c; 
	scanf("%d %d", &n, &c);
	for(int i = 0; i < n; i++)
	{
		int l; scanf("%d", &l);
		a[i].resize(l);
		for(int j = 0; j < l; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	for(int i = 0; i < n - 1; i++) 
	{
		if(!comp(i,i+1))
		{
			printf("-1");
			return 0;
		}
	}
	for(int i = 1; i <= c; i++)
	{
		nxt[i] = i;
	} 
	for(int i = 0; i < interval.size(); i++)
	{
		int l = interval[i].fi; int r = interval[i].se;
		if(l <= r)
		{
			if(nxt[l] >= l && nxt[l] < r)
			{
				nxt[l] = r;
			}
		}
		else
		{
			if(nxt[l] >= l || r > nxt[l])
			{
				nxt[l] = r;
			}
		}
	}
	for(int i = 1; i <= c; i++)
	{
		if(nxt[i] < i)
		{
			nxt[i] += c;
		}
	}
	int rmin = c; int rmax = 2*c-1;
	vector<ii> in;
	for(int i = 1; i <= c; i++)
	{
		//cerr << i << ' ' << nxt[i] << '\n';
		if(nxt[i] > c)
		{
			rmin = max(rmin, nxt[i]);
			rmax = min(rmax, i+c-1);
		}
		else
		{
			in.pb(mp(c+i, c+nxt[i]-1));
		}
	}
	if(rmin>rmax)
	{
		printf("-1");
		return 0;
	}
	/*
	if(rmax==2*c) rmax = c;
	int l = rmax - c + 1;
	//cerr<<rmin<<' '<<rmax<<'\n';
	//cerr<<l<<' '<<r<<'\n';
	bool pos = true;
	for(int i = 1; i <= c; i++)
	{
		if(nxt[i] <= c)
		{
			int L = i; int R = nxt[i];
			//cerr<<L<<' '<<R<<'\n';
			if(L < l)
			{
				L += c;
			}
			if(R < l)
			{
				R += c;
			}
			//cerr<<L<<' '<<R<<'\n';
			if(L > R)
			{
				pos = false;
				break;
			}
		}
	}
	*/
	bool pos =  true;
	int r = -1;
	for(int i = 0; i <= c; i++)
	{
		nex[i] = i+1;
	}
	for(int i = 0; i < in.size(); i++)
	{
		if(in[i].fi>in[i].se) continue;
		//cerr<<in[i].fi<<' '<<in[i].se<<'\n';
		int le = in[i].fi; int ri = in[i].se;
		le-=c; ri-=c;
		int ptr = le-1;
		ptr = nex[ptr];
		while(ptr <= ri)
		{
			int tmp = nex[ptr];
			used[ptr] = true;
			nex[ptr] = nex[ri];
			ptr = tmp;
		}
	}
	for(int i = rmin; i <= rmax; i++)
	{
		if(!used[i-c])
		{
			r = i;
			break;
		}
	}
	if(r==-1) 
	{
		printf("-1"); return 0;
	}
	int l = r - c + 1;
	if(pos)
	{
		int ans = c+1-l;
		ans%=c;
		printf("%d", ans);
		return 0;
	}
}