#include<bits/stdc++.h>
#define For(i,j,k) for (int i=j;i<=k;i++)
#define N 1005
using namespace std;
short mx[10][10][N][N];
int bit[N],a[N][N],f[N][N];
int ask(int x1,int x2,int y1,int y2){
	int bx=bit[x2-x1+1],by=bit[y2-y1+1];
	return max(
		max(mx[bx][by][x1][y1],mx[bx][by][x1][y2-(1<<by)+1]),
		max(mx[bx][by][x2-(1<<bx)+1][y1],mx[bx][by][x2-(1<<bx)+1][y2-(1<<by)+1])
	);
} 
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	For(i,1,n) For(j,1,m) scanf("%d",&a[i][j]);
	For(i,1,n) For(j,1,m) if (a[i][j])
		f[i][j]=min(min(f[i-1][j],f[i][j-1]),f[i-1][j-1])+1;
	For(i,1,n) For(j,1,m)
		mx[0][0][i][j]=f[i][j];
	For(t1,0,9){
		if (t1){
			For(i,1,n-(1<<t1)+1) For(j,1,m)
				mx[t1][0][i][j]=max(mx[t1-1][0][i][j],mx[t1-1][0][i+(1<<(t1-1))][j]);
		}
		For(t2,1,9) For(i,1,n) For(j,1,m-(1<<t2)+1)
			mx[t1][t2][i][j]=max(mx[t1][t2-1][i][j],mx[t1][t2-1][i][j+(1<<(t2-1))]);
	}
	For(i,2,N-1) bit[i]=bit[i>>1]+1;
	int q; scanf("%d",&q);
	while (q--){
		int x1,x2,y1,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		int L=min(x2-x1+1,y2-y1+1),ans=0;
		for (int j=9;j>=0;j--)
			if (ans+(1<<j)<=L&&ask(x1+ans+(1<<j)-1,x2,y1+ans+(1<<j)-1,y2)>=ans+(1<<j))
				ans+=(1<<j);
		printf("%d\n",ans);
	}
	
}