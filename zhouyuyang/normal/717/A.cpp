#include<bits/stdc++.h>
#define pii pair<int,int>
#define ll long long
using namespace std;
const int mo=1000000007;
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
#define fi first
#define se second
pii operator +(const pii &a,const pii &b){
	return pii((a.fi+b.fi)%mo,(a.se+b.se)%mo);
}
pii operator -(const pii &a,const pii &b){
	return pii((a.fi+mo-b.fi)%mo,(a.se+mo-b.se)%mo);
}
pii operator *(const pii &a,const pii &b){
	return pii((1ll*a.fi*b.fi+5ll*a.se*b.se)%mo,(1ll*a.fi*b.se+1ll*a.se*b.fi)%mo);
}
pii operator *(const pii &a,int b){
	return pii(1ll*a.fi*b%mo,1ll*a.se*b%mo);
}
bool operator !=(const pii &a,const pii &b){
	return a.fi!=b.fi||a.se!=b.se;
}
pii Inv(pii a){
	int t=(1ll*a.fi*a.fi+mo-5ll*a.se*a.se%mo)%mo;
	t=power(t,mo-2);
	return pii(1ll*a.fi*t%mo,mo-1ll*a.se*t%mo);
}
pii operator ^(pii a,ll b){
	pii ans(1,0);
	for (;b;b/=2,a=a*a)
		if (b&1) ans=ans*a;
	return ans;
}
pii sigma(pii x,ll l,ll r){
	if (x.fi==1&&x.se==0) return pii((r-l+1)%mo,0);
	return ((x^l)-(x^(r+1)))*Inv(pii(1,0)-x);
}
const int N=205;
ll k,l,r;
ll f[N],fac[N],inv[N];
ll C(ll x,ll y){
	return x<y?0:1ll*fac[x]*inv[y]%mo*inv[x-y]%mo;
}
pii A,B,pa[N],pb[N];
int sgn(int n){
	return n&1?mo-1:1;
}
int solve(ll l,ll r){
	pii c(1,0),bs=pii(0,power(5,mo-2)),sum;
	for (int i=1;i<=k;i++){
		c=c*bs; pii ts;
		for (int j=0;j<=i;j++)
			ts=ts+sigma(pa[j]*pb[i-j],l,r)*C(i,j)*sgn(i-j);
		sum=sum+(ts*c)*f[i];
	}	
	return sum.fi;
}
int main(){
	fac[0]=1;
	for (int i=1;i<N;i++)
		fac[i]=1ll*fac[i-1]*i%mo;
	inv[N-1]=power(fac[N-1],mo-2);
	for (int i=N-2;i>=0;i--)
		inv[i]=1ll*inv[i+1]*(i+1)%mo;
	pii A=(pii){1,1}*power(2,mo-2);
	pii B=(pii){1,0}-A;
	pa[0]=pb[0]=pii(1,0);
	for (int i=1;i<N;i++) pa[i]=pa[i-1]*A;
	for (int i=1;i<N;i++) pb[i]=pb[i-1]*B;
	scanf("%d%lld%lld",&k,&l,&r);
	l+=2; r+=2; f[1]=1; ll fa=1;
	for (int i=1;i<k;i++){
		fa=1ll*fa*(i+1)%mo;
		for (int j=i;j>=0;j--){
			f[j+1]=(f[j+1]+f[j])%mo;
			f[j]=1ll*f[j]*(mo-i)%mo;
		}
	}
	printf("%d\n",1ll*solve(l,r)*power(fa,mo-2)%mo);
}