//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define db double
#define gc getchar()
#define mk make_pair
#define iter set<int>::iterator
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
const int maxn=3e5+5,M=3e5;
int a[maxn],n;
int cnt[maxn];
inline void init()
{

}
inline void input()
{
	n=gi();
	FOR(i,1,n)a[i]=gi();
}
int bel[maxn];
struct BIT
{
	ll pre1[maxn],pre2[maxn];
	inline void update(int x,int v)
	{
		int y=x;
		while(bel[y]==bel[x])pre1[y++]+=v;
		for(int i=bel[x];i<=bel[M];++i)pre2[i]+=v;
	}
	inline ll query(int x)
	{
		if(x<=0)return 0;
		ll ret=pre2[bel[x]-1]+pre1[x];
		return ret;
	}
}T1,T2;
ll ans[maxn];
bool vis[maxn];
inline void solve()
{
	int block=600;
	FOR(i,1,M)bel[i]=(i-1)/block+1;
	FOR(i,1,n)
	{
		ans[i]+=T2.query(a[i]-1);
		int now=a[i]-1,cnt=0;
		while(now<M)
		{
			int last=now;cnt++;
			now=min(M,now+a[i]);
			ans[i]+=T2.query(now)-T2.query(last);
			ans[i]-=1ll*cnt*(T1.query(now)-T1.query(last))*a[i];
		}
		//printf("ans[%d]=%lld\n",i,ans[i]);
		ans[i]+=1ll*(i-1-T1.query(a[i]))*a[i];
		for(int l=1;l<=a[i];)
		{
			int r=a[i]/(a[i]/l),res=a[i]/l;
			ans[i]+=(T1.query(r)-T1.query(l-1))*a[i];
			ans[i]-=(T2.query(r)-T2.query(l-1))*res;
			l=r+1;
		}
		//printf("ans[%d]=%lld\n",i,ans[i]);
		T1.update(a[i],1);
		T2.update(a[i],a[i]);
	}
	FOR(i,1,n)ans[i]+=ans[i-1],printf("%lld%c",ans[i]," \n"[i==n]);
}
int main()
{
	int T=1;
	//T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}