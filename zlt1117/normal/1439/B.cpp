#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define rd (rand()<<16^rand())
#define sz(x) (int)(x.size())
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
const int maxn=2e5+5;
int n,m,T;
vector<int>vec[maxn];
int ind[maxn],k;
set<int>s[maxn];
bool vis[maxn],vis2[maxn];
vector<int>ans;
queue<int>q;
inline void init()
{
	FOR(i,1,n)vec[i].clear(),ind[i]=0,s[i].clear(),vis[i]=0,vis2[i]=0;
	ans.clear();while(!q.empty())q.pop();
}
inline void input()
{
	n=gi(),m=gi(),k=gi();
	FOR(i,1,m)
	{
		int u=gi(),v=gi();
		vec[u].pb(v),vec[v].pb(u);
		ind[u]++,ind[v]++;
	}
}
inline void dfs(int u)
{
	vis2[u]=1;
	ans.pb(u);
	for(auto v:vec[u])
	{
		if(!vis[v]&&!vis2[v])
		{
			dfs(v);
		}
	}
}
struct node
{
	int u,indd;
	node(int uu=0,int ii=0){u=uu,indd=ii;}
	inline bool operator<(const node &b)const
	{
		return indd<b.indd;
	}
};
inline bool check(int u,int xx)
{
	vector<int>vec1;vec1.clear();
	vec1.pb(u);
	for(auto x:s[u])
	{
		if(ind[x]<k-1)return 0;
		for(auto y:vec1)
		{
			if(!s[x].count(y))
			{
				return 0;
			}
		}
		vec1.pb(x);
	}
	return 1;
}
inline void solve(int xx)
{
	if(k==1)
	{
		printf("2\n1\n");
		return ;
	}
	FOR(i,1,n)
	{
		for(auto x:vec[i])s[i].insert(x);
		ind[i]=s[i].size();
	}
	FOR(i,1,n)
	{
		if(ind[i]<k)q.push(i),vis[i]=1;
		if(ind[i]==k-1)
		{
			if(1LL*k*(k-1)<=2*m&&check(i,xx))
			{
				printf("2\n");
				for(auto x:s[i])printf("%d ",x);
				printf("%d\n",i);
				return ;
			}
		}
	}
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(auto v:s[u])
		{
			ind[v]--;
			s[v].erase(u);
			if(!vis[v]&&ind[v]<k)vis[v]=1,q.push(v);
			if(1LL*k*k<=2*m&&ind[v]==k-1)
			{
				if(check(v,xx))
				{
					printf("2\n");
					for(auto x:s[v])printf("%d ",x);
					printf("%d\n",v);
					return ;
				}
			}
		}
		s[u].clear();
	}
	bool ok=0;
	FOR(i,1,n)
	{
		if(!vis[i])
		{
			ok=1;
			dfs(i);
			break;
		}
	}
	if(ok)
	{
		printf("1 %d\n",sz(ans));
		for(auto x:ans)printf("%d ",x);
		printf("\n");
		return ;
	}
	printf("-1\n");
}
int main()
{
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	T=gi();
	FOR(i,1,T)
	{	
		init();
		input();
		solve(i);
	}
	return 0;
}