#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
int T;
const int maxn=3e5+5;
int n,q,K,p[maxn],a[maxn],s[maxn],d[maxn],vn;
void discrete()
{
	static int v[maxn<<1];
	vn=0;
	for(int i=1;i<=n;i++)if(a[i])v[++vn]=a[i];
	for(int i=1;i<=K-1;i++)v[++vn]=s[i];
	for(int i=1;i<=q;i++)v[++vn]=d[i];
	sort(v+1,v+vn+1);vn=unique(v+1,v+vn+1)-(v+1);
	for(int i=1;i<=n;i++)if(a[i])a[i]=lower_bound(v+1,v+vn+1,a[i])-v;
	for(int i=1;i<=K-1;i++)s[i]=lower_bound(v+1,v+vn+1,s[i])-v;
	for(int i=1;i<=q;i++)d[i]=lower_bound(v+1,v+vn+1,d[i])-v;
}
class graph
{
	int son[maxn][2],rt;
	public:
	void clear(){rt=0;memset(son,0,sizeof son);}
	void build(const int p[])
	{
		static int sta[maxn],top;
		top=0;
		for(int i=1;i<=n;i++)
		{
			int tmp=top;
			while(tmp&&p[sta[tmp]]<p[i])tmp--;
			if(!tmp)rt=i;
			else son[sta[tmp]][1]=i;
			if(top!=tmp)son[i][0]=sta[tmp+1];
			sta[++tmp]=i;
			top=tmp;
		}
	}
	vector<pair<int,int>>get(const int v[])
	{
		vector<pair<int,int>>ret;ret.reserve(K);
		bool flag=true;
		auto dfs=[&](auto&& self,int u,int mi)->int
		{
			if(mi<=v[u]){flag=false;return -1;}
			if(v[u])mi=v[u];
			int mx=0;
			if(son[u][0])mx=max(mx,self(self,son[u][0],mi));
			if(!flag)return -1;
			if(son[u][1])mx=max(mx,self(self,son[u][1],mi));
			if(!flag)return -1;
			if(!v[u])
			{
				if(mx+1>mi-1){flag=false;return -1;}
				ret.emplace_back(mx+1,mi-1);
			}
			mx=max(mx,v[u]);
			return mx;
		};
		dfs(dfs,rt,vn+1);
		if(!flag)return {};
		return ret;
	}
}o;
int main()
{
	T=read();
	while(T--)
	{
		n=read();q=read();
		generate_n(p+1,n,read);
		generate_n(a+1,n,read);
		K=count(a+1,a+n+1,0);
		generate_n(s+1,K-1,read);
		generate_n(d+1,q,read);
		discrete();
		o.build(p);
		auto seg=o.get(a);
		if(seg.empty())for(int i=1;i<=q;i++)puts("NO");
		else
		{
			static vector<int>add[maxn<<1];
			static int del[maxn<<1];
			
			for(int i=1;i<=K-1;i++)del[s[i]]++;
			
			bool flag=true;
			int L=0,R=0;
			
			priority_queue<int,vector<int>,greater<int>>q0;
			for(auto&[l,r]:seg)add[l].push_back(r);
			for(int i=1;i<=vn;i++)
			{
				while(!q0.empty()&&q0.top()<i){R=q0.top();q0.pop();}
				for(int &j:add[i])q0.push(j);
				if(del[i]>q0.size()){flag=false;break;}
				for(int j=0;j<del[i];j++)q0.pop();
			}
			for(int i=1;i<=vn;i++)add[i].clear();
			if(!flag)for(int i=1;i<=q;i++)puts("NO");
			else
			{
				if(!q0.empty())R=q0.top();
				priority_queue<int>q1;
				for(auto&[l,r]:seg)add[r].push_back(l);
				for(int i=vn;i>=1;i--)
				{
					while(!q1.empty()&&q1.top()>i){L=q1.top();q1.pop();}
					for(int &j:add[i])q1.push(j);
					for(int j=0;j<del[i];j++)q1.pop();
				}
				for(int i=1;i<=vn;i++)add[i].clear();
				if(!q1.empty())L=q1.top();
				for(int i=1;i<=q;i++)puts(L<=d[i]&&d[i]<=R?"YES":"NO");
			}
			memset(del,0,sizeof(int)*(vn+1));
		}
		o.clear();		
	}
	return 0;
}