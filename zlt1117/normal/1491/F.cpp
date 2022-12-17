#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define PLL pair<ll,ll>
#define fi first
#define A(x) ((x)%mod)
#define se second
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define gc getchar()//(_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
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
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=2005;
int n;
int vis[maxn];
char s[maxn];
inline void init()
{
	FOR(i,1,n)vis[i]=0;
}
inline void input()
{
	n=gi();
//	scanf("%s",s+1);
}
inline int query(vector<int>&l,vector<int>&r)
{
	printf("? %d %d\n",sz(l),sz(r));
	for(auto x:l)printf("%d ",x);
	printf("\n");
	for(auto x:r)printf("%d ",x);
	printf("\n");
	fflush(stdout);
	int ret=0;
	ret=gi();
//	int cntl1=0,cntr1=0,cntl2=0,cntr2=0;
//	for(auto x:l)
//	{
//		if(s[x]=='N')cntl1++;
//		else if(s[x]=='S')cntl2++;
//	}
//	for(auto x:r)
//	{
//		if(s[x]=='N')cntr1++;
//		else if(s[x]=='S')cntr2++;
//	}
//	ret=cntl1*cntr1+cntl2*cntr2-cntl1*cntr2-cntl2*cntr1;
	return ret;
}
inline int erfen(int l,int r)
{
	int tt=r+1,ans=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		vector<int>x,y;
		FOR(i,l,mid)x.pb(i);
		y.pb(tt);
		int ret=query(x,y);
		if(ret==0)l=mid+1;
		else ans=mid,r=mid-1;
	}
	return ans;
}
inline void solve()
{
	int now=2;
	while(now<=n)
	{
		vector<int>l,r;
		FOR(i,1,now-1)l.pb(i);
		r.pb(now);
		int x=query(l,r);
		if(x!=0)
		{
			vis[now]=1;
			vis[erfen(1,now-1)]=1;
			break;
		}
		now++;
	}
	FOR(i,now+1,n)
	{
		vector<int>l,r;
		l.pb(now),r.pb(i);
		int x=query(l,r);
		if(x!=0)vis[i]=1;
	}
	int cnt=0;
	FOR(i,1,n)cnt+=!vis[i];
	printf("! %d ",cnt);
	FOR(i,1,n)if(!vis[i])printf("%d ",i);
	printf("\n");
	fflush(stdout);
}
int main()
{
	int T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}