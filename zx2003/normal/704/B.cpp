#include<bits/stdc++.h>
typedef long long ll;
const int N=5005;
int n,s,e,x[N],a[N],b[N],c[N],d[N],i,j,k,l,nw;
ll f[2][N][2][2];
inline void upi(ll&a,ll b){a>b?a=b:0;}
int main(){
	scanf("%d%d%d",&n,&s,&e);
	for(i=1;i<=n;++i)scanf("%d",x+i);
	for(i=1;i<=n;++i)scanf("%d",a+i),a[i]+=x[i];
	for(i=1;i<=n;++i)scanf("%d",b+i),b[i]-=x[i];
	for(i=1;i<=n;++i)scanf("%d",c+i),c[i]+=x[i];
	for(i=1;i<=n;++i)scanf("%d",d+i),d[i]-=x[i];
	memset(f,1,sizeof f);f[0][0][0][0]=0;nw=0;
	for(i=1;i<=n;++i){
		nw^=1;memset(f[nw],1,sizeof f[nw]);
		for(j=0;j<=i;++j)if(i==s)for(l=0;l<2;++l){
			upi(f[nw][j][1][l],f[!nw][j][0][l]+d[i]);
			if(j)upi(f[nw][j-1][1][l],f[!nw][j][0][l]+c[i]);
			if(l)upi(f[nw][j][0][0],f[!nw][j][0][l]+c[i]);
		}else if(i==e)for(k=0;k<2;++k){
			upi(f[nw][j][k][1],f[!nw][j][k][0]+b[i]);
			if(j)upi(f[nw][j-1][k][1],f[!nw][j][k][0]+a[i]);
			if(k)upi(f[nw][j][0][0],f[!nw][j][k][0]+a[i]);
		}else for(k=0;k<2;++k)for(l=0;l<2;++l){
			ll w;
			w=f[!nw][j][k][l]+a[i]+c[i];
			if(k && l)upi(f[nw][j][0][0],w);
			if((k || l || j>1) && j)upi(f[nw][j-1][k][l],w);
			w=f[!nw][j][k][l]+b[i]+c[i];
			if(j || l)upi(f[nw][j][k][l],w);
			w=f[!nw][j][k][l]+a[i]+d[i];
			if(k || j)upi(f[nw][j][k][l],w);
			w=f[!nw][j][k][l]+b[i]+d[i];
			upi(f[nw][j+1][k][l],w);
		}
	}
	printf("%lld\n",f[nw][0][0][0]);
	return 0;
}