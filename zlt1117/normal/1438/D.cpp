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
const int maxn=1e5+5;
int n,a[maxn],b[maxn],c[maxn],d[maxn],tot;
inline void init()
{

}
inline void input()
{
	n=gi();
	FOR(i,1,n)a[i]=gi();
}
inline void A(int i,int j,int k)
{
	a[i]=a[j]=a[k]=a[i]^a[j]^a[k];
	b[++tot]=i,c[tot]=j,d[tot]=k;
}
inline void output()
{
//	FOR(i,1,n)cerr<<a[i]<<' ';
//	cerr<<endl;
}
inline void solve()
{
	if(n%2==0)
	{
		int sum=0;
		FOR(i,1,n)sum^=a[i];
		if(sum!=0){printf("NO\n");return ;}
		else n--;
	}
	for(int i=1;i<=n-2;i+=2)
	{
		A(i,i+1,i+2);
	}
	for(int i=1;i<=n-2;i+=2)
	{
		A(i,i+1,n);
		output();
	}
	printf("YES\n%d\n",tot);
	FOR(i,1,tot)printf("%d %d %d\n",b[i],c[i],d[i]);
}
int main()
{
	init();
	input();
	solve();
	return 0;
}