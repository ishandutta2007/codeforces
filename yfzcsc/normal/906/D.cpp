#include<bits/stdc++.h>
#define maxn 100100
using namespace std;
typedef long long ll;
int n,mod,a[maxn],m,f[100];
int phi(int x){
	int ans=1;
	for(int i=2;i*i<=x;i++)if(x%i==0){
		ans*=i-1,x/=i; 
		while(x%i==0)x/=i,ans*=i;
	}
	if(x>1)ans*=x-1;
	return ans;
} 
int gmod(ll x,int y){
	if(x<y)return x;
	return x%y+y;
}
int qpow(int a,int b,int mod){
	int ans=1,tmp=a;
	for(;b;b>>=1,tmp=gmod(1ll*tmp*tmp,mod))
		if(b&1)ans=gmod(1ll*ans*tmp,mod);
	return ans;
}
int cal(int l,int r,int y){
	if(l==r)return gmod(a[l],f[y]);
	if(f[y]==1)return 1; 
	int z=cal(l+1,r,y+1);
	return qpow(a[l],z,f[y]);
}
int main(){
	scanf("%d%d",&n,&mod);
	f[1]=mod;
	for(int i=2;i<=50;++i)f[i]=phi(f[i-1]);
//	for(int i=1;i<=10;++i)printf("[%d]",f[i]);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1,l,r;i<=m;++i){
		scanf("%d%d",&l,&r);
		printf("%d\n",cal(l,r,1)%mod);
	}
}