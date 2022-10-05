#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll x1,x2,a,b,ans;

ll doit(ll d,ll l,ll r){
	if (l>r) swap(l,r);
	if (d>=l&&d<=r) return d;
	if (l<=0) exit(0*puts("DRAW"));
	ll aim=d%(l+r);
	if (!aim) exit(0*puts("SECOND"));
	if (aim>=l&&aim<=r) return aim;
	exit(0*puts("DRAW"));
}

int main(){
	cin>>x1>>x2>>a>>b;
	ans= x1<x2? doit(x2-x1,a,b): doit(x1-x2,-a,-b);
	printf("FIRST\n%I64d",x1<x2? x1+ans: x1-ans);
}