#include <cstdio>
int n,k,p,m,now,prd[200010],inv[200010],prdinv[200010];
long long stl;
const int harry=998244353;
int qpow(int base,int power){
	int pow=1,remain=power;
	long long res=1,now=base;
	while(remain){
		if(remain&pow)remain^=pow,res*=now,res%=harry;
		pow<<=1,now*=now,now%=harry;
	}
	return res;
}
int main(){
	scanf("%d %d",&n,&k);
	if(k>=n){printf("0");return 0;}
	m=n-k;
	prd[0]=1;
	for(register int i=1;i<=n;++i)prd[i]=(long long)prd[i-1]*i%harry;
	prdinv[n]=qpow(prd[n],harry-2);
	for(register int i=n-1;~i;--i)prdinv[i]=(long long)prdinv[i+1]*(i+1)%harry;
	for(register int i=1;i<=n;++i)inv[i]=(long long)prd[i]*prdinv[i-1]%harry;
	now=1;
	for(register int i=m;~i;--i,now=-now){
		if(now==1)stl+=(long long)qpow(i,n)*prdinv[i]%harry*prdinv[m-i]%harry;
		else stl+=harry-(long long)qpow(i,n)*prdinv[i]%harry*prdinv[m-i]%harry;
	}
	stl%=harry;
	if(k)printf("%d",stl*prd[m]%harry*prd[n]%harry*prdinv[m]%harry*prdinv[n-m]%harry*2%harry);
	else printf("%d",stl*prd[m]%harry*prd[n]%harry*prdinv[m]%harry*prdinv[n-m]%harry);
	return 0;
}