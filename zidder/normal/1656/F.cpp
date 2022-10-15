#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n;
	cin >> n;
	vector<int> a(n);
	long long sm = 0;
	for (int i=0;i<n;++i){
		scanf("%d", &a[i]);
		sm += a[i];
	}
	sort(a.begin(), a.end());

	long long m=a[0], M=a.back();
	// t = inf
	if (sm + m * (n - 2) > 0) {
		cout << "INF" << endl;
		return;
	}
	if (sm + M * (n - 2) < 0) {
		cout << "INF" << endl;
		return;
	}
	if (n == 2) {
		cout << m * M << endl;
		return;
	}

	bool first = true;
	long long ans;
	long long lsm = 0;
	int lcnt = 0;

	for (int i: a){
		lsm += i;
		lcnt++;
		if (lcnt == n) break;
		int t = -i;
		long long tmp = m * M + t * (m + M);
		tmp *= -1;
		tmp += lsm * M + t * M * lcnt + lsm * t;
		tmp += (sm - lsm) * m + t * m * (n - lcnt) + (sm - lsm) * t;
		if (lcnt == 1) ans = tmp;
		else ans = max(ans, tmp);
		// i+
	}
	cout << ans << endl;
	// (a+t)x + at
	// am + tm + at
	// aM + tM + at
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}