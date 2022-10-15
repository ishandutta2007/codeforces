#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=2e5+7,M=3e5+7;
int n,m,a[N];
struct b1t{
	ll c[M];
#define lbt(x) ((x)&-(x))
	inline void add(int p,int x){
		for(;p<=m;p+=lbt(p))c[p]+=x;
	}
	inline ll ask(int p){
		ll res=0;
		for(;p;p-=lbt(p))res+=c[p];
		return res;
	}
}T1,T2;
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),m=max(m,a[i]);
	ll ans=0,sum=0;
	for(int j=1;j<=n;j++){
		int x=a[j];ans+=sum+1ll*(j-1)*x-T2.ask(x),sum+=x;
		for(int i=x;i<=m;i+=x)ans-=x*(j-1-T1.ask(i-1));
		T1.add(x,1);
		for(int i=x;i<=m;i+=x)T2.add(i,x);
		printf("%lld ",ans);
	}
	return 0;
}