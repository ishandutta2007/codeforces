#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ldb;
ll k,d,t;
int main(){
	scanf("%lld%lld%lld",&k,&d,&t);
	ll D=(k+d-1)/d*d;
	ll cir=k*2+D-k;
	ll T=2*t;
	ldb use=T/cir*D;
	ll rest=T%cir;
//	printf("[%lld]",cir);
	if(rest<=k*2)use+=rest/2.0;
	else use+=k+rest-k*2;
	printf("%.10lf",(double)use);
}