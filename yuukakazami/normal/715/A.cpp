#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define per(i,a,n) for(int i=(n)-1;i>=(a);i--)

typedef long long ll;

int main(){
	int n;cin>>n;
	ll cur=2;
	rep(i,1,n+1){
		ll a = cur/i;
		ll out = 1LL *(i+1)*(i+1)*i - a;
		cout<<out<<endl;
		cur = 1LL*(i+1)*i;
	}
	return 0;
}