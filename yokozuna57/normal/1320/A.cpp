#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

#define fr first
#define sc second

int main(){
	static ll n;
	static ll b[200010];
	static ll cnt[600010] = {};
	scanf("%lld",&n);
	for(int i = 0 ; i < n ; i ++){
		scanf("%lld",&b[i]);
		cnt[b[i]-i+n] += b[i];
	}
	
	ll ret = 0;
	for(int i = 0 ; i < 600010 ; i ++){
		ret = max( ret , cnt[i] );
	}
	cout << ret << endl;
}