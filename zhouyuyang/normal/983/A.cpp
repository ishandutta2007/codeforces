#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define mo 1000000007
#define fi first
#define se second
using namespace std;
ll gcd(ll x,ll y){
	return y?gcd(y,x%y):x;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--){
		ll v1,v2,v3;
		scanf("%lld%lld%lld",&v1,&v2,&v3);
		if (v1==0){
			puts("Finite");
			continue;
		}
		ll tmp=gcd(v1,v2); v2/=tmp;
		tmp=gcd(v3,v2);
		for (;tmp!=1;){
			for (;v2%tmp==0;v2/=tmp);
			tmp=gcd(v2,tmp);
		}
		puts(v2==1?"Finite":"Infinite");
	}
}