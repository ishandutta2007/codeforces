#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#define SIZE 200005

using namespace std;
typedef pair <int,int> P;

vector <int> vec[SIZE];
vector <P> vx;
int ans[SIZE];
int deg[SIZE];
bool use[SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int unknown=m;
	for(int i=0;i<n;i++)
	{
		vx.clear();
		for(int j=0;j<m;j++)
		{
			int a;
			scanf("%d",&a);
			if(a!=-1) vx.push_back(P(a,j));
		}
		sort(vx.begin(),vx.end());
		bool up=true;
		for(int j=0;j<vx.size();)
		{
			int now=vx[j].first;
			for(;j<vx.size()&&now==vx[j].first;j++)
			{
				int id=vx[j].second;
				if(!up)
				{
					vec[unknown].push_back(id);
					deg[id]++;
				}
				vec[id].push_back(unknown+1);
				deg[unknown+1]++;
			}
			up=false;
			unknown++;
		}
	}
	int pos=0;
	queue <int> que;
	for(int i=0;i<m;i++)
	{
		if(deg[i]==0&&!use[i])
		{
			que.push(i);
			while(!que.empty())
			{
				int v=que.front();que.pop();
				if(v<m) ans[pos++]=v;
				use[v]=true;
				for(int i=0;i<vec[v].size();i++)
				{
					int to=vec[v][i];
					deg[to]--;
					if(deg[to]==0) que.push(to);
				}
			}
		}
	}
	if(pos==m)
	{
		for(int i=0;i<m;i++)
		{
			if(i!=0) printf(" ");
			printf("%d",ans[i]+1);
		}puts("");
	}
	else puts("-1");
	return 0;
}