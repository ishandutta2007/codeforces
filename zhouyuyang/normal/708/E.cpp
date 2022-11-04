#include<bits/stdc++.h>
#define N 1503
#define K 100005
#define M 1000000007
using namespace std;
typedef long long ll;
int n,m,a,k;
ll ji[K],inv[K],p[N],Sp[N],Ss[N],sum[N],q,now[N];
inline ll ksm(ll x,int y){
    ll s=1;
    for (;y;y/=2,x=x*x%M)
    	if (y&1) s=s*x%M;
    return s;
}
int main(){
	scanf("%d%d%lld%d%d",&n,&m,&q,&a,&k);
	ji[0]=inv[0]=1;
	q=q*ksm(a,M-2)%M;
	for(int i=1;i<=k;i++){
    	ji[i]=ji[i-1]*i%M;
		inv[i]=inv[i-1]*ksm(i,M-2)%M;
	}
    for(int i=0;i<=min(k,m);i++)
    	p[i]=ksm(q,i)*ksm(1-q,k-i)%M*ji[k]%M*inv[i]%M*inv[k-i]%M;
    Sp[0]=p[0];
    for(int i=1;i<=m;i++)
   		Sp[i]=(Sp[i-1]+p[i])%M;
    sum[m]=1,Ss[m]=p[m];
    for(int i=1;i<=n;i++){
        now[0]=0;
        for(int j=1;j<=m;j++)
        	now[j]=(now[j-1]+p[m-j]*(Sp[j-1]*(sum[m]-sum[m-j])%M-Ss[j-1])%M)%M;
        for(int j=1;j<=m;j++)
        	sum[j]=now[j],Ss[j]=(Ss[j-1]+sum[j]*p[j])%M;
    }
    printf("%lld",(sum[m]+M)%M);
}