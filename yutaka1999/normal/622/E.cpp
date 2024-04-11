#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 500005

using namespace std;
typedef long long int ll;

vector <int> vec[SIZE];
int nd[SIZE],dep[SIZE];
vector <int> vx;
ll ans;

void dfs(int v,int p=0,int d=0)
{
	dep[v]=d;
	if(vec[v].size()==1) vx.push_back(d);
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p) dfs(to,v,d+1);
	}
}
int get(int v)
{
	vx.clear();
	dfs(v);
	sort(vx.begin(),vx.end());
	int ans=-1;
	for(int i=0;i<vx.size();i++)
	{
		ans++;
		ans=max(ans,vx[i]);
	}
	return ans+1;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	int ans=0;
	for(int i=0;i<vec[0].size();i++)
	{
		int to=vec[0][i];
		ans=max(ans,get(to));
	}
	printf("%d\n",ans);
	return 0;
}