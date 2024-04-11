#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define PLL pair<ll,ll>
#define fi first
#define se second
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
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
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=3e5+5;
int n,k,ind[maxn],fa[maxn],f[maxn];
int a[maxn],b[maxn];
int nxt[maxn];
vector<int>e[maxn];
inline int get(int x)
{
	if(x==f[x])return x;
	else return f[x]=get(f[x]);
}
inline void init()
{
	
}
inline void input()
{
	n=gi(),k=gi();
	FOR(i,1,n)fa[i]=gi(),f[i]=i,nxt[i]=i,e[fa[i]].pb(i);
	FOR(i,1,k)
	{
		a[i]=gi();
		b[i]=gi();
		nxt[a[i]]=b[i];
	}
}
vector<int>vec[maxn];
int tot,bel[maxn];
vector<int>order;
inline void solve()
{
	FOR(i,1,k)
	{
		int f1=get(a[i]),f2=get(b[i]);
		if(f1==f2){printf("0\n");return ;}
		f[f2]=f1;
	}
	set<int>s;
	FOR(i,1,n)
	{
		if(f[i]==i)
		{
			++tot;
			s.clear();
			int now=i;
			while(1)
			{
				bel[now]=tot;
				vec[tot].pb(now);
				s.insert(now);
				if(!s.count(fa[now])&&fa[now]!=0)ind[tot]++;
				if(now==nxt[now])break;
				now=nxt[now];
			}
		}
	}
	queue<int>q;
	int counter=0;
	FOR(i,1,tot)if(ind[i]==0)q.push(i);
	while(!q.empty())
	{
		counter++;
		int u=q.front();
		order.pb(u);
		q.pop();
		for(auto x:vec[u])
		{
			for(auto y:e[x])
			{
				ind[bel[y]]--;
				if(ind[bel[y]]==0)
				{
					q.push(bel[y]);
				}
			}
		}
	}
	if(counter==tot)
	{
		for(auto x:order)
		{
			for(auto y:vec[x])
			{
				printf("%d ",y);
			}
		}
		printf("\n");
	}
	else
	{
		printf("0\n");
	}
}
int main()
{
	init();
	input();
	solve();
	return 0;
}