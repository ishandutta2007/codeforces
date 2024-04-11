#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define mo 1000000007
using namespace std;
int n,m,q,tp,x,y,t,la,nx,ny,bz[25][25];
const int c[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
struct mat{
	int a[25][25];
	mat(){memset(a,0,sizeof(a));};
	friend mat operator *(mat x,mat y){
		mat z;
		for (int i=1;i<=n*m;i++)
			for (int j=1;j<=n*m;j++)
				for (int k=1;k<=n*m;k++)
					z.a[i][j]=(z.a[i][j]+x.a[i][k]*1ll*y.a[k][j])%mo;
		return z;
	}
	friend mat operator ^(mat x,int y){
		mat s;
		for (int i=1;i<=n*m;i++) s.a[i][i]=1;
		for (;y;y/=2,x=x*x)
			if (y&1) s=s*x;
		return s;
	}
}now;
int poi(int x,int y){
	return (x-1)*m+y;
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	la=1;
	for (int i=1;i<=n*m;i++)
		now.a[i][i]=1;
	for (int i=1;i<=q;i++){
		scanf("%d%d%d%d",&tp,&x,&y,&t);
		mat tmp;
		for (int j=1;j<=n;j++)
			for (int k=1;k<=m;k++){
				for (int p=0;p<4;p++){
					nx=j+c[p][0],ny=k+c[p][1];
					if (nx<1||ny<1||nx>n||ny>m) continue;
					tmp.a[poi(j,k)][poi(nx,ny)]=1-(bz[j][k]||bz[nx][ny]);
				}
				tmp.a[poi(j,k)][poi(j,k)]=1-bz[j][k];
			}
		now=now*(tmp^(t-la));
		if (tp==2) bz[x][y]=1;
		if (tp==3) bz[x][y]=0;
		if (tp==1) printf("%d\n",now.a[1][poi(x,y)]);
		la=t;
	}
}