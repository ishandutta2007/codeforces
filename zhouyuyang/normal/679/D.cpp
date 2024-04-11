#include<bits/stdc++.h>
#define For(i,j,k) for (int i=j;i<=k;i++)
using namespace std;
const int N=405;
double b[N],c[N];
int f[N][N],q[N];
int n,m;
double s;
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) For(j,1,n)
		f[i][j]=(i==j?0:1e8);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		f[x][y]=f[y][x]=1;
	}
	For(k,1,n) For(i,1,n) For(j,1,n)
		f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	For(i,1,n){
		double r=0;
		For(j,0,n-1){
			double t=0; int u=0;
			memset(b,0,sizeof(b));
			For(k,1,n) if (f[i][k]==j){
				u++; int v=0;
				For(l,1,n)
					if (f[k][l]==1) v++;
				For(l,1,n)
					if (f[k][l]==1)
						b[l]+=1.0/v;
			}
			int p=0;
			For(k,1,n)
				if (abs(f[i][k]-j)<=1)
					p++,q[p]=k;
			For(k,1,n){
				double w=0;
				For(l,1,p)
					if (b[q[l]]>c[f[k][q[l]]]){
						w-=c[f[k][q[l]]];
						w+=(c[f[k][q[l]]]=b[q[l]]);
					}
				For(l,1,p)
					c[f[k][q[l]]]=0;
				t=max(t,w);
			}
			if (u)
				t=max(t,1.0);
			r+=t/n;
		}
		s=max(s,r);
	}
	printf("%.12lf\n",s);
}