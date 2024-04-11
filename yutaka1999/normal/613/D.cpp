#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <cmath>
#define SIZE 100005
#define BT 20

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
typedef pair <P,P> PP;

vector <int> vec[SIZE];
int par[SIZE][BT],dep[SIZE];
int id[SIZE],ch[SIZE];
int now_id;
int n,q;

void dfs(int v=0,int p=-1,int d=0)
{
	par[v][0]=p;
	dep[v]=d;
	id[v]=now_id++;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p) dfs(to,v,d+1);
	}
	ch[v]=now_id;
}
void make()
{
	for(int i=0;i+1<BT;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(par[j][i]==-1) par[j][i+1]=-1;
			else par[j][i+1]=par[par[j][i]][i];
		}
	}
}
int LCA(int a,int b)
{
	if(dep[a]>=dep[b]) swap(a,b);//dep[a]<=dep[b]
	for(int i=BT-1;i>=0;i--)
	{
		if(par[b][i]!=-1&&dep[par[b][i]]>=dep[a])
		{
			b=par[b][i];
		}
	}
	if(a==b) return a;
	for(int i=BT-1;i>=0;i--)
	{
		if(par[a][i]!=par[b][i])
		{
			a=par[a][i];
			b=par[b][i];
		}
	}
	return par[a][0];
}
bool have(int v,int c)//vcqAv=c
{
	return id[v]<=id[c]&&id[c]<ch[v];
}
int solve(vector <int> vec)
{
	vector <P> vt;
	for(int i=0;i<vec.size();i++)
	{
		int v=vec[i];
		vt.push_back(P(id[v],v));
	}
	sort(vt.begin(),vt.end());
	set <PP> st;
	set <PP>::iterator it;
	set <P> zan;
	set <P>::iterator its;
	for(int i=0;i<vt.size();i++) zan.insert(vt[i]);
	for(int i=0;i<vt.size();i++)
	{
		int v=vt[i].second;
		if(par[v][0]!=-1&&zan.count(P(id[par[v][0]],par[v][0]))) return -1;
	}
	for(int i=0;i+1<vt.size();i++)
	{
		int s=vt[i].second,t=vt[i+1].second;
		int p=LCA(s,t);
		st.insert(PP(P(-dep[p],p),P(s,t)));
	}
	int ret=0;
	while(!st.empty())
	{
		it=st.begin();
		PP pp=*it;
		st.erase(it);
		int p=pp.first.second,s=pp.second.first,t=pp.second.second;
		//printf("%d %d %d\n",p,s,t);
		if(s==p)
		{
			ret++;
			zan.erase(P(id[t],t));
			its=zan.lower_bound(P(id[t],t));
			if(its!=zan.end())
			{
				P q=*its;
				int v=q.second,l=LCA(s,v);
				st.insert(PP(P(-dep[l],l),P(s,v)));
				int r=LCA(t,v);
				st.erase(PP(P(-dep[r],r),P(t,v)));
			}
			continue;
		}
		ret++;
		zan.erase(P(id[s],s));
		zan.erase(P(id[t],t));
		bool up=true;
		if(zan.count(P(id[p],p)))
		{
			ret++;
			up=false;
		}
		int l=-1,r=-1;
		while(1)
		{
			its=zan.lower_bound(P(id[s],s));
			if(its==zan.begin()) break;
			its--;
			P q=*its;
			int v=q.second;
			if(up&&have(p,v))
			{
				zan.erase(its);
				st.erase(PP(P(-dep[p],p),P(v,s)));
				s=v;
			}
			else
			{
				int k=LCA(s,v);
				st.erase(PP(P(-dep[k],k),P(v,s)));
				l=v;
				break;
			}
		}
		while(1)
		{
			its=zan.lower_bound(P(id[t],t));
			if(its==zan.end()) break;
			P q=*its;
			int v=q.second;
			if(up&&have(p,v))
			{
				zan.erase(its);
				st.erase(PP(P(-dep[p],p),P(t,v)));
				t=v;
			}
			else
			{
				int k=LCA(t,v);
				st.erase(PP(P(-dep[k],k),P(t,v)));
				r=v;
				break;
			}
		}
		//printf("%d %d\n",l,r);
		if(l!=-1&&r!=-1)
		{
			int q=LCA(l,r);
			st.insert(PP(P(-dep[q],q),P(l,r)));
		}
	}
	return ret;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	dfs();
	make();
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		int k;
		scanf("%d",&k);
		vector <int> vec;
		for(int j=0;j<k;j++)
		{
			int v;
			scanf("%d",&v);v--;
			vec.push_back(v);
		}
		printf("%d\n",solve(vec));
	}
	return 0;
}