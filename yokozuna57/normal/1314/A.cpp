#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

#define fr first
#define sc second

int main(){
	static ll n;
	static ll a[200010],t[200010];
	scanf("%lld",&n);
	for(int i = 0 ; i < n ; i ++){
		scanf("%lld",&a[i]);
	}
	for(int i = 0 ; i < n ; i ++){
		scanf("%lld",&t[i]);
	}
	
	vector<P> vec;
	for(int i = 0 ; i < n ; i ++){
		vec.push_back(P(a[i],t[i]));
	}
	sort(vec.begin(),vec.end());
	
	multiset<ll> S;
	ll sum = 0;
	ll ret = 0;
	ll loc = 0;
	ll k = 0;
	while(1){
		if(k == vec.size() && S.size() == 0)break;
		if(S.size() > 0){
			loc ++;
			ret += sum;
		}
		else loc = vec[k].fr;
		while(k < vec.size() && vec[k].fr == loc){
			S.insert(vec[k].sc);
			sum += vec[k].sc;
			k ++;
		}
		sum -= *--S.end();
		S.erase(--S.end());
	}
	cout << ret << endl;
}