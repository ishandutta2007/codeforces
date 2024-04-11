//#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define pb push_back
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
const int maxn=1e5+5,inf=1e9;
int n,a[maxn],pos[maxn];
int pre[maxn];
inline void init()
{

}
inline void input()
{
	n=gi();
	FOR(i,1,n)a[i]=gi(),pre[i]=pre[i-1]^a[i];
}
inline int get(int x)
{
	int ret=0;
	while(x)x>>=1,ret++;
	return ret;
}
inline void solve()
{
	FOR(i,1,n)
	{
		int b=get(a[i]);
		if(!pos[b])pos[b]=i;
		else if(i-pos[b]>=2){printf("1\n");return ;}
	}
	int ans=inf;
	FOR(i,1,n)
	{
		FOR(j,i,n)
		{
			FOR(k,j+1,n)
			{
				int val1=pre[j]^pre[i-1];
				int val2=pre[k]^pre[j];
				if(val1>val2)
				{
					ans=min(ans,k-i-1);
				}
			}
		}
	}
	if(ans==inf)printf("-1\n");
	else printf("%d\n",ans);
}
int main()
{
	init();
	input();
	solve();
	return 0;
}///