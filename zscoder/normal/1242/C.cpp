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
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

set<ll> S[22];
map<ll,int> ma;
ll sum[22];
int dp[(1<<15)+10];
ll avg;
map<ll,vector<ii> > vv;
map<ll,int> B;

bool provoke(int x, vector<ii> &ops, int keep, int bit=0) //x = current removed number, bit = set of bits we removed stuff from, 
{
	int id = ma[x];
	ll newsum = sum[id]-x;
	ll reqnumber = avg-newsum;
	if(ma.find(reqnumber)==ma.end()) return false;
	if(reqnumber==keep)
	{
		ops.pb({keep,id});
		return true;
	}
	int newid = ma[reqnumber];
	if(bit&(1<<newid))
	{
		return false;
	}
	ops.pb({reqnumber,id}); //newid -> id
	bit|=(1<<newid);
	return provoke(reqnumber,ops,keep,bit);
}
int n; 
vector<ii> sol[(1<<16)+1];

int solve(int bit)
{
	if(dp[bit]!=-1)
	{
		return (dp[bit]);
	}
	for(int i=0;i<n;i++)
	{
		if(bit&(1<<i))
		{
			for(auto x:S[i])
			{
				if(B.find(x)==B.end()) continue;
				int usedbit = B[x];
				if((bit&usedbit)==usedbit)
				{
					if(solve(bit^usedbit))
					{
						dp[bit]=1;
						sol[bit]=sol[bit^usedbit];
						for(auto y:vv[x])
						{
							sol[bit].pb(y);
						}
						return (dp[bit]=1);
					}
				}
			}
			return (dp[bit]=0);
		}
	}
	return (dp[bit]=1);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll total=0;
	cin>>n;
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;i++)
	{
		int siz; cin>>siz;
		for(int j=0;j<siz;j++)
		{
			ll x; cin>>x; ma[x]=i;
			S[i].insert(x);
			total+=x;
			sum[i]+=x;
		}
	}
	if(abs(total)%n!=0)
	{
		cout<<"No\n"; return 0;
	}
	avg = total/n;
	for(int i=0;i<n;i++)
	{
		for(int x:S[i])
		{
			int bb=(1<<ma[x]);
			bool tmp = provoke(x,vv[x],x,bb);
			if(tmp==0)
			{
				vv.erase(x);
			}
			else
			{
				for(auto X:vv[x])
				{
					B[x]|=(1<<X.se);
				}
			}
		}
	}
	solve((1<<n)-1);
	if(dp[(1<<n)-1])
	{
		cout<<"Yes\n";
		vector<ii> P(n);
		for(auto x:sol[(1<<n)-1])
		{
			P[ma[x.fi]]=x;
		}
		for(ii x:P)
		{
			cout<<x.fi<<' '<<x.se+1<<'\n';
		}
	}
	else
	{
		cout<<"No\n";
	}
}