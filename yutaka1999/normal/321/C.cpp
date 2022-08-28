#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 100005
#define INF 1000000000

using namespace std;
typedef pair <int,int> P;

vector <int> vec[SIZE];
int sum[SIZE];
char ans[SIZE];
bool use[SIZE];
int n;

void make(int v,int p)
{
	sum[v]=1;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p&&!use[to])
		{
			make(to,v);
			sum[v]+=sum[to];
		}
	}
}
P center(int v,int p,int nod)
{
	P ret=P(INF,INF);
	P now=P(0,v);
	int all=1;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p&&!use[to])
		{
			ret=min(ret,center(to,v,nod));
			now.first=max(now.first,sum[to]);
			all+=sum[to];
		}
	}
	now.first=max(now.first,nod-all);
	return min(ret,now);
}
void dfs(int v=0,char tc='A')
{
	make(v,-1);
	int c=center(v,-1,sum[v]).second;
	//printf("[]%d\n",c);
	ans[c]=tc;
	use[c]=true;
	for(int i=0;i<vec[c].size();i++)
	{
		int to=vec[c][i];
		if(!use[to]) dfs(to,tc+1);
	}
	use[c]=false;
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
	for(int i=0;i<n;i++)
	{
		if(i!=0) printf(" ");
		printf("%c",ans[i]);
	}
	puts("");
	return 0;
}