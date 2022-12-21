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
const int maxn=4e5+5;
int n;
int a[maxn],b[maxn],g[maxn],pre[maxn],suf[maxn],c[maxn];
inline void input()
{
	n=gi();
	FOR(i,1,n)
	{
		a[i]=gi(),b[i]=gi();
		if(a[i]<=n&&b[i]<=n){puts("-1");exit(0);}
		if(a[i]>b[i])swap(a[i],b[i]),c[a[i]]=1;g[a[i]]=b[i]; 
	}
}
vector<int>v1,v2;
int cost1,cost2,ans;
inline void solve()
{
	pre[0]=1e9;
	FOR(i,1,n)pre[i]=min(pre[i-1],g[i]);
	for(int i=n;i>=1;--i)suf[i]=max(suf[i+1],g[i]);
	//FOR(i,1,n)printf("g[%d]=%d\n",i,g[i]);
	FOR(i,1,n)
	{
		if(v1.empty()||g[i]<v1.back())v1.pb(g[i]),cost1+=c[i];
		else if(v2.empty()||g[i]<v2.back())v2.pb(g[i]),cost2+=c[i];
		else {puts("-1");return ;}
		if(pre[i]>suf[i+1])
		{
			ans+=min(cost1+sz(v2)-cost2,cost2+sz(v1)-cost1);
			v1.clear(),v2.clear();cost1=cost2=0;
		}
	}
	printf("%d\n",ans);
}
int main()
{
	input();
	solve();
	return 0;
}