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
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

const int LG = 19;

vector<ii> ans;
int a[100001];
int nxt[LG][100001];
int nxt2[LG][100001];
int n;

void initst()
{
	nxt[0][n - 1] = -1; nxt2[0][n - 1] = -1;
	for(int i = n - 1; i >= 1; i--)
	{
		if(a[i] == 1)
		{
			nxt[0][i - 1] = i;
			nxt2[0][i - 1] = nxt2[0][i];
		}
		else
		{
			nxt[0][i - 1] = nxt[0][i];
			nxt2[0][i - 1] = i;
		}
	}
	for(int i = 1; i < LG; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(nxt[i-1][j] == -1) nxt[i][j] = -1;
			else nxt[i][j] = nxt[i-1][nxt[i-1][j]];
			if(nxt2[i-1][j] == -1) nxt2[i][j] = -1;
			else nxt2[i][j] = nxt2[i-1][nxt2[i-1][j]];
		}
	}
}

int go(int u, int k, int mode)
{
	if(a[u] == mode) k--;
	for(int i = 0; i < LG; i++)
	{
		if(u != -1 && k&(1<<i)) 
		{
			if(mode == 1) u = nxt[i][u];
			else u = nxt2[i][u];
		}
	}
	return u;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	initst();
	for(int i = 1; i <= n; i++)
	{
		int cnt1 = 0; int cnt2 = 0;
		int u = 0; //bool g = true;
		bool last = 0;
		while(u < n && u != -1)
		{
			//cerr << i << ' ' << u << endl;
			int l1 = go(u, i, 1);
			int l2 = go(u, i, 2);
			//cerr << "L " << l1 << ' ' << l2 << endl;
			if(l1 == -1 && l2 == -1)
			{
				u = -1; //g = false;
			}
			else if(l1 == -1) 
			{
				cnt2++; u = l2; last = 0;
			}
			else if(l2 == -1) 
			{
				cnt1++; u = l1; last = 1;
			}
			else
			{
				if(l1 < l2) {cnt1++; last = 1;}
				else {cnt2++; last = 0;}
				u = min(l1, l2);
			}		
			if(u != -1) u++;
		}
		if(u == -1) continue;
		else if(cnt1 != cnt2) 
		{
			if(!((cnt1>cnt2)^last)) ans.pb(mp(max(cnt1, cnt2), i));
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for(int i = 0; i < ans.size(); i++)
	{
		cout << ans[i].fi << ' ' << ans[i].se << '\n';
	}
}