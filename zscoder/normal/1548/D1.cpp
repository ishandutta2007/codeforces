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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

ii a[6666];

int gp(ii a, ii b)
{
	if((a.fi+b.fi)%2==0&&(a.se+b.se)%2==0) return 0;
	return 1;
	//return __gcd(a.fi-b.fi,a.se-b.se);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		int x,y; cin>>x>>y; x/=2; y/=2; a[i]={x,y};
	}
	ll ans=0;
	/*
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			for(int k=j+1;k<n;k++)
			{
				int s = gp(a[i],a[j])+gp(a[j],a[k])+gp(a[i],a[k]);
				if(s%2==0) ans++;
			}
		}
	}
	*/
	for(int i=0;i<n;i++)
	{
		//fix i
		vi S[2];
		for(int j=0;j<n;j++)
		{
			if(j==i) continue;
			S[gp(a[i],a[j])].pb(j);
		}
		for(int j=0;j<2;j++)
		{
			for(int k=j;k<2;k++)
			{
				ll cj[2][2] = {{0,0},{0,0}};
				ll ck[2][2] = {{0,0},{0,0}};
				for(auto x:S[j])
				{
					cj[(a[x].fi&1)][a[x].se&1]++;
				}
				for(auto x:S[k])
				{
					ck[(a[x].fi&1)][a[x].se&1]++;
				}
				ll res=0;
				//for each pair of sets
				//(j+k) = number of pairs
				ll total_pairs = ll(S[j].size())*ll(S[k].size());
				//pairs that sum up to 0
				ll zero_pairs = 0;
				for(int l=0;l<2;l++)
				{
					for(int m=0;m<2;m++)
					{
						zero_pairs+=cj[l][m]*ck[l][m];
					}
				}
				if((j+k)&1) res=total_pairs-zero_pairs;
				else res=zero_pairs;
				//cerr<<i<<' '<<j<<' '<<k<<": "<<res<<" ("<<S[j].size()<<") "<<'\n';
				//if j=k
				if(j==k)
				{
					res-=S[j].size();
					assert(res%2==0);
					res/=2; //ordered pairs -> unordered
				}
				ans+=res;
			}
		}
	}
	
	assert(ans%3==0); //three orientations
	cout<<ans/3<<'\n';
}