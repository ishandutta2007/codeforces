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
const int maxn=1005,maxm=1e5+5;
int a[maxn][maxn],n,m,k;
int c[maxm];
int fa[maxn][maxn];
inline int get(int *fa,int x){if(x==fa[x])return x;return fa[x]=get(fa,fa[x]);}
inline void init()
{

}
inline void input()
{
	n=gi(),m=gi(),k=gi();
	FOR(i,1,n)FOR(j,1,m)a[i][j]=gi();
}
inline int go(int y)
{
	int x=1;
	while(x<=n)
	{
		x=get(fa[y],x);
		if(x!=n)fa[y][x]=get(fa[y],fa[y][x+1]);
		if(a[x][y]==1)a[x][y]=2,y++;
		else if(a[x][y]==2)a[x][y]=2,x++;
		else if(a[x][y]==3)a[x][y]=2,y--;
	}
	return y;
}
inline void solve()
{
	FOR(i,1,n)FOR(j,1,m)fa[j][i]=i;
	FOR(i,1,k)
	{
		c[i]=gi();
		printf("%d ",go(c[i]));
	}
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