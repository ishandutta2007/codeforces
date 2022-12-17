#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define sz(x) (int)(x.size())
#define pb push_back
#define PII pair<int,int>
#define ll long long
#define gc getchar()
//#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
using namespace std;
char buf[100000],*p1=buf,*p2=buf;
inline int gi()
{
	int x=0,f=1;char ch=gc;
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc;}
	return (f==1)?x:-x;
}
const int maxn=605;
int n,m,mod;
inline int qpow(int x,int k)
{
	int ret=1;
	while(k)
	{
		if(k&1)ret=1ll*x*ret%mod;
		x=1ll*x*x%mod,k>>=1;
	}
	return ret;
}
vector<int>a[maxn];
inline int det(vector<int>*a,int n)
{
	int ans=1;
	FOR(i,1,n)
	{
		int p=i;
		FOR(j,i,n)if(a[j][i]!=0){p=j;break;}
		if(p!=i)swap(a[p],a[i]),ans=(mod-ans)%mod;
		if(a[i][i]==0)return 0;
		int inv=qpow(a[i][i],mod-2);
		ans=1ll*ans*a[i][i]%mod;
		FOR(j,i,n)a[i][j]=1ll*a[i][j]*inv%mod;
		FOR(j,i+1,n)
		{
			int v=a[j][i];
			FOR(k,i,n)a[j][k]=(a[j][k]-1ll*v*a[i][k]%mod+mod)%mod;
		}
	}
	return ans;
}
int id[maxn],cnt[maxn],cnt2[maxn],id2[maxn];
vector<int>e[maxn];
int c;
inline void input()
{
	n=gi(),m=gi(),mod=gi();
	FOR(i,1,n)a[i].resize(n+1);
	FOR(i,1,m)
	{
		int u=gi(),v=gi();
		e[u].pb(v);
		cnt[u]++;cnt2[v]++;
	}
	int c1=0,c2=0;
	FOR(i,1,n)if(!cnt2[i])id[i]=++c1,c++;
	FOR(i,1,n)if(!cnt[i])id2[i]=++c2;
}
int t[maxn],dp[maxn];
inline void solve()
{
	///topusort
	FOR(i,1,n)a[i].resize(n+1);
	FOR(i,1,n)
	{
		if(!cnt2[i])
		{
			queue<int>q;
			FOR(j,1,n)t[j]=cnt2[j];
			FOR(j,1,n)if(!t[j])q.push(j);
			memset(dp,0,sizeof(dp));
			dp[i]=1;
			while(!q.empty())
			{
				int u=q.front();
				q.pop();
				for(int v:e[u])
				{
					dp[v]=(dp[v]+dp[u])%mod;
					t[v]--;
					if(t[v]==0)q.push(v);
				}
			}
			FOR(j,1,n)if(!cnt[j])a[id[i]][id2[j]]=dp[j];
		}
	}
	printf("%d\n",det(a,c));
}
int main()
{
	input();
	solve();
	return 0;
}