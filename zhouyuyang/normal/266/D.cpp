

#include <cstdio>
#include <algorithm>
using namespace std;
const int N=205;
typedef pair<int,int> pii;
int n,m,ans=1e9+7,g[N][N];
pii q[N];
struct edge{
	int a,b,w;
	void read(){
		scanf("%d%d%d",&a,&b,&w);
		g[a][b]=g[b][a]=w;
	}
	void work(){
		for(int i=1;i<=n;i++) q[i]=pii(g[a][i],g[b][i]);
		sort(q+1,q+n+1);
		int p=n;
		int now=q[p].first*2;
		for(int j=n-1;j>=1;j--) if(q[j].first<q[p].first&&q[j].second>q[p].second)
			now=min(now,q[p].second+q[j].first+w),p=j;
		now=min(now,q[p].second*2);
		ans=min(ans,now);
	}
} e[N*N];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			g[i][j]=i==j?0:1e9+7;
	for(int i=0;i<m;i++)
		e[i].read();
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	for(int i=0;i<m;i++)
		e[i].work();
	printf("%.12lf\n",ans/2.);
}