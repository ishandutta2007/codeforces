#include<cstdio>
const int N=100005;
int n,q,a[15][105][105],i,j,k,c,t,x1,y1,x2,y2,s[N],x[N],y[N];
int main(){
	scanf("%d%d%d",&n,&q,&c);
	for(i=1;i<=n;++i)scanf("%d%d%d",x+i,y+i,s+i);
	for(i=0;i<=c;++i){
		for(j=1;j<=n;++j)a[i][x[j]][y[j]]+=s[j];
		for(j=1;j<=100;++j)
			for(k=1;k<=100;++k)a[i][j][k]+=a[i][j-1][k]+a[i][j][k-1]-a[i][j-1][k-1];
		for(j=1;j<=n;++j)s[j]=s[j]==c?0:s[j]+1;
	}
	while(q--){
		scanf("%d%d%d%d%d",&t,&x1,&y1,&x2,&y2);
		k=t%(c+1);
		printf("%d\n",a[k][x2][y2]-a[k][x1-1][y2]-a[k][x2][y1-1]+a[k][x1-1][y1-1]);
	}
	return 0;
}