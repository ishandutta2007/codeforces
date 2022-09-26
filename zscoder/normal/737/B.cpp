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

int n, a,b,k;
string s;
vector<ii> range;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n>>a>>b>>k;
	cin>>s;
	s += '1';
	int zl = 0;
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] == '1')
		{
			if(zl!=-1&&zl<=i-1) range.pb(mp(zl,i-1));
			zl = -1;
		}
		else
		{
			if(zl==-1) zl = i;
		}
	}
	int cnt = 0;
	for(int i = 0; i < range.size(); i++)
	{
		int l = range[i].fi; int r = range[i].se;
		//cerr<<l<<' '<<r<<'\n';
		int blocks = (r - l + 1)/b;
		cnt+=blocks;
	}
	int destroy = cnt - a + 1;
	cout<<destroy<<'\n';
	for(int i = 0; i < range.size(); i++)
	{
		int l = range[i].fi; int r = range[i].se;
		int blocks = (r - l + 1)/b;
		if(blocks == 0) continue;
		for(int j = l + b - 1; j <= r; j += b)
		{
			if(destroy>0)
			{
				destroy--;
				cout<<j+1<<' ';
			}
		}
	}
}