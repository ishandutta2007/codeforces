#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
map<int,int> st;
int n,h,mod,inv[maxn];
int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)ans=1ll*ans*a%mod;
	return ans;
}
void sol(int l,int r,int h){
	if(r-l+1<=1||h<=1){
		st[r-l+1]++;
	} else {
		int mid=l+r>>1;
		sol(l,mid,h-1);
		sol(mid+1,r,h-1);
	}
}
int cal(int x,int y){
	int ret=1ll*x*y%mod*(mod+1)/2%mod;
	for(int i=1;i<=x;++i)
		ret-=inv[i+y]-inv[i],ret%=mod;
	return (ret%mod+mod)%mod;
}
int main(){
	scanf("%d%d%d",&n,&h,&mod);
	sol(1,n,h);
	inv[0]=inv[1]=1;
	for(int i=2;i<=n;++i)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	for(int i=1;i<=n;++i)inv[i]=(inv[i-1]+inv[i])%mod;
	int ans=0;
	for(auto c:st)
		ans=(ans+1ll*(c.first)*(c.first-1)%mod*qpow(4,mod-2)%mod*c.second
				+1ll*(c.second)*(c.second-1)/2%mod*cal(c.first,c.first))%mod;
	for(auto c:st)for(auto d:st)if(c.first<d.first)
		ans=(ans+1ll*(c.second)*d.second%mod*cal(c.first,d.first))%mod;
	printf("%d",ans);
}