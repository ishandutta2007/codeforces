#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=2e5+7;
int n,a[N];
inline void work(){
	n=read();
	ll sum=0;
	for(int i=1;i<=n;i++)sum+=a[i]=read();
	sort(a+1,a+n+1);
	if(1ll*a[1]*(n-2)+sum>0 || 1ll*a[n]*(n-2)+sum<0)
		return puts("INF"),void();
	ll res=-1ll*(n-1)*a[n]*a[n],k=1ll*a[n]*(n-2)+sum,ans=res;
	for(int i=n;i>1;i--){
		res+=k*(a[i]-a[i-1]);
		ans=max(ans,res),k+=a[1]-a[n];
	}
	printf("%lld\n",ans);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	int test=read();
	while(test--)work();
	return 0;
}