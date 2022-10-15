#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll f=1,r=0;char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))r=(r<<1)+(r<<3)+(ch^48),ch=getchar();
	return f?r:-r;
}
const int N=2e5+7;
int n,m;
ll sum,a[N];
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),sum+=a[i];
	sort(a+1,a+n+1);m=read();
	while(m--){
		ll x=read(),y=read(),ans=4e18;
		ll pos=lower_bound(a+1,a+n+1,x)-a;
		if(pos<=n){
			ans=min(ans,max(y-(sum-a[pos]),0ll));
		}if(pos>1){
			pos--;
			ans=min(ans,max(y-(sum-a[pos]),0ll)+x-a[pos]);	
		}
		printf("%lld\n",ans);
	}
	return 0;	
}