#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define sz(x) (int)(x.size())
#define PII pair<int,int>
#define pb push_back
#define gc getchar()//(p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
using namespace std; 
char buf[100000],*p1=buf,*p2=buf;
inline int gi()
{
	int x=0,f=1;char ch=gc;
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48),ch=gc;}
	return (f==1)?x:-x;
}
const int maxn=5e4+5,mod=1e9+7;
ll n,a[maxn],M=30;
ll k;
struct Trie
{
	int son[maxn*32][2],siz[maxn*32],cnt[maxn*32][31],tot;
	inline void insert(int &u,int step,int x)
	{
		++tot;
		siz[tot]=siz[u],son[tot][0]=son[u][0],son[tot][1]=son[u][1];
		siz[tot]++;
		FOR(j,0,step)cnt[tot][j]=cnt[u][j];u=tot;
		if(step==-1)return ;
		insert(son[u][x>>step&1],step-1,x);
		FOR(j,0,step)if(x>>j&1)cnt[u][j]++;
	}
	inline ll query(int u,int step,int x,int d)///(\leq)
	{
		if(!u)return 0;
		if(step==-1)return siz[u];
		if(!(d>>step&1))return query(son[u][x>>step&1],step-1,x,d)+siz[son[u][(x>>step&1)^1]];
		else return query(son[u][(x>>step&1)^1],step-1,x,d);
	}
	inline ll qsum(int u,int step,int x,int d,int ext)
	{
		if(!u)return 0;
		if(step==-1)return 1ll*ext*siz[u]%mod;
		if(!(d>>step&1))
		{
			ll ret=siz[son[u][(x>>step&1)^1]]*((1LL<<step)+ext);
			FOR(j,0,step-1)
			{
				if(x>>j&1)ret+=1ll*(siz[son[u][(x>>step&1)^1]]-cnt[son[u][(x>>step&1)^1]][j])*(1LL<<j)%mod;
				else ret+=1ll*cnt[son[u][(x>>step&1)^1]][j]*(1LL<<j)%mod;
				ret%=mod;
			}
			return (qsum(son[u][x>>step&1],step-1,x,d,ext)+ret)%mod;
		}
		else return qsum(son[u][(x>>step&1)^1],step-1,x,d,ext+(1<<step))%mod;
	}
}trie;
int rt[maxn];
inline void init()
{
	
}
inline void input()
{
	n=gi();scanf("%lld",&k);
	FOR(i,1,n)a[i]=gi();
}
inline ll count(int mid)
{
	ll now=0;
	FOR(i,1,n)now+=trie.query(rt[i-1],M,a[i],mid);
	return now;
}
ll maxv=2e9;//2e9
inline void solve()
{
	FOR(i,1,n)
	{
		rt[i]=rt[i-1];
		trie.insert(rt[i],M,a[i]);
	}
	ll l=0,r=maxv,ans=0;///find the max value that it appears < k
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		if(count(mid)<=k)ans=mid,r=mid-1;
		else l=mid+1;
	}
	ll nans=0;
	FOR(i,1,n)nans+=trie.qsum(rt[i-1],M,a[i],ans,0),nans%=mod;
	ll res=k-count(ans);
	l=0,r=maxv,ans=0;
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		if(count(mid)>k)ans=mid,l=mid+1;
		else r=mid-1;
	}
	nans+=1ll*ans%mod*res%mod;
	printf("%lld\n",nans%mod);
}
int main()
{
	init();
	input();
	solve();
	return 0;
}
/*
3 3
5 7 8
*/