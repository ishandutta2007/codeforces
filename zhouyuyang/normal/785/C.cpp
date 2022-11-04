#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
ll n,m;
ll cal(ll x){
	if (x<=m) return n;
	x-=m+1;
	if (x>2e9) return -1;
	return n-x*(x+1)/2ll;
}
int main(){
	scanf("%I64d%I64d",&n,&m);
	ll l=0,r=n+m;
	while (l<r){
		ll mid=(l+r)/2;
		if (cal(mid)-mid<=0) r=mid; else l=mid+1;
	}
	printf("%I64d",l);
}