#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
ll m, C[62][62];
int K;
inline ll calc(ll mid) {
	ll res=0;
	for (int i=59, j=K; ~i && ~j; i--)
		if (mid>>i&1) res+=C[i][j], j--;
	return res;
}
int main(){
	m=read(), K=read(), C[0][0]=1, K--;
	for (int i=1; i<=59; i++) {
		C[i][0]=1;
		for (int j=1; j<=min(i, K); j++)
			C[i][j]=C[i-1][j]+C[i-1][j-1];
	}
	ll l=1, r=1e18;
	while (l<r) {
		ll mid=(l+r)>>1;
		if (calc(mid)>=m) r=mid;
		else l=mid+1;
	}
	printf("%lld\n", l);
	return 0;
}