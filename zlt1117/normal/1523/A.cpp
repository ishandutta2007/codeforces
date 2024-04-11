#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define db double
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
const int maxn=1e3+5;
int n,m,a[maxn],b[maxn];
char s[maxn];
inline void init()
{
	FOR(i,1,n)a[i]=b[i]=0;
}
inline void input()
{
	n=gi(),m=gi();
	scanf("%s",s+1);
	FOR(i,1,n)a[i]=s[i]-'0';
}
inline void solve()
{
	int cnt=0;
	FOR(i,1,n)cnt+=a[i];
	FOR(i,1,m)
	{
		FOR(j,1,n)b[j]=a[j];
		int cur=cnt;cnt=0;
		FOR(j,1,n)if(a[j]||(b[j-1]+b[j+1]==1))a[j]=1,cnt++;
		if(cnt==cur)break;
	}
	FOR(i,1,n)printf("%d",a[i]);
	puts("");
}
int main()
{
	int T=1;
	T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}