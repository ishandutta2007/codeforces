#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <functional>
#define SIZE 200005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

vector <int> vec[SIZE];
int nd[SIZE],vt[SIZE];
bool ok[SIZE];
int rt;
int n,k;

void dfs(int v=0,int p=-1)
{
	int mx=-1;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p)
		{
			dfs(to,v);
			nd[v]+=nd[to];
			mx=max(mx,nd[to]);
		}
	}
	mx=max(mx,k-nd[v]);
	if(mx*2<=k) rt=v;
}
ll get(int v,int p,int d)
{
	ll ret=0;
	if(ok[v]) ret+=d;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p) ret+=get(to,v,d+1);
	}
	return ret;
}
int main()
{
	scanf("%d %d",&n,&k);
	k*=2;
	for(int i=0;i<k;i++)
	{
		scanf("%d",&vt[i]);
		vt[i]--;
		nd[vt[i]]++;
		ok[vt[i]]=true;
	}
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	rt=-1;
	dfs();
	printf("%lld\n",get(rt,-1,0));
	return 0;
}