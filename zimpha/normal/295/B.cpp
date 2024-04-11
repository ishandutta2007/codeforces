#include <cstdio>
#include <cstdlib>
#include <cstring>
typedef long long LL;
const int MAXN=500+50;
const int inf=100000000;

int map[MAXN][MAXN];
int dis[MAXN][MAXN];
int x[MAXN], n;
LL ans[MAXN];

int main() {
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++) {
			scanf("%d", &map[i][j]);
			dis[i][j]=inf;
		}
	for (int i=1; i<=n; i++) scanf("%d", &x[i]);
	for (int k=n; k>=1; k--) {
		ans[k]=0;
		for (int j=1; j<=n; j++)
		{
			if (dis[x[k]][j]>map[x[k]][j]) dis[x[k]][j]=map[x[k]][j];
			if (dis[j][x[k]]>map[j][x[k]]) dis[j][x[k]]=map[j][x[k]];
		}
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++)
				if (dis[x[i]][x[j]]>dis[x[i]][x[k]]+dis[x[k]][x[j]])
					dis[x[i]][x[j]]=dis[x[i]][x[k]]+dis[x[k]][x[j]];
		for (int i=k; i<=n; i++)
			for (int j=k; j<=n; j++)
				if (i!=j&&dis[x[i]][x[j]]!=inf) ans[k]+=dis[x[i]][x[j]];
	}
	for (int i=1; i<=n; i++)
		printf("%I64d%c", ans[i], (i==n)?'\n':' ');
}