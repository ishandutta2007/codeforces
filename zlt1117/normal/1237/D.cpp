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
const int maxn=3e5+5;
int a[maxn],n,m;
int minv[maxn][20];
int ans[maxn],ed[maxn];
inline void init()
{
	
}
inline void input()
{
	n=gi();
	FOR(i,1,n)a[i]=gi();
	FOR(i,1,n)a[i+n]=a[i];
	FOR(i,1,n)a[i+2*n]=a[i];
}
inline void solve()
{
	int m=n*3;
	ed[m+1]=3*n+1; 
	for(int i=m;i>=1;--i)
	{
		minv[i][0]=a[i];
		FOR(j,1,19)if(i+(1<<j)-1<=m)minv[i][j]=min(minv[i][j-1],minv[i+(1<<(j-1))][j-1]);
	}
	for(int i=m;i>=1;--i)
	{
		int pos=i;
		for(int j=19;j>=0;--j)
		{
			if(pos+(1<<j)-1<=m)
			{
				if(minv[pos][j]>=(a[i]+1)/2)pos+=(1<<j);
			}
		}
		ed[i]=pos;
		ed[i]=min(ed[i],ed[i+1]);
		ans[i]=ed[i]-i;
	}
	FOR(i,1,n)
	{
		ans[i]=max(ans[i],ans[i+n]);
		ans[i]=max(ans[i],ans[i+2*n]);
		if(ans[i]>2*n)printf("-1 ");
		else printf("%d ",ans[i]);
	}
	printf("\n");
}
int main()
{
	init();
	input();
	solve();
	return 0;
}///