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
const int maxn=50005;
int n;
int r[maxn][6],now[6],tmp[6];
inline void init()
{
	memset(now,0,sizeof(now));
	memset(tmp,0x3f,sizeof(tmp));
}
inline void input()
{
	n=gi();
	FOR(i,1,n)FOR(j,1,5)r[i][j]=gi();
	FOR(i,1,n)FOR(j,1,5)tmp[j]=min(tmp[j],r[i][j]);
}
inline bool better(int i,int j)
{
	int sum=0;
	FOR(k,1,5)sum+=r[i][k]<r[j][k];
	return sum<3;
}
inline void solve()
{
	int best=1;
	FOR(i,1,n)if(better(best,i))best=i;
	bool ok=1;
	FOR(kk,1,n)
	{
		if(kk!=best&&better(best,kk))return puts("-1"),void();
	}	
	printf("%d\n",best);
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