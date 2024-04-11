#include <bits/stdc++.h>
using namespace std;
const int N=42;
int n,m,q,a[N][N],U[N][N],L[N][N];
int s[N][N][N][N];
int calc(int x){
	return x*(x+1)/2;
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			scanf("%1d",&a[i][j]);
	for (int i=1;i<=n;i++)
		a[i][0]=1;
	for (int i=0;i<=m;i++)
		a[0][i]=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			while (a[i-U[i][j]][j]==0)
				U[i][j]++;
			while (a[i][j-L[i][j]]==0)
				L[i][j]++;
		}
	for (int sx=1;sx<=n;sx++)
		for (int sy=1;sy<=m;sy++)
			for (int ex=sx;ex<=n;ex++)
				for (int ey=sy;ey<=m;ey++){
					int &now=s[sx][sy][ex][ey];
					now=s[sx][sy][ex-1][ey-1];
					int q[N],d[N],v[N],tail=0;
					for (int i=sx;i<ex;i++)
						v[i]=min(L[i][ey],ey-sy+1);
					v[ex]=0;
					q[0]=0,v[0]=0;
//					printf("%d %d %d %d\n",ex,ey,sx,sy);
//					printf("%d\n",now);
					for (int i=sx;i<=ex;i++){
						int dd=i;
						while (tail>0&&v[i]<v[q[tail]]){
							now+=calc(i-d[q[tail]])*(v[q[tail]]-max(v[q[tail-1]],v[i]));
							dd=d[q[tail--]];
						}
						d[i]=dd;
						q[++tail]=i;
					}
//					printf("%d\n",now);
					for (int i=sy;i<=ey;i++)
						v[i]=min(U[ex][i],ex-sx+1);
					v[ey+1]=tail=0;
					for (int i=sy;i<=ey+1;i++){
						int dd=i;
						while (tail>0&&v[i]<v[q[tail]]){
							now+=calc(i-d[q[tail]])*(v[q[tail]]-max(v[q[tail-1]],v[i]));
							dd=d[q[tail--]];
						}
						d[i]=dd;
						q[++tail]=i;
					}
//					printf("%d\n",now);
				}
	while (q--){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		printf("%d\n",s[a][b][c][d]);
	}
	return 0;
}