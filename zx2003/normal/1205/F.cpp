#include<bits/stdc++.h>
const int N=105;
int q,n,k,i,j,way[N][N*N],tp[N][N*N],l,r,a[N],xb;
int main(){
	way[1][0]=-1;
	for(i=2;i<=100;++i)for(k=i;k<=i*(i+1)/2;++k){
		for(j=2;j<=i;++j)if(k>=j*(j+1)/2-1 && way[i-j+1][k-j*(j+1)/2+1]){
			way[i][k]=j,tp[i][k]=1;
		}
		for(j=4;j<=i;++j)if(way[i-j+1][k-j])
			way[i][k]=j,tp[i][k]=2;
	}
	for(scanf("%d",&q);q--;){
		scanf("%d%d",&n,&k);--k;
		if(!way[n][k]){puts("NO");continue;}
		puts("YES");
		bool rev=0;
		l=1;r=n;
		for(;l<r;){
			j=way[n][k];
			if(tp[n][k]==1){
				if(rev){for(i=r;i>=r-j+2;--i)printf("%d ",i);r=i;}
					else{for(i=l;i<=l+j-2;++i)printf("%d ",i);l=i;}
				rev^=1;k-=j*(j+1)/2-1;
			}else{
				xb=0;
				for(i=l+1;i<=l+j-1;i+=2)a[++xb]=i;for(i=l;i<=l+j-1;i+=2)a[++xb]=i;
				if(j&1)a[j/2]=r-1,a[j-1]=r,r-=2,l+=j-3;
					else a[j/2]=r--,l+=j-2;
				for(i=1;i<xb;++i)printf("%d ",a[i]);k-=j;
			}
			n-=j-1;
		}
		printf("%d\n",l);
	}
	return 0;
}