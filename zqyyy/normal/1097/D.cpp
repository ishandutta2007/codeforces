#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int mod=1e9+7;
ll n,p[57];
int m,K,f[57],inv[57],zs[57];
int main(){
	n=read(),K=read();
	for(ll i=2;i*i<=n;i++)
		if(n%i==0){
			p[++m]=i;
			while(n%i==0)n/=i,zs[m]++;
		}
	inv[1]=1;
	for(int i=2;i<=50;i++)inv[i]=mod-1ll*(mod/i)*inv[mod%i]%mod;
	if(n^1)p[++m]=n,zs[m]=1;
	int ans=1;
	for(int o=1;o<=m;o++){
		memset(f,0,sizeof(f)),f[zs[o]]=1;
		for(int i=1;i<=K;i++)
			for(int j=0;j<=zs[o];j++){
				f[j]=1ll*f[j]*inv[j+1]%mod;
				for(int k=j+1;k<=zs[o];k++)
					(f[j]+=1ll*f[k]*inv[k+1]%mod)%=mod;
			}
		int sum=0,res=1;
		for(int i=0;i<=zs[o];i++)(sum+=1ll*res*f[i]%mod)%=mod,res=1ll*res*p[o]%mod;
		ans=1ll*ans*sum%mod;
	}
	return cout<<ans,0;
}