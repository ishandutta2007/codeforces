#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int MOD = 998244353;

void solve(int test_ind){
	int n;
	cin >> n;
	if (n%2) {
		cout << 0 << endl;
	} else {
		int p = 1;
		for (int i=1;i<=n/2;++i){
			p = p * 1ll * i % MOD;
		}
		p = p * 1ll * p % MOD;
		cout << p << endl;
	}
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}