#include<bits/stdc++.h>
const int N=3e5+5,L=20;
int n,q,a[N],i,j,k,f[N][L],lst[L],x,y;
int main(){
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	for(i=0;i<L;++i)lst[i]=n+1;
	for(i=n;i;--i){
		for(j=0;j<L;++j)f[i][j]=n+1;
		for(j=0;j<L;++j)if(a[i]>>j&1){
			if(lst[j]<=n){
				f[i][j]=lst[j];
				for(k=0;k<L;++k)f[i][k]=std::min(f[i][k],f[lst[j]][k]);
			}
			lst[j]=i;
		}
	}
	for(;q--;){
		scanf("%d%d",&x,&y);
		for(i=0;i<L && (!(a[y]>>i&1) || f[x][i]>y);++i);
		puts(i<L?"Shi":"Fou");
	}
	return 0;
}