#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> P1;

#define rep1(i,x) for(int i = 1 ; i <= x ; i ++)
#define mp1(a,b,c) P1(a,P(b,c))

int main(){
	static ll n;
	static ll val[300010],mask[300010];
	scanf("%lld",&n);
	rep1(i,n){
		scanf("%lld%lld",&val[i],&mask[i]);
	}
	
	static ll ret = 0;
	static ll sum = 0;
	rep1(i,n)sum += val[i];
	if(sum < 0){
		ll m = 0;
		while(m < (1LL << 61)){
			ll pm = m;
			m = 2*m+1;
			ll sum_ = 0;
			rep1(i,n){
				if(pm < mask[i] && mask[i] <= m){
					sum_ += val[i];
				}
			}
			if(sum_ < 0){
				ll x = pm+1;
				ret += x;
				rep1(i,n){
					if(x&mask[i])val[i] = -val[i];
				}
			}
		}
	}
	else {
		ll m = 0;
		while(m < (1LL << 61)){
			ll pm = m;
			m = 2*m+1;
			ll sum_ = 0;
			rep1(i,n){
				if(pm < mask[i] && mask[i] <= m){
					sum_ += val[i];
				}
			}
			if(sum_ > 0){
				ll x = pm+1;
				ret += x;
				rep1(i,n){
					if(x&mask[i])val[i] = -val[i];
				}
			}
		}
	}
	cout << ret << endl;
}