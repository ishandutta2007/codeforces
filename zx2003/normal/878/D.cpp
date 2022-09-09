#include<bits/stdc++.h>
#include<cstdio> 
const int N=100050;
int n,k,q,a[13][N],i,j,b[N][13],xb,o,x,y;
inline bool cmp(int x,int y){return a[x][i]<a[y][i];}
std::bitset<4096> c[N];
int main(){
	scanf("%d%d%d",&n,&k,&q);
	for(i=1;i<=k;++i)
		for(j=1;j<=n;++j){
			scanf("%d",a[i]+j);
			b[j][i]=i;
		}
	for(i=1;i<=n;++i)std::sort(b[i]+1,b[i]+k+1,cmp);
	for(i=1;i<=k;++i)
		for(j=0;j<1<<k;++j)if(j>>(i-1)&1)c[i][j]=1;xb=k;
	while(q--){
		scanf("%d%d%d",&o,&x,&y);
		if(o==1)c[++xb]=c[x]|c[y];
		if(o==2)c[++xb]=c[x]&c[y];
		if(o==3){
			for(i=k,j=0;!c[x][j];j|=1<<(b[y][i--]-1));++i;
			printf("%d\n",a[b[y][i]][y]);
		}
	}
	return 0;
}