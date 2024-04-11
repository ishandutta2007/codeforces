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
	long long k;
	cin >> k;
	vector<long long> a(n);
	for (int i=0;i<n;++i) scanf("%lld", &a[i]);

	long long sm = 0;
	for (long long i: a) sm+=i;
	if(sm <= k) {
		printf("0\n");
		return;
	}
	sort(a.begin(), a.end());
	long long ans = sm - k;
	sm -= a[0];
	for (int i=n-1;i>0;--i){
		sm -= a[i];
		long long m = (k - sm) / (n - i + 1);
		if (m * (n - i + 1) > k - sm) m--;
		m = min(m, a[0]);
		ans = min(ans, n - i + a[0] - m);
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