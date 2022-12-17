//#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define rd (rand()<<16^rand())
#define gc getchar()//(_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
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
const int maxn=2e5+5;
int n;
int x;
set<int>s;
char opt[maxn][3];
int a[maxn],pos[maxn];
int val[maxn];
inline void init()
{

}
inline void input()
{
	scanf("%d",&n);
	FOR(i,1,2*n)
	{
		scanf("%s",opt[i]+1);
		if(opt[i][1]=='-')scanf("%d",&a[i]);
	}
}
inline void solve()
{
	FOR(i,1,2*n)if(opt[i][1]=='+')s.insert(i);else pos[a[i]]=i;
	FOR(i,1,n)
	{
		if(!s.size()){printf("NO\n");return ;}
		auto it=s.lower_bound(pos[i]);
		if(it==s.begin()){printf("NO\n");return ;}
		--it;
		val[*it]=i;
		s.erase(it);
	}
	s.clear();
	FOR(i,1,2*n)
	{
		if(opt[i][1]=='+')s.insert(val[i]);
		else
		{
			int x=*s.begin();
			s.erase(x);
			if(x!=a[i]){printf("NO\n");return ;}
		}
	}
	printf("YES\n");
	FOR(i,1,2*n)if(val[i])printf("%d ",val[i]);
	printf("\n");
}
int main()
{
	init();
	input();
	solve();
	return 0;
}