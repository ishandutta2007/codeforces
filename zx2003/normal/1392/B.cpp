#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int T,n,i,a[N];long long k;
inline void doo(){
	int mx=-(1<<30);for(i=1;i<=n;++i)mx=max(mx,a[i]);for(i=1;i<=n;++i)a[i]=mx-a[i];
}
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d%lld",&n,&k);
		for(i=1;i<=n;++i)scanf("%d",a+i);
		doo();--k;
		if(k&1)doo();
		for(i=1;i<=n;++i)printf("%d%c",a[i],i==n?'\n':' ');
	}
}