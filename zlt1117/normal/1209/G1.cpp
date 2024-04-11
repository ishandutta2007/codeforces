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
int n,a[maxn],maxpos[maxn],cnt[maxn],ans=0,q;
vector<int>vec;
inline void init()
{

}
inline void input()
{
	n=gi();q=gi();
	FOR(i,1,n)a[i]=gi(),maxpos[a[i]]=i;
}
inline void solve()
{
	int last=1,now=0;
	while(last<=n)
	{
		now=maxpos[a[last]];
		int maxv=0;
		for(auto x:vec)cnt[x]=0;
		vec.clear();
		FOR(i,last,now)
		{
			now=max(maxpos[a[i]],now);
			cnt[a[i]]++;
			vec.push_back(a[i]);
			if(cnt[a[i]]>maxv)maxv=cnt[a[i]];
		}
		ans+=now-last+1-maxv;
		last=now+1;
	}
	printf("%d\n",ans);
}
int main()
{
	init();
	input();
	solve();
	return 0;
}