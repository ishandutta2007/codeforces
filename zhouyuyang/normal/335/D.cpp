#include<bits/stdc++.h>
#define For(i,j,k) for (int i=j;i<=k;i++)
#define y1 wzpakking
using namespace std;
const int N=3005;
const int M=100005;
int X[M],Y[M],n;
int sum[N][N];
int f1[N][N];
int f2[N][N];
int main(){
	scanf("%d",&n);
	For(i,1,n){
		int x1,x2,y1,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		For(x,x1+1,x2) For(y,y1+1,y2) sum[x][y]++;
		For(x,x1+1,x2) f2[x][y1+1]=f2[x][y2+1]=1;
		For(y,y1+1,y2) f1[x1+1][y]=f1[x2+1][y]=1;
		X[i]=x1+1; Y[i]=y1+1;
	}
	For(i,1,3001) For(j,1,3001)
		sum[i][j]+=sum[i][j-1],f1[i][j]+=f1[i][j-1];
	For(i,1,3001) For(j,1,3001)
		sum[i][j]+=sum[i-1][j],f2[i][j]+=f2[i-1][j];
	For(i,1,n){
		int x=X[i],y=Y[i],t=1;
		for (;;){
			if (sum[x][y]-sum[X[i]-1][y]-sum[x][Y[i]-1]+sum[X[i]-1][Y[i]-1]!=t*t) break;
			if (f1[X[i]][y]==f1[X[i]][y-1]) break;
			if (f2[x][Y[i]]==f2[x-1][Y[i]]) break;
			if (f1[x+1][y]-f1[x+1][Y[i]-1]==t)
				if (f2[x][y+1]-f2[X[i]-1][y+1]==t){
					int tot=0;
					For(j,1,n)
						if (X[i]<=X[j]&&X[j]<=x)
							if (Y[i]<=Y[j]&&Y[j]<=y)
								tot++;
					printf("YES %d\n",tot);
					For(j,1,n)
						if (X[i]<=X[j]&&X[j]<=x)
							if (Y[i]<=Y[j]&&Y[j]<=y)
								printf("%d ",j);
					exit(0);
				}
			x++; y++; t++;
		}
	}
	puts("NO");
}