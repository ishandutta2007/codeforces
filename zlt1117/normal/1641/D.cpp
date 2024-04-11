#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define db double
#define mk make_pair
#define iter set<int>::iterator
#define gc (_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
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
const int maxn=1e5+5;
int b[maxn*5],B=8192,n,k;
struct node
{
	int v[6],w;
}a[maxn];
bitset<8192>bs[maxn*5];
inline void init()
{

}
inline void input()
{
	n=gi();k=gi();
	int tot=0;
	FOR(i,1,n)
	{
		FOR(j,1,k)a[i].v[j]=gi(),b[++tot]=a[i].v[j];
		a[i].w=gi();
	}
	sort(b+1,b+tot+1);tot=unique(b+1,b+tot+1)-b-1;
	FOR(i,1,n)FOR(j,1,k)a[i].v[j]=lower_bound(b+1,b+tot+1,a[i].v[j])-b;
	sort(a+1,a+n+1,[&](node &a,node &b){return a.w<b.w;}); 
}
bool vis[maxn*5];
inline void solve()
{
	int l=1,ans=2e9+1;
	while(l<=n)
	{
		int r=min(l+B-1,n);
		FOR(i,l,r)
		{
			FOR(j,1,k)vis[a[i].v[j]]=1,bs[a[i].v[j]][i-l]=1;
			/*FOR(j,l,r)
			{
				FOR(p,1,k)if(vis[a[j].v[p])continue;
				ans=min(ans,v[i]+v[j]);
				break;
			}*/
			FOR(j,1,k)vis[a[i].v[j]]=0;
		}
		FOR(i,1,n)
		{
			bitset<8192>now=~bs[a[i].v[1]];
			FOR(j,2,k)now&=~bs[a[i].v[j]];
			int x=now._Find_first();
			if(l+x<=n&&x!=now.size())ans=min(ans,a[i].w+a[l+x].w);
		}
		FOR(i,l,r)FOR(j,1,k)bs[a[i].v[j]][i-l]=0;
		l=r+1;
	}
	if(ans==(int)(2e9+1))puts("-1");
	else printf("%d\n",ans);
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
/*
2 1
1 1000000000
2 1000000000
*/