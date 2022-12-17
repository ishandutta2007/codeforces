#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define rd (rand()<<16^rand())
#define PII pair<int,int>
#define pb push_back
#define sz(x) (int)(x.size())
#define gc (_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
using namespace std;
char _buf[100000],*_p1=_buf,*_p2=_buf;
inline int gi()
{
    int x=0,f=1;char ch=gc;
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc;}
    return (f==1)?x:-x;
}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=105;
int n,k1,k2,a[maxn],b[maxn],v1=0,v2=0;
inline void init()
{
	v1=v2=0;
}
inline void input()
{
	n=gi(),k1=gi(),k2=gi();
	FOR(i,1,k1)a[i]=gi(),v1=max(v1,a[i]);
	FOR(i,1,k2)b[i]=gi(),v2=max(v2,b[i]);
}
inline void solve()
{
	if(v1<v2)printf("NO\n");
	else printf("YES\n");
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