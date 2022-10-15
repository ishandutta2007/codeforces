#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

long long best_match(int x, set<int> X){
	int ans = abs(x - *X.begin());
	auto it = X.lower_bound(x);
	if (it != X.end()){
		ans = min(ans, abs(x - *it));
	}
	if (it != X.begin()){
		it--;
		ans = min(ans, abs(x - *it));
	}
	return ans;
}

void solve(int test_ind){
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	set<int> A, B;
	for (int i=0;i<n;++i){
		scanf("%d", &a[i]);
		A.insert(a[i]);
	}

	for (int i=0;i<n;++i){
		scanf("%d", &b[i]);
		B.insert(b[i]);
	}

	// connect a[0], b[0], a[-1], b[-1]
	long long ans = min(abs(a[0] - b[0]) + 0ll + abs(a.back() - b.back()), abs(a[0] - b.back()) + 0ll + abs(a.back() - b[0]));
	ans = min(ans, abs(a[0] - b[0]) + best_match(a.back(), B) + best_match(b.back(), A));
	ans = min(ans, abs(a[0] - b.back()) + best_match(a.back(), B) + best_match(b[0], A));
	ans = min(ans, abs(a.back() - b[0]) + best_match(a[0], B) + best_match(b.back(), A));
	ans = min(ans, abs(a.back() - b.back()) + best_match(a[0], B) + best_match(b[0], A));
	ans = min(ans, best_match(a[0], B) + best_match(b[0], A) + best_match(a.back(), B) + best_match(b.back(), A));
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