#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 200005

using namespace std;
typedef pair <int,int> P;

vector <P> vec[SIZE];
vector <P> nd[SIZE];
vector <P> var[SIZE];
bool vis[SIZE],D[SIZE];
int ans[SIZE];

int get(int v,int p)
{
	D[v]=true;
	for(int i=0;i<vec[v].size();i++)
	{
		P e=vec[v][i];
		if(e.first!=p)
		{
			if(D[e.first]) return e.second;
			int d=get(e.first,v);
			if(d!=-1) return d;
		}
	}
	return -1;
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		int c;
		scanf("%d",&c);
		for(int j=0;j<c;j++)
		{
			int t;
			scanf("%d",&t);
			var[i].push_back(P(abs(t)-1,t/abs(t)));
			nd[abs(t)-1].push_back(P(i,t/abs(t)));
		}
	}
	memset(vis,false,sizeof(vis));
	memset(ans,0,sizeof(ans));
	queue <int> que;
	for(int i=0;i<m;i++)
	{
		if(nd[i].empty()) continue;
		if(nd[i].size()==1)
		{
			P p=nd[i][0];
			ans[i]=p.second;
			if(!vis[p.first])
			{
				vis[p.first]=true;
				que.push(p.first);
			}
		}
		else
		{
			P p=nd[i][0],q=nd[i][1];
			if(p.second==q.second)
			{
				ans[i]=p.second;
				if(!vis[p.first])
				{
					vis[p.first]=true;
					que.push(p.first);
				}
				if(!vis[q.first])
				{
					vis[q.first]=true;
					que.push(q.first);
				}
			}
		}
	}
	while(!que.empty())
	{
		int v=que.front();que.pop();
		for(int i=0;i<var[v].size();i++)
		{
			P p=var[v][i];
			if(ans[p.first]==0)
			{
				P q=nd[p.first][0];
				if(q.first==v) q=nd[p.first][1];
				ans[p.first]=q.second;
				if(!vis[q.first])
				{
					vis[q.first]=true;
					que.push(q.first);
				}
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		if(ans[i]==0&&!nd[i].empty())
		{
			P p=nd[i][0],q=nd[i][1];
			vec[p.first].push_back(P(q.first,i));
			vec[q.first].push_back(P(p.first,i));
		}
	}
	memset(D,false,sizeof(D));
	for(int i=0;i<n;i++)
	{
		if(!vis[i])
		{
			int g=get(i,-1);
			if(g==-1)
			{
				puts("NO");
				return 0;
			}
			P d=nd[g][0];
			vis[d.first]=true;
			ans[g]=d.second;
			que.push(d.first);
			while(!que.empty())
			{
				int v=que.front();que.pop();
				for(int j=0;j<var[v].size();j++)
				{
					P p=var[v][j];
					if(ans[p.first]==0)
					{
						P q=nd[p.first][0];
						if(q.first==v) q=nd[p.first][1];
						ans[p.first]=q.second;
						if(!vis[q.first])
						{
							vis[q.first]=true;
							que.push(q.first);
						}
					}
				}
			}
		}
	}
	puts("YES");
	for(int i=0;i<m;i++) printf("%d",(ans[i]+1)/2);
	puts("");
	
	return 0;
}