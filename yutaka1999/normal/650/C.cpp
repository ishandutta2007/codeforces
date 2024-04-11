#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#define SIZE 1000005

using namespace std;
typedef pair <int,int> P;
typedef pair <int,P> PP;

vector < vector <int> > A;
vector < vector <int> > B;
vector <int> vec[SIZE];
int id[SIZE];
bool use[SIZE];
int n,m;

int main()
{
	scanf("%d %d",&n,&m);
	vector <PP> vp;
	for(int i=0;i<n;i++)
	{
		vector <int> vec;
		for(int j=0;j<m;j++)
		{
			int x;
			scanf("%d",&x);
			vec.push_back(x);
			vp.push_back(PP(x,P(i,j)));
		}
		A.push_back(vec);
		B.push_back(vec);
	}
	sort(vp.begin(),vp.end());
	for(int i=0;i<vp.size();)
	{
		int f=i;
		for(;i<vp.size()&&vp[i].first==vp[f].first;i++);
		vector <P> vx;
		for(int j=f;j<i;j++)
		{
			P p=vp[j].second;
			int x=p.first,y=p.second+n;
			vec[x].push_back(y);
			vec[y].push_back(x);
			vx.push_back(P(id[x],x));
			vx.push_back(P(id[y],y));
		}
		sort(vx.begin(),vx.end());
		for(int j=((int) vx.size())-1;j>=0;j--)
		{
			int v=vx[j].second;
			if(!use[v])
			{
				queue <int> que;
				que.push(v);
				while(!que.empty())
				{
					int x=que.front();que.pop();
					id[x]=max(id[x],vx[j].first+1);
					for(int k=0;k<vec[x].size();k++)
					{
						int to=vec[x][k];
						if(!use[to])
						{
							use[to]=true;
							que.push(to);
						}
					}
				}
			}
		}
		for(int j=f;j<i;j++)
		{
			P p=vp[j].second;
			int x=p.first,y=p.second+n;
			B[x][y-n]=max(id[x],id[y]);
			vec[x].clear();
			vec[y].clear();
			use[x]=use[y]=false;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(j!=0) printf(" ");
			printf("%d",B[i][j]);
		}puts("");
	}
	return 0;
}