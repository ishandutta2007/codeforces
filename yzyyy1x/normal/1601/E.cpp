#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define sc second
#define pb push_back
#define ll long long
#define trav(v, x) for(auto v:x)
#define VI vector<int>
#define VLL vector<ll>
//define double long double
#define all(x) (x).begin(),(x).end()
using namespace std;
const double eps = 1e-10;//1e-12
const int N = 3e5 + 100;
const ll mod = 998244353;//1e9 + 7;

struct gg{
	int l, r;
	int id;
	gg(){};
	gg(int l, int r, int id):l(l), r(r), id(id){};
};

int n, m, a[N], step, qq, lg[N], b[N];
vector<int>val[N];
vector<gg>qry[N];
int mn[N][20];
ll ans[N];

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> qq >> step;
	multiset<int>st;
	queue<int>bin;
	for(int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		b[i] = x;
		st.insert(x);
		bin.push(x);
		if(i > step + 1)
			st.erase(st.find(bin.front())), bin.pop();
		a[i] = (*st.begin());
	}
	for(int i = 1; i <= n; i++)
	{
		val[i % step].pb(a[i]);
	}
	for(int i = 1; i <= qq; i++)
	{
		int l, r, lp, rp;
		cin >> l >> r;
		ans[i] += b[l];
		l += step;
		if(l > r)
		{
			continue;
		}
		lp = (l - 1) / step;
		r = (r - l) / step * step + l;
		rp = (r - 1) / step;
		qry[l % step].pb(gg(lp, rp, i));
	}
	lg[1] = 0;
	for(int i = 2; i <= n; i++)
		lg[i] = lg[i >> 1] + 1;
	for(int rem = 0; rem < step; rem ++)
	{
		vector<int>&buk = val[rem];
		auto get = [&](int l, int r)
		{
			int k = lg[r - l + 1];
			r -= (1 << k), ++r;
			if(buk[mn[l][k]] <= buk[mn[r][k]])
				return mn[l][k];
			else
				return mn[r][k];
		};
		int sz = buk.size();
		buk.pb(-1);
		for(int i = 0; i <= sz; i++)
			mn[i][0] = i;
		for(int k = 1; k < 20; k++)
		{
			int len = (1 << k);
			for(int i = 0; i + len - 1 <= sz; i++)
			{
				int ni = i + (len >> 1);
				if(buk[mn[i][k - 1]] <= buk[mn[ni][k - 1]])
					mn[i][k] = mn[i][k - 1];
				else 
					mn[i][k] = mn[ni][k - 1];
			}
		}
		vector<ll> dp(sz + 1, 0);
		stack<int>stk;
		while(!stk.empty())stk.pop();
		dp[sz] = 0, stk.push(sz);
		for(int i = sz - 1; i >= 0; i--)
		{
			while(buk[stk.top()] >= buk[i])
				stk.pop();
			int nx = stk.top();
			dp[i] = dp[nx] + 1LL * buk[i] * (nx - i);
			stk.push(i);
		//	cerr << i << ' ' << buk[i] << ' ' << nx<< ' ' << dp[i] << '\n';
		}
		trav(v, qry[rem])
		{
			int l = v.l;
			int r = v.r;
			int id = v.id;
			int ps = get(l, r);
			ll res = dp[l] - dp[ps];
			res += 1LL * buk[ps] * (r - ps + 1);
			ans[id] += res;
		}
	}
	for(int i = 1; i <= qq; i++)
		cout << ans[i] << '\n';
}