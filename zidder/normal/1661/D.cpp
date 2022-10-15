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
	int k;
	cin >> k;
	vector<long long> b(n);
	for (int i=0;i<n;++i) scanf("%lld", &b[i]);
	vector<long long> c(n);
	long long d = 0, sm = 0;
	long long ans = 0;
	for (int i=n-1;i>=0;--i){
		d -= c[i];
		if (i >= k) {
			if (b[i] > sm) {
				long long cnt = (b[i] - sm + k - 1) / k;
				ans += cnt;
				c[i-k] += cnt;
				d += cnt;
				sm += cnt * k;
			}
		} else {
			if (b[i] > sm) {
				b[i] -= sm;
			} else {
				b[i] = 0;
			}
		}
		sm -= d;
	}
	long long m = 0;
	for (int i=0;i<k;++i){
		m = max(m, (b[i] + i) / (i + 1));
	}
	cout << m + ans << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}