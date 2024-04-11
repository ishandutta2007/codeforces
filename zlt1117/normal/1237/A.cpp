//#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define sz(x) (int)(x.size())
#define ll long long
#define rd (rand()<<16^rand())
#define PII pair<int,int>
#define gc getchar()//(p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
#define pb push_back
char buf[100000],*p1=buf,*p2=buf;
using namespace std;
inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}
inline int gi()
{
	int x=0,f=1;char ch=gc;
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc;}
	return (f==1)?x:-x;
}
const int maxn=20005;
int n,cnt;
int a[maxn];
inline void init()
{

}
inline void input()
{
	n=gi();
	FOR(i,1,n)a[i]=gi();
	FOR(i,1,n)if(a[i]%2!=0)cnt++;
}
inline void solve()
{
	cnt/=2;
	FOR(i,1,n)
	{
		if(a[i]%2==0)printf("%d\n",a[i]/2);
		else if(cnt)printf("%d\n",(a[i]+1)/2),cnt--;
		else printf("%d\n",(a[i]-1)/2);
	}
}
int main()
{
	init();
	input();
	solve();
	return 0;
}