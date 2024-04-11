#include<bits/stdc++.h>
const int N=500005;int a[N],b[N],c[N];
void add(int x){for(;x;x-=x&-x)++c[x];}
int ask(int x){int ans=0;for(;x<N;x+=x&-x)ans+=c[x];return ans;}
int main(){
	int _;scanf("%d",&_);
	while(_--){
		int n;scanf("%d",&n);memset(c,0,(n+3)<<2);long long ans=0;
		for(int i=1;i<=n;++i)scanf("%d",&a[i]),b[i]=2*a[i]-i-1,ans+=ask(a[i]),add(a[i]);
		std::sort(b+1,b+n+1);for(int i=0;i<=n;++i)ans+=b[i],printf("%lld%c",ans-1LL*i*(i-1)/2," \n"[i==n]);
	}
	return 0;
}