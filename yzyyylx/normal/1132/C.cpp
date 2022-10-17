#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define N 5010
#define M 
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

ll n,m,ans,sum,cnt[N][N],ct[N];
vector<ll>in[N],out[N];
set<ll>now;
set<ll>::iterator it;

int main()
{
	ll i,j,p,q;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&p,&q);
		in[p].push_back(i);
		out[q+1].push_back(i);
	}
	for(i=1;i<=n;i++)
	{
		for(j=0;j<in[i].size();j++) now.insert(in[i][j]);
		for(j=0;j<out[i].size();j++) now.erase(out[i][j]);
		if(!now.size()) sum++;
		if(now.size()==1) ct[*now.begin()]++;
		else if(now.size()==2)
		{
			it=now.begin(),p=(*it);
			it++,q=(*it);
			if(p>q) swap(p,q);
			cnt[p][q]++;
		}
	}
	for(i=1;i<=m;i++)
	{
		for(j=i+1;j<=m;j++)
		{
			ans=max(ans,n-ct[i]-ct[j]-cnt[i][j]-sum);
		}
	}
	cout<<ans;
}