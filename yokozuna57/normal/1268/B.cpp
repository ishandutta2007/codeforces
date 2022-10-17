#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define fr first
#define sc second

int main(){
	static ll n;
	static ll a[300010];
	scanf("%lld",&n);
	for(int i = 0 ; i < n ; i ++){
		scanf("%lld",&a[i]);
	}
	
	ll cnt[2] = {};
	for(int i = 0 ; i < n ; i ++){
		if(i&1){
			cnt[0] += a[i]/2;
			cnt[1] += a[i]-(a[i]/2);
		}
		else {
			cnt[0] += a[i]-(a[i]/2);
			cnt[1] += a[i]/2;
		}
	}
	cout << min( cnt[0] , cnt[1] ) << endl;
}