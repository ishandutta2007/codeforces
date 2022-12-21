#pragma GCC optimize(3)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<set>
#define IN inline
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
using namespace std;
inline int gi()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return (f==1)?x:-x;
}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=5e5+5;
int fa[maxn],siz[maxn],sz,val[maxn],n,m,q;
inline int get(int x){if(x==fa[x])return x;else return get(fa[x]);}
set<int>s[maxn];
vector<int>vec[maxn];
vector<PII>temp;
bool del[maxn];
int typ[maxn],x[maxn],now[maxn][2],mp[maxn];
inline void merge(int u,int v)
{
	if(u!=v)
	{
		if(siz[u]>siz[v])swap(u,v);
		siz[v]+=siz[u],fa[u]=v;
		FOR(i,0,(int)vec[u].size()-1)vec[v].push_back(vec[u][i]); 
	}
}
int main()
{
	n=gi(),m=gi(),q=gi();
	FOR(i,1,n)val[i]=gi(),fa[i]=i,siz[i]=1,vec[i].push_back(i);
	temp.push_back(PII(0,0));
	FOR(i,1,m){int u=gi(),v=gi();temp.push_back(PII(u,v));}
	FOR(i,1,q){typ[i]=gi(),x[i]=gi();if(typ[i]==2)del[x[i]]=1;}
	FOR(i,1,m)if(!del[i])merge(get(temp[i].first),get(temp[i].second));
	for(int i=q;i>=1;--i)
	{
		if(typ[i]==2)
		{
			int u=get(temp[x[i]].first),v=get(temp[x[i]].second);
			merge(u,v);now[i][0]=u,now[i][1]=v;
		}
	}
	FOR(i,1,n)s[get(i)].insert(val[i]),mp[val[i]]=i,s[i].insert(0);
	FOR(i,1,q)
	{
		if(typ[i]==1)
		{
			x[i]=get(x[i]);
			int ans=*(--s[x[i]].end());
			printf("%d\n",ans);
			s[x[i]].erase(ans),s[x[i]].insert(0),val[mp[ans]]=0;
		}
		else
		{
			if(now[i][0]!=now[i][1])
			{
				int u=now[i][0],v=now[i][1];
				if(fa[v]==u)swap(u,v);
				fa[u]=u;
				siz[v]-=siz[u];
				FOR(i,0,siz[u]-1)vec[v].pop_back();
				FOR(i,0,siz[u]-1)
				{
					s[v].erase(val[vec[u][i]]);
					s[u].insert(val[vec[u][i]]);
				}
				s[v].insert(0);///0 maybe deleted
			}
		}
	}
	return 0;
}