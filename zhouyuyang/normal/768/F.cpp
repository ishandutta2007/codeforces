#include<bits/stdc++.h>
#define mo 1000000007
#define N 200005
using namespace std;
int fac[N],inv[N];
int n,m,p,ans;
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int C(int x,int y){
	if (x<0||y<0||x<y) return 0;
	return 1ll*fac[x]*inv[y]%mo*inv[x-y]%mo; 
}
int main(){
	fac[0]=inv[0]=inv[1]=1;
	for (int i=2;i<N;i++)
		inv[i]=1ll*(mo-mo/i)*inv[mo%i]%mo;
	for (int i=1;i<N;i++){
		fac[i]=1ll*fac[i-1]*i%mo;
		inv[i]=1ll*inv[i-1]*inv[i]%mo;
	}
	scanf("%d%d%d",&n,&m,&p);
	int tot=C(n+m,n);
	if (!m)
		return puts("1"),0;
	if (!n)
		return printf("%d\n",p<m),0;
	for (int i=1;i*p<=m&&i<=m;i++){
		int ok=m-i*p;
		ans=(ans+1ll*C(ok-1,i-1)*(C(n-1,i)+C(n-1,i-2)+2ll*C(n-1,i-1)))%mo;
	}
	printf("%d\n",ans*1ll*power(tot,mo-2)%mo);
}