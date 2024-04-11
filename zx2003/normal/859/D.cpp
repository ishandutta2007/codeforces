#include<cstdio>
int n,i,j,b[70][70],m,k,l,be,en;
double p[70][70],x,c[70][70],f[70][70],ma[70][70];
int main(){
	scanf("%d",&n);m=1<<n;
	for(i=0;i<m;++i)
		for(j=0;j<m;++j)scanf("%d",b[i]+j),c[i][j]=b[i][j]*1.0/100;
	for(i=0;i<m;++i)p[1][i]=1;
	for(i=2;i<=n+1;++i)
		for(j=0;j<m;j+=1<<(i-1))
			for(k=j;k<j+(1<<(i-1));++k){
				if(k>=j+(1<<(i-2)))be=j,en=j+(1<<(i-2));
					else be=j+(1<<(i-2)),en=j+(1<<(i-1));
				for(l=be,x=0;l<en;++l)
					if(k!=l)x+=c[k][l]*p[i-1][l];
				p[i][k]=x*p[i-1][k];
				f[i][k]=p[i][k]*(1<<(i-2))+ma[i-1][be]+f[i-1][k];
				if(f[i][k]>ma[i][j])ma[i][j]=f[i][k];
			}
	printf("%.10f\n",ma[n+1][0]);
	return 0;
}