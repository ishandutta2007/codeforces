//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define iter set<int>::iterator
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
const int maxn=1e5+5,maxv=1e5;
const ll inf=1e18;
ll dp[20][maxn],T,phi[maxn],pre[maxn];
bool vis[maxn];
vector<int>pri;
int n,k;
vector<int>factor[maxn];
inline void seive(int n)
{
	vis[0]=vis[1]=1;phi[1]=1;
	FOR(i,2,n)
	{
		if(!vis[i])pri.pb(i),phi[i]=i-1;
		for(int x:pri)
		{
			if(x*i>n)break;
			vis[i*x]=1;
			if(i%x)phi[i*x]=phi[i]*phi[x];
			else {phi[i*x]=phi[i]*x;break;}
		}
	}
	FOR(i,1,n)for(int j=i;j<=n;j+=i)factor[j].pb(i);
	FOR(i,1,n)pre[i]=pre[i-1]+phi[i];
}
inline void input()
{
	T=gi();
	seive(100000);
}
int now;
int nowl=1,nowr=0;
ll value=0;
inline ll costl(){return pre[nowr/nowl];}
inline ll costr()
{
	ll ret=0;
	for(int x:factor[nowr])if(x>=nowl)ret+=phi[nowr/x];///at most 1 once
	return ret;
}
inline ll cost(int l,int r)
{
	while(nowl>l)--nowl,value+=costl();
	while(nowr<r)++nowr,value+=costr();
	while(nowl<l)value-=costl(),nowl++;
	while(nowr>r)value-=costr(),nowr--;
	return value;
}
inline void work(int l,int r,int L,int R)
{
	if(l>r||L>R)return ;
	pair<ll,ll>best={inf,0};
	int mid=(l+r)>>1;
	FOR(i,L,min(R,mid))
	{
		ll val=dp[now-1][i]+cost(i+1,mid);
		best=min(best,{val,i});
	}
	dp[now][mid]=best.first;
	work(l,mid-1,L,best.second);
	work(mid+1,r,best.second,R);
}
inline void solve()
{
	///solve
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	FOR(i,1,19)now=i,work(1,maxv,0,maxv);
	///answer
	while(T--)
	{
		n=gi(),k=gi();
		if(k>=20)printf("%d\n",n);
		else printf("%lld\n",dp[k][n]);
	}
}
int main()
{
	input();
	solve();
	return 0;
}