//#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define rd (rand()<<16^rand())
#define PII pair<int,int>
#define gc getchar()//(_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
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
int T,n,x,y,d; 
inline void init()
{

}
inline void input()
{
	n=gi(),x=gi(),y=gi(),d=gi();
	int ans=2e9+1;
	if(abs(y-x)%d==0)ans=min(ans,abs(y-x)/d);
	if((y-1)%d==0)ans=min(ans,(y-1)/d+(x-1)/d+(int)((x-1)%d!=0));
	if((n-y)%d==0)ans=min(ans,(n-y)/d+(n-x)/d+(int)((n-x)%d!=0));
	if(ans<=2e9)printf("%d\n",ans);
	else printf("-1\n");
}
inline void solve()
{

}
int main()
{
	T=gi();
	while(T--)
	{
		input();
		init();
		solve();
	}
	return 0;
}