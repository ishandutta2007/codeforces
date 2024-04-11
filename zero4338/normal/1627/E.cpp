#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
int T;
const int maxn=1e6+5;
const ll inf=1e17;
int n,m,k;
int x[maxn];
map<pair<int,int>,int>num;
struct graph
{
	vector<pair<int,int>>e[maxn];
	void clear(){for(int i=1;i<=num.size();i++)e[i].clear();}
	void add(int x,int y,int z){e[x].push_back({y,z});}
}o;
vector<int>p[maxn];
struct edge{int fr,to,val;}e[maxn];
ll dis[maxn];
int main()
{
	T=read();
	while(T--)
	{
		n=read();m=read();k=read();
		generate_n(x+1,n,read);
		for(int i=1;i<=n;i++)p[i].clear();
		num.clear();
		num[{1,1}]=1;p[1].push_back(1);
		for(int i=1;i<=k;i++)
		{
			int a=read(),b=read(),c=read(),d=read(),h=read();
			if(!num[{a,b}])num[{a,b}]=num.size(),p[a].push_back(b);
			if(!num[{c,d}])num[{c,d}]=num.size(),p[c].push_back(d);
			e[i].fr=num[{a,b}];e[i].to=num[{c,d}];e[i].val=h;
		}
		o.clear();
		for(int i=1;i<=k;i++)o.add(e[i].to,e[i].fr,e[i].val);
		for(int i=1;i<=num.size();i++)dis[i]=-inf;dis[1]=0;
		for(int i=1;i<=n;i++)
		{
			if(p[i].empty())continue;
			for(int &j:p[i])
			{
				int id=num[{i,j}];
				for(auto &k:o.e[id])
				if(dis[k.first]!=-inf)dis[id]=max(dis[id],dis[k.first]+k.second);
			}
			sort(p[i].begin(),p[i].end());
			ll mx=-inf;
			for(int j=0;j<p[i].size();j++)
			{
				int id=num[{i,p[i][j]}];
				if(dis[id]!=-inf)mx=max(mx,dis[id]+(ll)x[i]*p[i][j]);
				if(mx!=-inf)dis[id]=max(dis[id],mx-(ll)x[i]*p[i][j]);
			}
			mx=-inf;
			for(int j=p[i].size()-1;j>=0;j--)
			{
				int id=num[{i,p[i][j]}];
				if(dis[id]!=-inf)mx=max(mx,dis[id]-(ll)x[i]*p[i][j]);
				if(mx!=-inf)dis[id]=max(dis[id],mx+(ll)x[i]*p[i][j]);
			}
		}
		ll ans=-inf;
		for(int &i:p[n])ans=max(ans,(ll)x[n]*(i-m)+dis[num[{n,i}]]);
		if(ans==-inf)puts("NO ESCAPE");
		else printf("%lld\n",-ans);
	}
	return 0;
}