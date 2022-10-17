#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=607;

int n,m;

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

int g[N][N];

ll d[N];

int done[N];

void solve(int x)
{;
	int cnt=0;
	for(int i=0;i<n;i++)
		d[i]=g[x][i],done[i]=0;
	while(cnt<n)
	{
		int p=-1;
		for(int i=0;i<n;i++)
			if(!done[i]&&(p==-1||d[i]<d[p]))
				p=i;
		d[(p+1)%n]=min(d[(p+1)%n],d[p]+1);
		for(int i=0;i<n;i++)
			d[(i+d[p])%n]=min(d[(i+d[p])%n],d[p]+g[p][i]);
		done[p]=1;
		cnt++;
	}
	d[x]=0;
	for(int i=0;i<n;i++)
		printf("%lld ",d[i]);
	puts("");
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			g[i][j]=2e9;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g[u][v]=min(g[u][v],w);
	}
	for(int i=0;i<n;i++)
		solve(i);
}