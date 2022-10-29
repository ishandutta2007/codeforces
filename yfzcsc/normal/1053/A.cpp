#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,g;
void tp(ll x,ll y){
	if(x<=n&&y<=m)printf("YES\n0 0\n%lld 0\n%lld %lld\n",x,x,y),exit(0);
}
int main(){
	cin>>n>>m>>k;
	if(2*n*m%k||k==1){
		puts("NO");
		return 0;
	}
	g=__gcd(2*n,k);
	tp(2*n/g,m/(k/g));
	g=__gcd(2*m,k);
	tp(n/(k/g),(2*m)/(k));
}