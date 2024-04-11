#include<bits/stdc++.h>
#define maxn 60100
using namespace std;
typedef long double ldb;
const ldb eps=1e-8;
int n,x[maxn],v[maxn];
bool check(ldb t){
	ldb l=-1e20,r=1e20;
	for(int i=1;i<=n;++i){
		l=max(l,x[i]-t*v[i]);
		r=min(r,x[i]+t*v[i]);
		if(fabs(r-l)>eps&&l>r)return false;
	}
	return true;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&x[i]);
	for(int i=1;i<=n;++i)
		scanf("%d",&v[i]);
	ldb l=0,r=1e10;
	while(r-l>eps){
		ldb mid=(l+r)/2;
		if(check(mid))r=mid;
		else l=mid;
	}
	printf("%.9lf",(double)l);
}