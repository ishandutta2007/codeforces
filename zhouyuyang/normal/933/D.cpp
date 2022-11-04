#include<bits/stdc++.h>
#define mo 1000000007
#define Inv6 166666668
#define ll long long
#define int ll
#define N 1000005
using namespace std;
int n,m;
ll ans;
ll sum2[N],sum4[N],sum6[N];
ll calc(int t3,int t2,int t1,int t0,int l,int r){
	ll ans=1ll*t0*r%mo;
	ans+=1ll*t1*l%mo*r%mo+1ll*t1*sum2[r]%mo;
	ans+=1ll*t2*l%mo*l%mo*r%mo+2ll*t2*l%mo*sum2[r]%mo+1ll*t2*sum4[r]%mo;
	ans+=1ll*t3*l%mo*l%mo*l%mo*r%mo+3ll*t3*l%mo*l%mo*sum2[r]%mo+3ll*t3*l%mo*sum4[r]%mo+1ll*t3*sum6[r]%mo;
	return ans%mo;
} 
signed main(){
	scanf("%lld",&m);
	/*Sum(l){
		return (m-l+1)*(m-l+2)*(m+2*l)/6;
		(m-l+1)*(m-l+2)=m^2+l^2-2ml+3m-3l+2
		=m^3+ml^2-2m^2l+3m^2-3ml+2m
		 2m^2l+2l^3-4ml^2+6ml-6l^2+4l
		=m^3+3m^2-3ml^2+3ml+2m+2l^3-6l^2+4l
	  }
	  Sum(a,b,c,d
	Rep(j,l,r) Sum(i*i+j*j,m)*/
	int tmp=1;
	for (;1ll*tmp*tmp<=m;tmp++);
	for (int i=1;i<tmp;i++){
		sum2[i]=1ll*i*i%mo;
		sum4[i]=1ll*sum2[i]*i%mo*i%mo;
		sum6[i]=1ll*sum4[i]*i%mo*i%mo;
	}
	for (int i=1;i<tmp;i++){
		sum2[i]=(sum2[i]+sum2[i-1])%mo;
		sum4[i]=(sum4[i]+sum4[i-1])%mo;
		sum6[i]=(sum6[i]+sum6[i-1])%mo;
	}
	int r=tmp,M=m%mo;
	int cs=(1ll*M*M%mo*M%mo+3ll*M*M%mo+2ll*M)%mo;
	for (int i=1;1ll*i*i<=m;i++){
		for (;1ll*r*r+1ll*i*i>m;r--);
		ans+=calc(2,((-3*m-6)%mo+mo)%mo,(3*m+4)%mo,cs,1ll*i*i%mo,r);
	} 
	for (int i=1;i<tmp;i++){
		int p=(m-1ll*i*i+1)%mo;
		ans+=1ll*p*(p+1)%mo*(m%mo+2ll*i*i%mo)%mo;
	}
	ans=ans%mo*4%mo*Inv6%mo;
	m%=mo;
	ans+=1ll*m*(m+1)/2%mo*(m+1)%mo-1ll*m*(m+1)%mo*(2*m+1)%mo*Inv6%mo; 
	printf("%lld\n",(ans+233ll*mo)%mo);
}