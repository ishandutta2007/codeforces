#include <bits/stdc++.h>
using namespace std;
#define N ((int)201*1000)

int n,m,q,ans[N],par[N],val[N];
pair <int,int> qu[N];
set <pair<pair<int,int>,pair<int,int> > > s;
vector <pair<pair<int,int>,int> > seg[4*N];
vector <int> now;

pair <int,int> root(int x){if(par[x]<0)return {x,0};pair<int,int> res=root(par[x]);return {res.first,res.second^val[x]};}

int mini(int x){for(auto u:now)x=min(x,x^u);return x;}

void add(int x)
{
	for(auto u:now)x=min(x,x^u);
	if(!x)return ;
	for(auto &u:now)u=min(u,u^x);
	now.push_back(x);
}

void update(int ql,int qr,int v,int u,int w,int xl=0,int xr=N,int id=1)
{
	if(qr<=xl || xr<=ql)return ;
	if(ql<=xl && xr<=qr){seg[id].push_back({{v,u},w});return ;}
	int mid=(xl+xr)/2;
	update(ql,qr,v,u,w,xl,mid,id*2);
	update(ql,qr,v,u,w,mid,xr,id*2+1);
}

void walk(int xl=0,int xr=N,int id=1)
{
	vector <int> ex=now;
	vector <pair<pair<int,int>,int> > ex2;
	for(auto u:seg[id])
	{
		pair <int,int> p1=root(u.first.first),p2=root(u.first.second);
		if(p1.first==p2.first)add(p1.second^p2.second^u.second);
		else
		{
			if(par[p1.first]>par[p2.first])swap(p1,p2);
			ex2.push_back({{p1.first,p2.first},par[p2.first]});
			par[p1.first]+=par[p2.first];
			par[p2.first]=p1.first;
			val[p2.first]=p2.second^p1.second^u.second;
		}
	}
	if(xl==xr-1){if(xl<m)ans[xl]=mini(root(qu[xl].first).second^root(qu[xl].second).second);}
	else
	{
		int mid=(xl+xr)/2;
		walk(xl,mid,id*2);
		walk(mid,xr,id*2+1);
	}
	now=ex;
	reverse(ex2.begin(),ex2.end());
	for(auto u:ex2)
	{
		par[u.first.second]=u.second;
		val[u.first.second]=0;
		par[u.first.first]-=u.second;
	}
}

int main()
{
	memset(par,-1,sizeof par);
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int v,u,w;
		scanf("%d%d%d",&v,&u,&w);
		if(v>u)swap(v,u);
		s.insert({{v,u},{w,0}});
	}
	scanf("%d",&q);m=0;
	while(q--)
	{
		int t,v,u,w;
		scanf("%d%d%d",&t,&v,&u);
		if(v>u)swap(v,u);
		if(t==1)scanf("%d",&w),s.insert({{v,u},{w,m}});
		if(t==2)
		{
			auto it=s.lower_bound({{v,u},{0,0}});
			update(it->second.second,m,v,u,it->second.first);
			s.erase(it);
		}
		if(t==3)qu[m++]={v,u};
	}
	for(auto u:s)update(u.second.second,m,u.first.first,u.first.second,u.second.first);
	walk();
	for(int i=0;i<m;i++)printf("%d\n",ans[i]);
	return 0;
}