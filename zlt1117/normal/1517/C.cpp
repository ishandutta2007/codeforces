//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define sz(x) (int)(x.size())
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define rd (rand()<<16^rand())
//#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2))?EOF:*p1++;
#define gc getchar()
#define iter set<int>::iterator
using namespace std;
char buf[100000],*p1=buf,*p2=buf;
inline int gi()
{
	int x=0,f=1;char ch=gc;
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48),ch=gc;}
	return (f==1)?x:-x;
}
const int maxn=505;
int a[maxn][maxn],p[maxn],n;
inline void input()
{
	n=gi();
	FOR(i,1,n)p[i]=gi();
}
inline void solve()
{
	FOR(i,1,n)
	{
		int cnt=0;
		int last=i;
		FOR(j,i,n)
		{
			int pos=last;
			while(!a[j][pos]&&pos>=1&&cnt<p[i])a[j][pos]=p[i],pos--,cnt++,last=pos+1;
		}
	}
	FOR(i,1,n)FOR(j,1,i)printf("%d%c",a[i][j]," \n"[j==i]);
}
int main()
{
	input();
	solve();
	return 0;
}