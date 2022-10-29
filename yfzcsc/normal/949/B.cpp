#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll solve(ll n,ll p){
//	printf("[%lld,%lld]",n,p);
	if(n==1)return 1;
	if(n==2)return p==1?1:2;
	if(p&1)return p+1>>1;
	if(n%2==0)return solve(n/2,p/2)+(n>>1);
	else return solve(n/2,p==2?n/2:p/2-1)+(n+1>>1);
}
int Q;
ll n,x;
int main(){
	scanf("%lld%d",&n,&Q);
	while(Q--){
		scanf("%lld",&x);
		printf("%lld\n",solve(n,x));
	}
}