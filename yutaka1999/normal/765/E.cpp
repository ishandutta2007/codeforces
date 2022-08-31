#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 200005

using namespace std;
typedef pair <int,int> P;

vector <int> vec[SIZE];
int memo[SIZE];
bool use[SIZE];
vector <int> vt;
int sz;

P dfs(int v=0,int p=-1,int d=0)
{
	P ret=P(d,v);
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p) ret=max(ret,dfs(to,v,d+1));
	}
	return ret;
}
bool dfs2(int v=0,int p=-1,int r=-1)
{
	memo[sz++]=v;
	use[v]=true;
	if(v==r) return true;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p&&dfs2(to,v,r)) return true;
	}
	use[v]=false;
	sz--;
}
void get_dist(int v,int p=-1,int d=0)
{
	if(vec[v].size()==1&&p!=-1) vt.push_back(d);
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(!use[to]&&to!=p) get_dist(to,v,d+1);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--,b--;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	int l=dfs().second;
	int r=dfs(l).second;
	dfs2(l,-1,r);
	//for(int i=0;i<sz;i++) printf("%d ",memo[i]);puts("");
	for(int i=0;i<sz;i++)
	{
		if(i==sz-i-1) continue;
		int v=memo[i];
		vt.clear();
		get_dist(v);
		for(int j=0;j<vt.size();j++)
		{
			int d=vt[j];
			//printf("%d : %d\n",i,d);
			if(d!=min(i,sz-i-1))
			{
				puts("-1");
				return 0;
			}
		}
	}
	if(sz%2==1)
	{
		int ct=memo[(sz-1)/2];
		int L=-1;
		for(int j=0;j<vec[ct].size();j++)
		{
			if(use[vec[ct][j]]) continue;
			vt.clear();
			get_dist(vec[ct][j],ct,1);
			bool up1=false,up2=false;
			for(int i=0;i<vt.size();i++)
			{
				int d=vt[i];
				if(d!=(sz-1)/2)
				{
					if(L!=d)
					{
						if(L!=-1)
						{
							puts("-1");
							return 0;
						}
						L=d;
					}
					if(L==d) up1=true;
				}
				if(d==(sz-1)/2) up2=true;
			}
			if(up1&&up2)
			{
				puts("-1");
				return 0;
			}
		}
		if(L!=-1) sz=(sz-1)/2+L+1;
	}
	int now=sz-1;
	while(now%2==0) now/=2;
	printf("%d\n",now);
	return 0;
}