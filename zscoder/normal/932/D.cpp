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

int st[20][411111];
int tot;
ll sum[20][411111];
int par[20][411111];
ll rmq[20][411111];
ll v[411111];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(st,-1,sizeof(st)); memset(par,-1,sizeof(par)); memset(rmq,-1,sizeof(rmq));
	int q; cin>>q;
	ll last =0;
	int mx = 0;
	for(int z=0;z<q;z++)
	{
		int t; ll a,b; cin>>t>>a>>b; a^=last; b^=last; a--;
		if(t==1)
		{
			v[++mx] = b;
			//add(++mx, b);
			par[0][mx] = a;
			for(int i = 1; i < 20; i++)
			{
				if(par[i-1][mx]==-1) par[i][mx]=par[i-1][mx];
				else par[i][mx] = par[i-1][par[i-1][mx]];
			}
			rmq[0][mx] = v[a];
			for(int i = 1; i < 20; i++)
			{
				rmq[i][mx] = rmq[i-1][mx];
				if(par[i-1][mx]!=-1) rmq[i][mx] = max(rmq[i][mx], rmq[i-1][par[i-1][mx]]);
			}
			int cur = mx;
			for(int j = 19; j >= 0; j--)
			{
				if(cur==-1) break;
				if(rmq[j][cur]>=b)
				{
					
				}
				else
				{
					cur = par[j][cur];
				}
			}
			st[0][mx] = (cur==-1?-1:par[0][cur]);
			for(int i=1;i<20;i++)
			{
				if(st[i-1][mx]==-1) st[i][mx]=-1;
				else st[i][mx]=st[i-1][st[i-1][mx]];
			}
			sum[0][mx]=0;
			if(st[0][mx]!=-1) sum[0][mx]+=v[st[0][mx]];
			for(int i=1;i<20;i++)
			{
				sum[i][mx]=sum[i-1][mx];
				if(st[i-1][mx]!=-1) sum[i][mx]+=sum[i-1][st[i-1][mx]];
			}
		}
		else
		{
			ll cur = v[a];
			if(cur>b)
			{
				cout<<0<<'\n';
				last=0; continue;
			}
			int len = 1;
			for(int i=19;i>=0;i--)
			{
				if(st[i][a]==-1) continue;
				if(cur+sum[i][a]<=b)
				{
					cur+=sum[i][a];
					len+=(1<<i);
					a = st[i][a];
				}
			}
			cout<<len<<'\n';
			last=len;
		}
	}
}