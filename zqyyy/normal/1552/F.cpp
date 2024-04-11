#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=2e5+7,mod=998244353;
int n,ans,s[N],a[N],f[N];
int main(){
	n=read();
	for(int i=1,y,fl;i<=n;i++){
		a[i]=read(),y=read(),fl=read();
		f[i]=(0ll+a[i]+s[i-1]-y-s[lower_bound(a+1,a+i+1,y)-a-1]+mod)%mod;
		s[i]=(s[i-1]+f[i])%mod;
		if(fl)ans=(ans+f[i])%mod;
	}
	return cout<<(ans+a[n]+1)%mod,0;
}