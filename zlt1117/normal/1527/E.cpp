#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define gc getchar()
//#define gc (_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
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
const int maxn=35005;
int l=1,r=0;
int pre[maxn],nxt[maxn];
ll dp[2][maxn];
int n,k,a[maxn];
inline void init()
{

}
set<int>S[maxn];
set<int>cur[maxn];
inline void input()
{
	n=gi(),k=gi();
	FOR(i,1,n)a[i]=gi(),S[a[i]].insert(i);
	FOR(i,1,n)
	{
		pre[i]=nxt[i]=-1;
		auto it=S[a[i]].upper_bound(i);
		if(it!=S[a[i]].end())nxt[i]=*it;
		it=S[a[i]].lower_bound(i);
		if(it!=S[a[i]].begin())it--,pre[i]=*it;
	}
}
int now,last;
ll sum;
inline void add1(int x)
{
	if(nxt[x]<=r&&nxt[x]!=-1)sum+=nxt[x]-x;
}
inline void add2(int x)
{
	if(pre[x]>=l&&pre[x]!=-1)sum+=x-pre[x];
}
inline void del1(int x)
{
	if(nxt[x]<=r&&nxt[x]!=-1)sum-=nxt[x]-x;
}
inline void del2(int x)
{
	if(pre[x]>=l&&pre[x]!=-1)sum-=x-pre[x];
}
inline ll calc(int i,int j)
{
	if(i==j)return 0;
	while(l>i)add1(--l);
	while(r<j)add2(++r);
	while(l<i)del1(l++);
	while(r>j)del2(r--);
	return sum;
}
inline void Divide(int l,int r,int L,int R)
{
	if(l>r||L>R)return ;
	int mid=(l+r)>>1;
	pair<ll,ll>best={1e18,1e18};
	FOR(i,L,min(R,mid))
	{
		ll now=calc(i+1,mid)+dp[last][i];
		best=min({now,i},best);	
	}
	//cerr<<best.second<<endl;
	dp[now][mid]=best.first;
	Divide(l,mid-1,L,best.second);
	Divide(mid+1,r,best.second,R);
}
inline void solve()
{
	memset(dp[now],0x3f,sizeof(dp[now]));dp[now][0]=0;
	FOR(i,1,k)
	{
		now^=1,last=now^1;
		memset(dp[now],0x3f,sizeof(dp[now]));
		Divide(0,n,0,n);
	}
	printf("%lld\n",dp[now][n]);
}
int main()
{
	init();
	input();
	solve();
	return 0;
}