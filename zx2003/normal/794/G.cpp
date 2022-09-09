#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5,mo=1e9+7;
char c[N],d[N];
int n,i,j,k,lc,ld,ca,cb,cw,da,db,dw;
int fac[N],vf[N],inv[N],mi[N],ans;
inline int C(int n,int m){return 1ll*vf[m]*vf[n-m]%mo*fac[n]%mo;}
inline int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main(){
	for(i=mi[1]=2,*fac=*vf=fac[1]=vf[1]=inv[1]=*mi=1;i<N;++i)
		fac[i]=1ll*fac[i-1]*i%mo,
		inv[i]=1ll*inv[mo%i]*(mo-mo/i)%mo,
		vf[i]=1ll*vf[i-1]*inv[i]%mo,
		mi[i]=2ll*mi[i-1]%mo;
	scanf("%s%s%d",c+1,d+1,&n);
	lc=strlen(c+1);ld=strlen(d+1);
	for(i=1;i<=lc;++i)if(c[i]!='?')(c[i]=='A'?ca:cb)++;else cw++;
	for(i=1;i<=ld;++i)if(d[i]!='?')(d[i]=='A'?da:db)++;else dw++;
	int ww=0;
	if(lc==ld)for(i=ww=1;i<=lc;++i)if(c[i]==d[i])ww=ww*(c[i]=='?'?2:1)%mo;
		else ww*=c[i]=='?' || d[i]=='?'?1:0;
	ans=1ll*(mi[n+1]-2)*(mi[n+1]-2)%mo*ww%mo;
	for(i=0;i<=cw+dw;++i){
		int w=C(cw+dw,i),x=cw-i,y=cw-dw-x;
		x=ca-da+x;y=cb-db+y;
		if(1ll*x*y>0)continue;
		x=abs(x);y=abs(y);
		if(!x && !y){
			static long long a[N];int s=0;
			for(j=1;j<=n;++j)a[j]=1ll*(n/j)*(n/j);
			for(j=n;j;--j)for(k=j*2;k<=n;k+=j)a[j]-=a[k];
			for(j=1;j<=n;++j)s=(s+a[j]%mo*mi[j])%mo;
			ans=(ans+1ll*(w+mo-ww)*s)%mo;
			continue;
		}
		if(!x || !y)continue;
		ans=(ans+1ll*w*(mi[n/(max(x,y)/gcd(x,y))+1]-2))%mo;
	}
	printf("%d\n",(ans%mo+mo)%mo);
	return 0;
}