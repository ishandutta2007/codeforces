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
const int maxn=1e5+5;
vector<int>e[maxn];
vector<int>must,ord;
int n;
int cnt=0;
inline int query(vector<int>nodes)
{
	cnt++;
	assert(cnt<=12);
	printf("? %d ",sz(nodes));
	for(int x:nodes)printf("%d ",x);
	puts("");
	fflush(stdout);
	int x=gi();return x;
}
inline void init()
{

}
int fa[maxn];
inline void dfs(int u)
{
	ord.pb(u);
	for(int v:e[u])
	{
		if(v==fa[u])continue;
		fa[v]=u;
		dfs(v);
	}
}
inline void input()
{
	n=gi();
	FOR(i,1,n-1)
	{
		int u=gi(),v=gi();
		e[u].pb(v),e[v].pb(u);
	}
	srand(time(0));
	dfs(1);
}
inline void solve()
{
	vector<int>temp;FOR(i,1,n)temp.pb(i);
	int l=1,r=n-1,w=query(temp),ret=n-1;
	must.pb(1);
	while(l<=r)
	{
		int mid=(l+r)>>1;
		temp=must;
		FOR(i,l,mid)temp.pb(ord[i]);
		if(query(temp)==w)ret=mid,r=mid-1;
		else 
		{
			FOR(i,l,mid)must.pb(ord[i]);
			l=mid+1;
		}
	}
	ret=ord[ret];
	printf("! %d %d\n",ret,fa[ret]);
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