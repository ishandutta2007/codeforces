#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vector<ii> V;
void add(int u, int v)
{
	V.pb({u,v});
}

void out()
{
	for(int i=0;i<V.size();i++)
	{
		cout<<V[i].fi+1<<' '<<V[i].se+1<<'\n';
	}
}
int a[555555];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	vector<ii> vec;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		vec.pb({a[i],i});
	}
	sort(vec.rbegin(),vec.rend());
	int d = vec[0].fi;
	vi chain;
	chain.pb(2*vec[0].se);
	for(int i=0;i<d-1;i++)
	{
		chain.pb(2*vec[i+1].se);
	}
	chain.pb(2*vec[0].se + 1);
	for(int i=0;i+1<chain.size();i++) add(chain[i],chain[i+1]);
	for(int i=1;i<d;i++)
	{
		int cur = vec[i].se;
		int dist = vec[i].fi;
		//currently at chain[i], last = chain[d]
		int attach_to = i+dist-1;
		if(attach_to==int(chain.size())-1)
		{
			chain.pb(2*cur+1);
		}
		add(chain[attach_to],2*cur+1);
	}
	for(int i=d;i<n;i++)
	{
		int cur = vec[i].se;
		int dist = vec[i].fi;
		add(chain[0],2*cur);
		if(dist==1)
		{
			add(2*cur,2*cur+1);
		}
		else
		{
			add(chain[dist-2],2*cur+1);
		}
	}
	out();
}