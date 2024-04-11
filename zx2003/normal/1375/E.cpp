#include<bits/stdc++.h>
const int N=1005;
int n,a[N],i,j,c[N],xb,m;
bool b[N][N];
int main(){
	scanf("%d",&n);for(i=1;i<=n;++i)scanf("%d",a+i);
	for(i=1;i<n;++i)for(j=i+1;j<=n;++j)m+=b[i][j]=a[i]>a[j];
	printf("%d\n",m);
	for(i=1;i<=n;++i){
		xb=0;for(j=i+1;j<=n;++j)if(b[i][j])c[++xb]=j;
		std::sort(c+1,c+xb+1,[&](int x,int y){return x<y?!b[x][y]:b[y][x];});
		for(j=xb;j;--j)printf("%d %d\n",i,c[j]),std::swap(a[i],a[c[j]]);
	}
}