#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=2e5+7,mod=998244353;
inline void inc(int &x,int y){x+=y-mod,x+=x>>31&mod;}
inline void dec(int &x,int y){x-=y,x+=x>>31&mod;}
inline int qpow(int a,int b){
	int res=1;
	for(;b;b>>=1,a=(ll)a*a%mod)
		if(b&1)res=1ll*res*a%mod;
	return res;
}
int n,m,c,a[N];
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	n=read(),m=read(),c=read();
	for(int i=1;i<=m;i++)a[i]=read();
	int ans=qpow(c,n-2*a[m]);
	for(int i=1;i<=m;i++){
		int x=qpow(c,a[i]-a[i-1]);
		ans=(ll)x*(x+1)/2%mod*ans%mod;
	}
	printf("%d\n",ans);
	return 0;
}