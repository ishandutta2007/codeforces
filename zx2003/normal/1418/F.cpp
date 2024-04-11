#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
const int N=2e5+5;
int n,m,M,T[N*3],g,b,a,t,x,i,ans[N];
ll L,R;
inline void mdy(int x,int v){
	for(x+=M;x;T[x]=v,x>>=1);
}
inline int ask(int l,int r){
	int ret=0;
	for(l+=M-1,r+=M+1;l^r^1;l>>=1,r>>=1){
		if(!(l&1))ret=max(ret,T[l^1]);
		if(r&1)ret=max(ret,T[r^1]);
	}
	return ret;
}
int main(){
	scanf("%d%d%lld%lld",&n,&m,&L,&R);
	for(M=1;M<m+2;M<<=1);memset(ans+1,-1,n<<2);
	for(g=n,b=1;g;--g){
		for(;b*g<=n;++b)for(t=1;t*b<=m;++t)mdy(t*b,b);
		for(a=1;a*g<=n;++a){
			ll l=(L+a*g-1)/(a*g),r=min(R/(a*g),ll(m));
			if(l<=r)x=ask(l,r),a<x?ans[a*g]=x*g:0;
			if(ans[1]!=-1){
				++i,--i;
			}
		}
	}
	for(i=1;i<=n;++i)if(ans[i]==-1)puts("-1");else{
		x=ans[i];
		ll z=1ll*i*x/__gcd(i,x),y=(L+z-1)/z*z;
		printf("%d %lld %d %lld\n",i,y/i,x,y/x);
	}
}