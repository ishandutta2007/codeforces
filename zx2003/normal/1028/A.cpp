#include<bits/stdc++.h>
int n,m,i,j,mnx,mny,mxx,mxy;
char c[199][199];
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%s",c[i]+1);
	for(i=1;i<=n;++i)for(j=1;j<=m;++j)if(c[i][j]=='B')mxx=i,mxy=j;
	for(i=n;i;--i)for(j=m;j;--j)if(c[i][j]=='B')mnx=i,mny=j;
	printf("%d %d\n",mnx+mxx>>1,mny+mxy>>1);
}