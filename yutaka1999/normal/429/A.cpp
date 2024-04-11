#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 100005
#define INF 1000000000

using namespace std;

vector <int> vec[SIZE];
vector <int> ans;
int in[SIZE];

void dfs(int v=0,int p=-1,int odd=0,int even=0)
{
	if((in[v]+odd)%2==1)
	{
		odd++;
		ans.push_back(v);
	}
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p)
		{
			dfs(to,v,even,odd);
		}
	}
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
	for(int i=0;i<n;i++) scanf("%d",&in[i]);
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		in[i]=(a-in[i]+2)%2;
	}
	dfs();
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++) printf("%d\n",ans[i]+1);
	return 0;
}