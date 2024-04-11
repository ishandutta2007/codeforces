#include <bits/stdc++.h>
#define SIZE 200005
using namespace std;
typedef pair <int,int> P;

int par[SIZE],dep[SIZE];
vector <int> ans,ord;
vector <int> vec[SIZE];
void dfs(int v,int g)
{
	ans.push_back(g);
	int bef=g;
	for(int i=0;i<vec[v].size();i++)
	{
		dfs(vec[v][i],bef);
		bef=vec[v][i];
	}
	ord.push_back(v);
}
int main()
{
	int n;
	scanf("%d",&n);
	dep[0]=0;
	P mx=P(-1,-1);
	par[0]=-1;
	for(int i=1;i<n;i++)
	{
		scanf("%d",&par[i]);
		dep[i]=dep[par[i]]+1;
		mx=max(mx,P(dep[i],i));
		vec[par[i]].push_back(i);
	}
	int v=mx.second;
	vector <int> vx;
	while(v!=-1)
	{
		vx.push_back(v);
		v=par[v];
	}
	reverse(vx.begin(),vx.end());
	ord.push_back(vx[vx.size()-1]);
	for(int i=vx.size()-2;i>=0;i--)
	{
		int v=vx[i];
		int bef=vx[i+1];
		for(int j=0;j<vec[v].size();j++)
		{
			int to=vec[v][j];
			if(to!=vx[i+1])
			{
				dfs(to,bef);
				bef=to;
			}
		}
		ord.push_back(v);
	}
	reverse(ord.begin(),ord.end());
	for(int i=0;i<n;i++) printf("%d ",ord[i]);puts("");
	printf("%d\n",ans.size());
	reverse(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);puts("");
	return 0;
}