#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, a, b;
	cin >> n >> a >> b;
	vector<int> x(n);
	for (int i=0;i<n;++i) scanf("%d", &x[i]);
	vector<long long> suf(n+1);
	for (int i=n-1;i>=0;--i){
		suf[i] = suf[i+1] + x[i];
	}
	long long cur = 0, prev=0;
	long long ans;
	for (int i=0;i<n;++i) {
		long long curans = b * (suf[i] - cur * (n - i)) + prev;
		// cout << i << ": "  << curans << endl;
		if (i) ans = min(ans, curans);
		else ans = curans;
		prev += (x[i] - cur) * (a + b);
		cur = x[i];
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