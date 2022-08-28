#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#define SIZE 105

using namespace std;

vector <int> vec[SIZE];
bool use[SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	if(n!=m)
	{
		puts("NO");
		return 0;
	}
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		vec[b].push_back(a);
		vec[a].push_back(b);
	}
	queue <int> que;
	use[0]=true;
	que.push(0);
	while(!que.empty())
	{
		int v=que.front();que.pop();
		for(int i=0;i<vec[v].size();i++)
		{
			int to=vec[v][i];
			if(!use[to])
			{
				use[to]=true;
				que.push(to);
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(!use[i])
		{
			puts("NO");
			return 0;
		}
	}
	puts("FHTAGN!");
	return 0;
}