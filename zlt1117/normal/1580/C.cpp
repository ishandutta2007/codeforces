#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define mk make_pair
#define gc (_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
using namespace std;
char _buf[100000],*_p1=_buf,*_p2=_buf;
inline int gi()
{
	int x=0,f=1;
	char ch=gc;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=gc;
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=gc;
	}
	return (f==1)?x:-x;
}
constexpr int maxn=200'005,B=450;
int a[maxn],b[maxn],opt[maxn],k[maxn],n,m;
bool vis[maxn];
inline void input()
{
	n=gi(),m=gi();
	FOR(i,1,n)a[i]=gi(),b[i]=gi();
	FOR(i,1,m)opt[i]=gi(),k[i]=gi();
	FOR(i,1,n)if(a[i]+b[i]<=B)vis[a[i]+b[i]]=1;
}
struct Block
{
	int val[maxn],sum[maxn],bel[maxn],posl[maxn],posr[maxn],tot;
	inline void init(int n)
	{
		while(posr[tot]<n)
		{
			++tot;
			posl[tot]=posr[tot-1]+1;
			posr[tot]=posl[tot]+B-1;
		}
		FOR(i,1,n)bel[i]=(i-1)/B+1;
	}
	inline void add(int x,int v)
	{
		val[x]+=v;
		sum[bel[x]]+=v;
	}
	inline int query(int x)
	{
		int ret=0;
		FOR(i,1,bel[x]-1)ret+=sum[i];
		FOR(i,posl[bel[x]],x)ret+=val[i];
		return ret;
	}
}block;
int ans[maxn],now[maxn],tim[maxn];
inline void count(int x)
{
	FOR(i,0,x)now[i]=0;
	FOR(i,1,m)
	{
		if(a[k[i]]+b[k[i]]!=x){ans[i]+=now[i%x];continue;}
		if(opt[i]==2)
		{
			int edt=(tim[k[i]]-1)%x,st=(tim[k[i]]+a[k[i]])%x;
			if(st<=edt)FOR(i,st,edt)now[i]--;
			else 
			{
				FOR(i,0,edt)now[i]--;
				FOR(i,st,x-1)now[i]--;
			}
		}
		else
		{
			tim[k[i]]=i;
			int edt=(tim[k[i]]-1)%x,st=(tim[k[i]]+a[k[i]])%x;
			if(st<=edt)FOR(i,st,edt)now[i]++;
			else 
			{
				FOR(i,0,edt)now[i]++;
				FOR(i,st,x-1)now[i]++;
			}
		}
		ans[i]+=now[i%x];
	}
}
inline void solve()
{
	block.init(m);
	FOR(i,1,B)if(vis[i])count(i);
	FOR(i,1,m)
	{
		if(a[k[i]]+b[k[i]]<=B){ans[i]+=block.query(i);continue;}
		if(opt[i]==1)tim[k[i]]=i;
		int t=tim[k[i]]+a[k[i]];
		while(t<=m)
		{
			int edt=t+b[k[i]]-1;
			edt=min(edt,m);
			int v=opt[i]==1?1:-1;
			block.add(t,v);
			block.add(edt+1,-v);
			t+=a[k[i]]+b[k[i]];
		}
		ans[i]+=block.query(i);
	}
	FOR(i,1,m)printf("%d\n",ans[i]);
}
int main()
{
	input();
	solve();
	return 0;
}