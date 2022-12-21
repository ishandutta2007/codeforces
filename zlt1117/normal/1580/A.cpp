#pragma GCC optimize("Ofast")
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
const int maxn=405;
int n,m,a[maxn][maxn],b[maxn][maxn];
char s[maxn][maxn];
inline void init()
{

}
inline void input()
{
	n=gi(),m=gi();
	FOR(i,1,n)scanf("%s",s[i]+1);
	FOR(i,1,n)FOR(j,1,m)b[i][j]=a[i][j]=s[i][j]-'0';
	FOR(i,1,n)FOR(j,1,m)a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
}
inline int count(int aa,int b,int c,int d)
{
	aa--,b--;
	return a[c][d]-a[aa][d]-a[c][b]+a[aa][b];
}
inline void solve()
{
	int ans=16;
	FOR(i,1,n-4)FOR(j,1,m-3)
	{
		int now=0;
		FOR(k,i+1,i+2)now+=b[k][j]==0;
		FOR(p1,i+4,n)
		{
			now+=b[p1-1][j]==0;
			if(now>=ans)break;
			int nows=now;
			FOR(p2,j+3,m)
			{
				nows+=(b[i][p2-1]==0)+(b[p1][p2-1]==0);
				if(nows>=ans)break;
				int sum=(p1-i-1)*2+(p2-j-1)*2;
				sum-=count(i,j,p1,p2)-count(i+1,j+1,p1-1,p2-1)-b[i][j]-b[i][p2]-b[p1][j]-b[p1][p2];
				sum+=count(i+1,j+1,p1-1,p2-1);
				ans=min(ans,sum);
			}
		}
	}
	printf("%d\n",ans);
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