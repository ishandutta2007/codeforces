#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#define SIZE 100005

using namespace std;
typedef pair <int,int> P;
typedef long long int ll;

struct edge
{
	int to,cost;
	edge(int to=0,int cost=0):to(to),cost(cost){}
};
vector <edge> vec[SIZE];
vector <int> gt[SIZE];
int nd[SIZE],cmb[SIZE];
int sum[SIZE],gl[SIZE];
int pos[SIZE];
int n;

void dfs(int v=0,int p=-1)
{
	nd[v]=1;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i].to;
		if(to!=p)
		{
			dfs(to,v);
			nd[v]+=nd[to];
		}
	}
}
P center(int v=0,int p=-1)
{
	int mx=n-nd[v];
	P ret=P(n*2,-1);
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i].to;
		if(to!=p)
		{
			P p=center(to,v);
			ret=min(ret,p);
			mx=max(mx,nd[to]);
		}
	}
	ret=min(ret,P(mx,v));
	return ret;
}
void color(int v,int p,int k)
{
	cmb[v]=k;
	gt[k].push_back(v);
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i].to;
		if(to!=p)
		{
			color(to,v,k);
		}
	}
}
ll get(int v,int p,ll d)
{
	ll ret=d;
	for(int i=0;i<vec[v].size();i++)
	{
		edge e=vec[v][i];
		if(e.to!=p)
		{
			ret+=get(e.to,v,d+e.cost);
		}
	}
	return ret;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);a--;b--;
		vec[a].push_back(edge(b,c));
		vec[b].push_back(edge(a,c));
	}
	if(n==1)
	{
		puts("0");
		puts("1");
		return 0;
	}
	dfs();
	int ct=center().second;
	int sz=0;
	cmb[ct]=sz;
	gt[sz++].push_back(ct);
	for(int i=0;i<vec[ct].size();i++)
	{
		int to=vec[ct][i].to;
		color(to,ct,sz++);
	}
	set <P> st,gd;
	set <P>::iterator it;
	for(int i=0;i<sz;i++)
	{
		sort(gt[i].begin(),gt[i].end());
		sum[i]=gt[i].size()*2;
		st.insert(P(sum[i],i));
		pos[i]=0;
		gd.insert(P(gt[i][0],i));
	}
	//puts("*");
	for(int i=0;i<n;i++)
	{
		int c=cmb[i];
		st.erase(P(sum[c],c));
		sum[c]--;
		it=st.end();it--;
		P p=*it;
		if(p.first==n-i&&p.second!=0)
		{
			int d=p.second;
			st.erase(it);
			gd.erase(P(gt[d][pos[d]],d));
			//printf("%d %d %d\n",d,pos[d],gl[i]);
			gl[i]=gt[d][pos[d]++];
			sum[d]--;
			st.insert(P(sum[d],d));
			if(pos[d]<gt[d].size()) gd.insert(P(gt[d][pos[d]],d));
		}
		else
		{
			it=gd.begin();
			if(it->second==c&&c!=0) it++;
			int d=it->second;
			//printf("%d %d %d %d\n",d,pos[d],gt[d][pos[d]],gl[i]);
			st.erase(P(sum[d],d));
			gd.erase(it);
			gl[i]=gt[d][pos[d]++];
			sum[d]--;
			st.insert(P(sum[d],d));
			if(pos[d]<gt[d].size()) gd.insert(P(gt[d][pos[d]],d));
		}
		st.insert(P(sum[c],c));
	}
	printf("%I64d\n",get(ct,-1,0)*2LL);
	for(int i=0;i<n;i++)
	{
		if(i!=0) printf(" ");
		printf("%d",gl[i]+1);
	}puts("");
	return 0;
}