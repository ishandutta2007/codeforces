#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int N = (1 << 20);
int c[N];
string T[N];
const int MOD = 998244353;

int n;
string s;

void build(int v) {
	T[v] = "";
	if (v * 2 > s.size()) {
		T[v] += s[v-1];
		c[v] = 1;
	} else {
		build(2 * v);
		build(2 * v + 1);
		if (T[2*v] == T[2*v+1]){
			c[v] = (c[2 * v] * 1ll * c[2 * v + 1]) % MOD;
		} else {
			c[v] = ((c[2 * v] * 1ll * c[2 * v + 1]) % MOD * 2ll) % MOD;
		}
		if (T[2 * v] <= T[2 * v + 1]) {
			T[v] += s[v-1];
			T[v] += T[2 * v];
			T[v] += T[2 * v + 1];
		} else {
			T[v] += s[v-1];
			T[v] += T[2 * v + 1];
			T[v] += T[2 * v];
		}
		// cout << v << " " << T[v] << endl;
	}
	// cout << v << " " << c[v] << endl;
}

void solve(int test_ind){
	cin >> n;
	cin >> s;
	build(1);
	cout << c[1] << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}