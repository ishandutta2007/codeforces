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
const int maxn=2e5+5,mod=1e9+7;
int fa[maxn],n,m,x,y,c;
inline void input()
{
	n=gi(),m=gi();
	FOR(i,1,2*n+4)fa[i]=i;
}
inline int get(int x)
{
	if(x==fa[x])return x;
	else return fa[x]=get(fa[x]);
}
inline void solve()
{
	int N=n+2;
	FOR(i,1,m)
	{
		x=gi()-1,y=gi()-1;
		char s[2];
		scanf("%s",s);
		int l=abs(x-y),r=2+min((n-1)*2-(x+y),x+y);
		int l2=l+N,r2=r+N;
		if(s[0]=='x')
		{
			if(get(l)==get(r))continue;
			if(get(l)==get(r2))return puts("0"),void();
			else fa[get(l)]=get(r),fa[get(l2)]=get(r2);
		}
		else
		{
			if(get(l)==get(r2))continue;
			if(get(l)==get(r))return puts("0"),void();
			else fa[get(l)]=get(r2),fa[get(r)]=get(l2);
		}
	}
	int cnt=0;
	FOR(i,1,N*2)cnt+=get(i)==i;
	int ans=1;cnt=cnt/2-2;
	FOR(i,1,cnt)ans=ans*2%mod;
	printf("%d\n",ans);
}
int main()
{
	input();
	solve();
	return 0;
}