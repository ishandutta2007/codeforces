#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <functional>
#include <deque>
#include <cassert>
#define SIZE 500005
#define INF 1000000005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
typedef pair <P,P> PP;

struct edge
{
	int to,l,r,rev;
	edge(int to=0,int l=0,int r=0,int rev=-1):to(to),l(l),r(r),rev(rev){}
};
vector <edge> vec[SIZE];
vector <int> dp[SIZE][2];
set <P> zan[SIZE][2];
set <P>::iterator it;

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	if(n==1)
	{
		puts("0");
		return 0;
	}
	for(int i=0;i<m;i++)
	{
		int a,b,l,r;
		scanf("%d %d %d %d",&a,&b,&l,&r);a--,b--;
		int S=vec[a].size(),T=vec[b].size();
		vec[a].push_back(edge(b,l,r,T));
		vec[b].push_back(edge(a,l,r,S));
	}
	for(int i=0;i<n;i++)
	{
		for(int t=0;t<2;t++)
		{
			dp[i][t].resize(vec[i].size(),INF);
			for(int j=0;j<vec[i].size();j++)
			{
				int L=vec[i][j].l;
				if(L%2!=t) L++;
				zan[i][t].insert(P(L,j));
			}
		}
	}
	priority_queue <PP,vector <PP>,greater <PP> > que;
	for(int i=0;i<vec[0].size();i++)
	{
		edge e=vec[0][i];
		if(e.l==0)
		{
			dp[0][0][i]=0;
			que.push(PP(P(0,0),P(0,i)));
		}
	}
	while(!que.empty())
	{
		PP p=que.top();que.pop();
		int v=p.first.second,d=p.second.first,id=p.second.second;
		if(dp[v][d][id]<p.first.first) continue;
		int rv=vec[v][id].rev,to=vec[v][id].to;
		int vl=dp[v][d][id];
		if(dp[to][1-d][rv]>vl+1&&vec[v][id].l<=vl&&vl+1<=vec[v][id].r)
		{
			dp[to][1-d][rv]=vl+1;
			que.push(PP(P(vl+1,to),P(1-d,rv)));
		}
		int end=vec[v][id].r;
		if(end%2!=d) end--;
		if(vl>end) continue;
		while(!zan[v][d].empty())
		{
			it=zan[v][d].begin();
			int idx=it->second;
			int l=it->first;
			if(l>end) break;
			int dt=max(l,vl);
			if(dp[v][d][idx]>dt)
			{
				dp[v][d][idx]=dt;
				que.push(PP(P(dt,v),P(d,idx)));
			}
			zan[v][d].erase(it);
		}
	}
	int ret=INF;
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<vec[n-1].size();j++)
		{
			ret=min(ret,dp[n-1][i][j]);
		}
	}
	if(ret==INF) ret=-1;
	printf("%d\n",ret);
	return 0;
}