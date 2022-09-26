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
typedef long double ld; 
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

map<string,int> ma;
vector<ii> vec;
int cost[611][611];
vector<int> tickets;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,a,b,k,f;
	cin>>n>>a>>b>>k>>f;
	int ct=0;
	for(int i=0;i<n;i++)
	{
		string u1,u2;
		cin>>u1>>u2;
		assert(u1!=u2);
		if(ma.find(u1)==ma.end())
		{
			ma[u1]=ct++;
		}
		if(ma.find(u2)==ma.end())
		{
			ma[u2]=ct++;
		}
		vec.pb(mp(ma[u1],ma[u2]));
	}
	for(int i=0;i<vec.size();i++)
	{
		if(i>0&&vec[i].fi==vec[i-1].se)
		{
			cost[vec[i].fi][vec[i].se]+=b;
		}
		else
		{
			cost[vec[i].fi][vec[i].se]+=a;
		}
	}
	for(int i=0;i<610;i++)
	{
		for(int j=i+1;j<610;j++)
		{
			tickets.pb(cost[i][j]+cost[j][i]);
		}
	}
	sort(tickets.rbegin(),tickets.rend());
	int ans=0;
	for(int i=0;i<tickets.size();i++)
	{
		if(i<k)
		{
			ans+=min(f,tickets[i]);
		}
		else
		{
			ans+=tickets[i];
		}
	}
	cout<<ans<<'\n';
}