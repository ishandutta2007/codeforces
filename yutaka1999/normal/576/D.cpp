#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 155
#define INF 1500000005
#define MX 60

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
typedef pair <int,P> PP;

bool fr[SIZE][SIZE];
bool dp[SIZE][SIZE];
bool cur[SIZE][SIZE];
bool reach[SIZE],nxt[SIZE];
ll memoA[SIZE][SIZE/MX+2];
ll memoB[SIZE][SIZE/MX+2];
vector <int> vec[SIZE];
int dist[SIZE];
PP edge[SIZE];
int n,m;

void calc(bool A[SIZE][SIZE],bool B[SIZE][SIZE])
{
	memset(memoA,0,sizeof(memoA));
	memset(memoB,0,sizeof(memoB));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++) if(B[i][j]) memoB[i][j/MX]|=1LL<<(j%MX);
	}
	memset(cur,false,sizeof(cur));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(A[i][j])
			{
				for(int k=0;k<=(n-1)/MX;k++) memoA[i][k]|=memoB[j][k];
			}
		}
		for(int j=0;j<n;j++) cur[i][j]=(memoA[i][j/MX]>>(j%MX)&1);
	}
}
void make(int L)
{
	if(L==0)
	{
		memset(dp,false,sizeof(dp));
		for(int i=0;i<n;i++) dp[i][i]=true;
		return;
	}
	make(L/2);
	calc(dp,dp);
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) dp[i][j]=cur[i][j];
	if(L%2==1)
	{
		calc(dp,fr);
		for(int i=0;i<n;i++) for(int j=0;j<n;j++) dp[i][j]=cur[i][j];
	}
}
void build_dist(int goal)
{
	memset(dist,-1,sizeof(dist));
	dist[goal]=0;
	queue <int> que;
	que.push(goal);
	while(!que.empty())
	{
		int v=que.front();que.pop();
		for(int i=0;i<vec[v].size();i++)
		{
			int to=vec[v][i];
			if(dist[to]==-1)
			{
				dist[to]=dist[v]+1;
				que.push(to);
			}
		}
	}
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int a,b,d;
		scanf("%d %d %d",&a,&b,&d);a--;b--;
		edge[i]=PP(d,P(a,b));
	}
	sort(edge,edge+m);
	reach[0]=true;
	int ret=INF;
	int now=0;
	for(int i=0;i<m;i++)
	{
		build_dist(n-1);
		for(int j=0;j<n;j++)
		{
			if(reach[j]&&dist[j]!=-1)
			{
				ret=min(ret,now+dist[j]);
			}
		}
		PP p=edge[i];
		if(p.first>ret) break;
		int start=p.second.first,end=p.second.second;
		make(p.first-now);
		for(int i=0;i<n;i++)
		{
			nxt[i]=false;
			for(int j=0;j<n;j++) if(reach[j]&&dp[j][i]) nxt[i]=true;
		}
		for(int i=0;i<n;i++) reach[i]=nxt[i];
		fr[start][end]=true;
		vec[end].push_back(start);
		now=p.first;
	}
	build_dist(n-1);
	for(int j=0;j<n;j++)
	{
		if(reach[j]&&dist[j]!=-1)
		{
			ret=min(ret,now+dist[j]);
		}
	}
	if(ret==INF) puts("Impossible");
	else printf("%d\n",ret);
	return 0;
}