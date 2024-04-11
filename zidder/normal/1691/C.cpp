#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	// 11 * mid + 1 * right + 10 * left
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;

	int one = 0, zero = 0;
	for (char c: s){
		if (c == '0') zero++;
		else one++;
	}
	int ans = 11 * n;
	auto f = [&](int l, int r) -> int {
		int remone = one, remzero = zero;
		if (l == 0) remzero--;
		else remone--;
		if (r == 0) remzero--;
		else remone--;
		int ans2 = remone * 11 + r + 10 * l;
		int li = -1;
		for (int i=0;i<n;++i) {
			if (s[i] - '0' == l) {li = i; break;}
		}
		if (li == -1) return ans;
		int ri = -1;
		for (int i=0;i<n;++i) {
			if (s[i] - '0' == r) {ri = i;}
		}
		if (ri == -1) return ans;
		if (ri == li) return ans;
		if (li + (n - 1 - ri - (li > ri)) <= k) return ans2;
		return ans;
	};

	for (int i=0;i<=1;++i){
		for (int j=0;j<=1;++j) {
			ans = min(ans, f(i, j));
		}
	}
	cout << ans << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}