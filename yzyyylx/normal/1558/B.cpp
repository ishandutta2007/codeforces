#include<bits/stdc++.h>
#define ll long long
#define db double
#define PP pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
#define MN 4000000
#define N 4001000
using namespace std;

ll T,n,M,dp[N],zz,sum,qz;
int zs[N],mn[N],pos[N];
bool P[N];
vector<PP>have;

inline void Add(ll &u,ll v){u=(u+v)%M;}
inline void get()
{
	ll i,j;
	for(i=2; i<=MN; i++)
	{
		if(!P[i])
		{
			zz++;
			zs[zz]=mn[i]=i;
		}
		for(j=1; j<=zz&&i*zs[j]<=MN; j++)
		{
			P[i*zs[j]]=1;
			mn[i*zs[j]]=zs[j];
			if(i%zs[j]==0) break;
		}
	}
}

void dfs(ll now,ll ji)
{
	if(now==have.size())
	{
		if(ji==1) return;
		Add(sum,M-dp[pos[ji]]);
		Add(sum,dp[++pos[ji]]);
		return;
	}
	ll i,t=ji;
	for(i=0;i<=have[now].se;i++)
	{
		dfs(now+1,t);
		t*=have[now].fi;
	}
}

int main()
{
	get();
	ll i,j,k,t,p,q;
//	for(i=1;i<=10;i++) cout<<mn[i]<<" ";
	cin>>n>>M;
	dp[1]=qz=1,sum=0;
	for(i=2;i<=n;i++)
	{
//		cout<<i<<endl;
		have.clear();
		for(j=i;j!=1;)
		{
//			cout<<" "<<j<<" "<<mn[j]<<endl;
			p=mn[j],q=0;
			for(;j%p==0;j/=p) q++;
			have.push_back(mp(p,q));
		}
//		puts("OK");
		dfs(0,1);
		dp[i]=(qz+sum)%M;
		Add(qz,dp[i]);
	}
//	for(i=1;i<=n;i++) cout<<dp[i]<<" ";return 0;
	cout<<dp[n];
}