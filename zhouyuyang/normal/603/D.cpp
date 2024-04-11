#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pa pair<ll,ll>
map<pa,int> mp;
ll x[2005],y[2005],bot[2005];
int n;
ll gcd(ll x,ll y){
	return y?gcd(y,x%y):x;
}
pa work(ll a,ll b){
	if (a<0) a=-a,b=-b;
	ll tmp=gcd(a,b);
	return pa(a/tmp,b/tmp);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		x[i]=a*c; y[i]=b*c; bot[i]=a*a+b*b;
	}
	int ans=0;
	for (int i=1;i<=n;i++){
		map<pa,int> mp;
		mp.clear();
		for (int j=i+1;j<=n;j++){
			ll u=x[i]*bot[j]-x[j]*bot[i];
			ll v=y[i]*bot[j]-y[j]*bot[i];
			if (!u&&!v) ans+=n-1-i;
			else ans+=(mp[work(u,v)]++);
		}
	}
	printf("%d",ans);
}