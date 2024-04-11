#include <bits/stdc++.h>

using namespace std;

const int maxnode = 30000 + 5;
const int maxedge = 2100000 + 5;
const int oo = 1000000000;
int node, src, dest, nedge;
int head[maxnode], point[maxedge], nxt[maxedge], flow[maxedge],
capa[maxedge];
int dist[maxnode], Q[maxnode], work[maxnode];
void init(int _node, int _src, int _dest) {
node = _node;
src = _src;
dest = _dest;
for (int i = 0; i < node; i++)
head[i] = -1;
nedge = 0;
}
void addedge(int u, int v, int c1, int c2) {
point[nedge] = v, capa[nedge] = c1, flow[nedge] = 0,
nxt[nedge] = head[u], head[u] =(nedge++);
point[nedge] = u, capa[nedge] = c2, flow[nedge] = 0,
nxt[nedge] = head[v], head[v] =(nedge++);
}
bool dinic_bfs() {
memset(dist, 255, sizeof(dist));
dist[src] = 0;
int sizeQ = 0;
Q[sizeQ++] = src;
for (int cl = 0; cl < sizeQ; cl++)
for (int k = Q[cl], i = head[k]; i >= 0; i = nxt[i])
if (flow[i] < capa[i] && dist[point[i]] < 0) {
dist[point[i]] = dist[k] + 1;
Q[sizeQ++] = point[i];
}
return dist[dest] >= 0;
}
int dinic_dfs(int x, int exp) {
if (x == dest)
return exp;
for (int &i = work[x]; i >= 0; i = nxt[i]) {
int v = point[i], tmp;
if (flow[i] < capa[i] && dist[v] == dist[x] + 1 && (tmp = dinic_dfs(v, min(exp, capa[i] - flow[i]))) > 0) {
flow[i] += tmp;
flow[i ^ 1] -= tmp;
return tmp;
}
}
return 0;
}
int dinic_flow() {
int result = 0;
while (dinic_bfs()) {
for (int i = 0; i < node; i++)
work[i] = head[i];
while (1) {
int delta = dinic_dfs(src, oo);
if (delta == 0)
break;
result += delta;
}
}
return result;
}

const int N=605;

int n,m,k;
int a[N],b[N],d[N];
vector<int> ans[N];
int res[N];

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&n,&m,&k);
		for(int i=0;i<n;i++) {ans[i].clear(); d[i]=0;}
		for(int i=0;i<m;i++)
		{
			scanf("%d %d",&a[i],&b[i]);
			a[i]--; b[i]--;
			d[a[i]]++; d[b[i]]++;
		}
		init(n+m+2,0,1);
		int ED=2,ND=2+m;
		for(int i=0;i<m;i++)
		{
			addedge(0,i+ED,1,0);
		}
		for(int i=0;i<m;i++)
		{
			addedge(i+ED,a[i]+ND,1,0);
			addedge(i+ED,b[i]+ND,1,0);
		}
		int cur=0;
		for(int i=0;i<n;i++)
		{
			addedge(i+ND,1,max(2*(d[i]-k),0),0);
			cur+=max(2*(d[i]-k),0);
		}
		int fl=dinic_flow();
		if(fl<cur)
		{
			for(int i=0;i<m;i++)
				printf("0%c"," \n"[i==m-1]);
			continue;
		}
		int ed=0;
		for(int i=2*m;i<2*m+4*m;i+=4)
		{
			if(flow[i])
			{
				ans[a[ed]].push_back(ed);
			}
			else if(flow[i+2])
			{
				ans[b[ed]].push_back(ed);
			}
			else
			{
				res[ed]=1000+ed;
			}
			ed++;
		}
		int curc=1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j+1<ans[i].size();j+=2)
			{
				res[ans[i][j]]=res[ans[i][j+1]]=curc;
				curc++;
			}
		}
		for(int i=0;i<m;i++)
			printf("%d%c",res[i]," \n"[i==m-1]);
	}
}