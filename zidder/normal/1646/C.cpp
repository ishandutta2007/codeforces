#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	long long mx = 1000000000000ll;
	vector<long long> fct;
	fct.push_back(1);
	for (int i=2;fct.back() < mx;++i){
		fct.push_back(i * fct.back());
	}
	int k = 60;
	auto f = [&](long long x){
		int r = 0;
		for (int i=0;i<60;++i){
			if (x & (1ll<<i)){
				r++;
			}
		}
		return r;
	};
	auto upd = [&](int x){
		k = min(k, x);
	};
	long long n;
	cin >> n;
	for (int msk=0;msk<(1<<fct.size());++msk){
		long long s = 0, c = 0;
		for (int j=0;j<fct.size();++j){
			if (msk & (1<<j)){
				s += fct[j];
				c++;
			}
		}
		if (s > n) continue;
		upd(f(n - s) + c);
	}
	cout << k << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}