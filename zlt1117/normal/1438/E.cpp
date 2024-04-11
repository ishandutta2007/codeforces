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
const int maxn=2e5+5;
set<PII>s;
int n,a[maxn],ans;
inline void init()
{

}
inline void input()
{
	n=gi();
	FOR(i,1,n)a[i]=gi();
}
inline void solve()
{
	FOR(i,1,n)
	{
		int sum=0;
		FOR(j,i+2,n)
		{
			sum+=a[j-1];
			if(sum==(a[i]^a[j]))ans++,s.insert(PII(i,j));
			if(sum>a[i]*2)break;
		}
	}
	reverse(a+1,a+n+1);
	FOR(i,1,n)
	{
		int sum=0;
		FOR(j,i+2,n)
		{
			sum+=a[j-1];
			if(sum==(a[i]^a[j]))if(!s.count(PII(n-j+1,n-i+1)))ans++;
			if(sum>a[i]*2)break;
		}
	}
	printf("%d\n",ans);
}
int main()
{
	init();
	input();
	solve();
	return 0;
}///