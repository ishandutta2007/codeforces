#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i=0;i<n;++i) {
		scanf("%d", &a[i]);
	}
	if (k <= n) {
		vector<long long> p(n + 1);
		for (int i=0;i<n;++i) {
			p[i + 1] = p[i] + a[i];
		}
		long long m = 0;
		for (int i=k;i<=n;++i){
			m = max(m, p[i] - p[i - k]);
		}
		cout << k * 1ll * (k - 1) / 2 + m << endl;
		return;
	}
	long long s = 0;
	for (int i: a) s += i + k;
	s -= n * 1ll * (n + 1) / 2;
	cout << s << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}