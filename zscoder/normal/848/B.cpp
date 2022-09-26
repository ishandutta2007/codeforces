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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

const int C = 120000;

vector<ii> hori[250001];
vector<ii> vert[250001];
deque<int> ve[250001];

ii en[200001];
int ans[200001];
int as[200001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,w,h; cin>>n>>w>>h;
	vector<pair<int,pair<int,int> > > V;
	for(int i=0;i<n;i++)
	{
		int type; ll x,t;
		cin>>type>>x>>t;
		if(type==1)
		{
			en[i]=mp(x,h);
			vert[x-t+C].pb(mp(x,i));
		}
		else
		{
			en[i]=mp(w,x);
			hori[x-t+C].pb(mp(x,i));
			V.pb(mp(x,mp(x-t+C,i)));
		}
	}
	for(int i=0;i<n;i++) ans[i]=i;
	for(int i=0;i<=250000;i++)
	{
		sort(vert[i].begin(),vert[i].end());
		sort(hori[i].begin(),hori[i].end());
		for(int j=0;j<vert[i].size();j++)
		{
			ve[i].pb(vert[i][j].se);
		}
	}
	/*
		if(vert[i].empty()||hori[i].empty()) continue;
		for(int j=0;j<vert[i].size();j++)
		{
			if(j==0)
			{
				ans[hori[i].back().se]=vert[i][j].se;
			}
			else
			{
				ans[vert[i][j-1].se]=vert[i][j].se;
			}
		}
		for(int j=0;j<hori[i].size();j++)
		{
			if(j==0)
			{
				ans[vert[i].back().se]=hori[i][j].se;
			}
			else
			{
				ans[hori[i][j-1].se]=hori[i][j].se;
			}
		}
	}
	*/
	sort(V.begin(),V.end());
	for(int i = 0; i < V.size();i++)
	{
		int T = V[i].se.fi;
		int idx = V[i].se.se;
		if(ve[T].empty()) continue;
		ans[idx]=ve[T].back();
		ve[T].pop_back();
		ve[T].push_front(idx);
	}
	for(int i=0;i<=250000;i++)
	{
		for(int j=0;j<ve[i].size();j++)
		{
			ans[vert[i][j].se]=ve[i][j];
		}
	}
	for(int i = 0; i < n; i++)
	{
		as[ans[i]]=i;
	}
	for(int i=0;i<n;i++)
	{
		cout<<en[as[i]].fi<<' '<<en[as[i]].se<<'\n';
	}
}