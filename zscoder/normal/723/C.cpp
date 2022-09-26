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

vector<int> vec;
map<int, vi> ma;
map<int, vi> ma2;
int cnt = 0;
int n, m; 

void rep(int a, int b)
{
	int z = ma[a].back();
	ma2[a].pop_back();
	ma2[b].pb(z);
	if(ma2[a].empty()) ma2.erase(a);
	cnt++;
}

void replace(int a, int b) //- a + b
{
	int z = ma[a].back();
	ma[a].pop_back();
	ma[b].pb(z);
	if(ma[a].empty()) ma.erase(a);
	cnt++;
}

void refresh()
{
	for(map<int,vi>::iterator it = ma.begin(); it != ma.end(); it++)
	{
		vi tmp = (*it).se;
		for(int i = 0; i < tmp.size(); i++)
		{
			vec[tmp[i]] = (*it).fi;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	vec.resize(n);
	for(int i = 0; i < n; i++) 
	{
		cin >> vec[i];
		ma[vec[i]].pb(i);
	}
	int lo = 0; int hi = 2001;
	int ans = -1;
	while(lo <= hi)
	{
		int mid = (lo+hi)>>1;
		//ma2 = ma;
		int c1 = 0; int need = 0; int ext = 0;
		for(int i = 1; i <= m; i++)
		{
			c1 += ma[i].size();
			need += max(0, mid - int(ma[i].size()));
			ext += max(0, int(ma[i].size()) - mid);
		}
		c1 = n - c1;
		//cerr << mid << ' ' << need << ' ' << ext << ' ' << c1 << '\n';
		if(ext + c1 >= need)
		{
			ans = mid;
			lo = mid + 1;
		}
		else
		{
			hi = mid - 1;
		}
	}
	vector<int> v2;
	for(int i = 0; i < n; i++)
	{
		if(vec[i] > m) v2.pb(vec[i]);
	}
	for(int i = 1; i <= m; i++)
	{
		int ext = max(0, int(ma[i].size()) - ans);
		for(int j = 0; j < ext; j++)
		{
			v2.pb(i);
		}
	}
	for(int i = 1; i <= m; i++)
	{
		while(ma[i].size() < ans)
		{
			replace(v2.back(), i);
			v2.pop_back();
		}
	}
	refresh();
	cout << ans << ' ' << cnt << '\n';
	for(int i = 0; i < n; i++)
	{
		cout << vec[i] << ' ';
	}
}