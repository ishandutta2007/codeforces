#include <bits/stdc++.h>
using namespace std;
#define N 1010
#define rep(x, a, b) for(int x=a; x<=b; x++)
int n, p[N][N], vis[N];
double A[N], B[N], ex[N];
int main(){
	scanf("%d", &n);
	rep(i, 1, n) rep(j, 1, n) scanf("%d", &p[i][j]);
	rep(i, 1, n-1) ex[i]=1e9, A[i]=B[i]=1; ex[n]=0;
	rep(x, 1, n)
	{
		double mn=1e60; int u;
		rep(i, 1, n)
			if(!vis[i] && mn>ex[i])
				mn=ex[i], u=i;
		vis[u]=1;
		rep(v, 1, n) if(!vis[v])
		{
			B[v]+=p[v][u]/100.*A[v]*ex[u];
			A[v]=A[v]*(1-p[v][u]/100.);
			ex[v]=B[v]/(1-A[v]);
		}
	}
	printf("%.15lf\n", ex[1]);
}