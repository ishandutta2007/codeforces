

#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int mo=1000000007;
int b[120],a[120],i,n,p,j,tot,lmax,rmax,l,r,f[1200][4],g[4],k;
int mel(int x,int y){
	for(int i=0;i<=2;++i)if(x!=i && y!=i)return i;
}
int calc(int x,int y){
	int r=p-x,l=p-y;
	return (long long)(l+r)*(r-l+1)/2%mo;
}
int main(){
	tot=1;
	a[tot]=2; b[tot]=0;
	scanf("%d%d",&n,&p);
	l=r=1;
	while(a[tot]<p){
		lmax=(a[l]+1)*3-1;
		if(a[r]&1)rmax=(a[r]-1)/2*3+1;
		else rmax=a[r]/2*3;
		
		b[++tot]=mel(b[l],b[r]);
		if(b[tot]==b[tot-1])tot--;
		a[tot]=min(rmax,lmax);
		if(lmax==a[tot])l++;
		if(rmax==a[tot])r++;
	}
	for(i=1;i<=tot;++i){
		if(i!=tot)g[b[i]]=(g[b[i]]+calc(a[i-1]+1,a[i]))%mo;
		else g[b[i]]=(g[b[i]]+calc(a[i-1]+1,p))%mo;
	}
	f[0][0]=1;
	for(i=1;i<=n;++i){
		for(j=0;j<=3;++j)
			for(k=0;k<=2;++k)f[i][j^k]=((long long)f[i-1][j]*g[k]+f[i][j^k])%mo;
	}
	printf("%d\n",((long long)f[n][1]+f[n][2]+f[n][3])%mo);
}