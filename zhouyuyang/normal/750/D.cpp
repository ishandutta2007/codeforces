#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
struct orz{
	int x,y,w,z;
}q[1000005];
int c[8][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
int a[35],v[305][305][32][8],map[305][305];
int n,h,t,x,y,w,z,ans;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	h=0; t=1;
	q[1].x=150; q[1].y=150; q[1].w=0; q[1].z=0;
	v[150][150][0][0]=1;
	while (h!=t){
		h=h%1000005+1;
		x=q[h].x;
		y=q[h].y;
		w=q[h].w+1;
		z=q[h].z;
		if (w>n) continue;
		for (int i=1;i<=a[w];i++){
			x+=c[z][0];
			y+=c[z][1];
			map[x][y]=1;
		}
		if (!v[x][y][w][(z+1)%8]){
			t=t%1000005+1;
			q[t].x=x;
			q[t].y=y;
			q[t].w=w;
			q[t].z=(z+1)%8;
			v[x][y][w][(z+1)%8]=1;
		}
		if (!v[x][y][w][(z+7)%8]){
			t=t%1000005+1;
			q[t].x=x;
			q[t].y=y;
			q[t].w=w;
			q[t].z=(z+7)%8;
			v[x][y][w][(z+7)%8]=1;
		}
	}
	ans=0;
	for (int i=0;i<301;i++)
		for (int j=0;j<301;j++) ans+=map[i][j];
	printf("%d",ans);
	return 0;
}