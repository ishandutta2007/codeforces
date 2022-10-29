#include<bits/stdc++.h>
#define mod 1000000007
#define maxn 100100
using namespace std;
typedef long double ldb;
ldb a[maxn],b[maxn],p;
int n,x;
bool check(ldb time){
	ldb used=0,x=time*p;
	for(int i=1;i<=n;++i)if(a[i]*time>b[i]){
		used+=(a[i]*time-b[i]);
		if(used>x)return false;
	}
	return true;
}
int main(){
	scanf("%d%d",&n,&x),p=x;
	for(int i=1;i<=n;++i)
		scanf("%d",&x),a[i]=x,
		scanf("%d",&x),b[i]=x;
	ldb l=0,r=1e15;
	for(int i=0;i<=200;++i){
		ldb mid=(l+r)/2;
		if(check(mid))l=mid;
		else r=mid;
	}
	if(l>1e14)printf("-1");
	else printf("%.9lf",(double)l);
}