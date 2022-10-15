#include <cstdio>
const int harry=1e9+7,N=2e5+10;
int n,a[N],prd[N<<1],inv[N<<1];
long long ans;
inline int C(int n,int m){return (long long)prd[n]*inv[m]%harry*inv[n-m]%harry;}
int legal(int x,int y){return y>=a[x];}
int query(int x,int y){return C(x+y,x);}
int qpow(int b,int p){
	int pw=1,rs=1,nw=b,rm=p;
	for(;rm;pw<<=1,nw=(long long)nw*nw%harry)if(rm&pw)rm^=pw,rs=(long long)rs*nw%harry;
	return rs;
}
int main(){
	n=2e5,prd[0]=inv[0]=1;
	for(int i=1;i<=(n<<1);++i)prd[i]=(long long)prd[i-1]*i%harry;
	inv[n<<1]=qpow(prd[n<<1],harry-2);
	for(int i=(n<<1)-1;i;--i)inv[i]=(long long)inv[i+1]*(i+1)%harry;
	scanf("%d",&n);
	for(int i=0;i<=n;++i)scanf("%d",&a[i]);
	while(!a[n])--n;
	for(int i=0;i<=n;++i)for(int j=a[i]-1;j>=a[i+1]-1&&j>=0;--j)ans+=query(i,j)*(legal(i+1,j)+legal(i,j+1));
	if(n>=0)printf("%lld",(ans+harry-1)%harry);
	else puts("0");
	return 0;
}