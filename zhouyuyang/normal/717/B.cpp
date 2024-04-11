#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ans;
int n,a,b,s;
int c[20005];
bool check(ll m){
	int sum=m/a;
	for (int i=0;i<=s;i++) c[i]=i+1;
	for (int i=1;1ll*i*b<=m&&sum<n;i++)
		for (int j=0;1ll*i*b+1ll*j*a<=m&&sum<n;j++)
			sum+=c[j],c[j]+=(j?c[j-1]:0);
	return sum>=n; 
}
void calc(ll m){
	int sum=m/a;
	ans+=1ll*sum*(sum+1)/2*a;
	for (int i=0;i<=s;i++) c[i]=i+1;
	for (int i=1;1ll*i*b<=m;i++)
		for (int j=0;1ll*i*b+1ll*j*a<=m;j++){
			ans+=1ll*c[j]*(1ll*i*b+1ll*j*a);
			sum+=c[j],c[j]+=(j?c[j-1]:0);
		}
	ans-=m*(sum-n);
}
int main(){
	scanf("%d%d%d",&n,&a,&b);
	if (a>b) swap(a,b);
	n--; ans=1ll*n*(a+b);
	n--; s=sqrt(n*2)+1;
	if (!a){
		printf("%lld\n",ans);
		return 0;
	}
	ll l=0,r=1ll*n*a;
	while (l<r){
		ll mid=(l+r)/2;
		if (check(mid)) r=mid;
		else l=mid+1;
	}
	calc(l);
	printf("%lld\n",ans);
}