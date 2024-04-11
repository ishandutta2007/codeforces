#include<bits/stdc++.h>
#define ll long long 
#define N 100005
using namespace std;
ll n,p,phi,l,r,ans;
ll g[N][10],f[N],F[N],pr[30],t[30];
ll power(ll a,ll b){
	ll s=1;
	for (;b;b/=2,a=a*a%p)
		if (b&1) s=s*a%p;
	return s;
}
ll C(ll a,ll b){
	if (a<b) return 0;
	ll s=f[a]*F[b]%p*F[a-b]%p;
	for (int i=1;i<=pr[0];i++)
		s=s*power(pr[i],g[a][i]-g[b][i]-g[a-b][i])%p;
	return s;
}
void init(){
	f[0]=F[0]=1;
	ll P=p,phi=p;
	for (ll i=2;i*i<=P;i++)
		if (P%i==0){
			pr[++pr[0]]=i;
			phi-=phi/i;
			for (;P%i==0;P/=i);
		}
	if (P>1){
		pr[++pr[0]]=P;
		phi-=phi/P;
	}
	for (ll i=1;i<=n;i++){
		ll num=i;
		for (int j=1;j<=pr[0];j++)
			for (;num%pr[j]==0;num/=pr[j],g[i][j]++);
		for (int j=1;j<=pr[0];j++) g[i][j]+=g[i-1][j];
		f[i]=f[i-1]*num%p;
		F[i]=power(f[i],phi-1);
	}
}
int main(){
	scanf("%d%d%d%d",&n,&p,&l,&r);
	init();
	for (ll i=l;i<=n;i++){
		ll L=(l+i+1)/2;
		ll R=min(i,(r+i)/2);
		if (L>R) continue;
		ans+=1ll*C(n,i)*(C(i,L)+p-C(i,R+1))%p;
	}
	printf("%I64d",(ans%p+p)%p);
}