#include<bits/stdc++.h>
using namespace std;
const int N=1005;
bool a[N][N],b[N][N];
int n,Q,S;
int Qx[N],Qy[N],Sx[N];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n-3;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		a[x][y]=a[y][x]=1;
	}
	for (int i=1;i<=n-3;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		b[x][y]=b[y][x]=1;
	}
	for (int i=2;i<=n;i++)
		for (int j=n;j>=i+2;j--)
			if (a[i][j]){
				Qx[++Q]=i; Qy[Q]=j;
				a[i][j]=a[j][i]=0;
			}
	for (int i=2;i<=n;i++)
		for (int j=n;j>=i+2;j--)
			if (b[i][j]){
				int k;
				for (k=j-1;k>i;k--)
					if (b[i][k]||k==i+1) break;
				Sx[++S]=k;
				b[i][j]=b[j][i]=0;
				b[1][Sx[S]]=b[Sx[S]][1]=1;
			}
	printf("%d\n",Q+S);
	for (int i=1;i<=Q;i++)
		printf("%d %d\n",Qx[i],Qy[i]);
	for (int i=S;i;i--) printf("1 %d\n",Sx[i]);
}