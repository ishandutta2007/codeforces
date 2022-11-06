#include "bits/stdc++.h"
using namespace std;


int main() {
	long long int s, f, t; cin >> s >> f >> t;
	int N; cin >> N;
	vector<long long int>v(N);
	for (int i = 0; i < N; ++i) {
		cin >> v[i];
	}
	v.emplace_back(f-t+1);
	sort(v.begin(), v.end());
	pair<long long int, long long int>ans(1e18, 1e18);
	long long int len = 0;
	for (int i = 0; i <= N; ++i) {
		if (i == 0)len = 0;
		else {
			if (v[i] > s) {
				len = max(0ll, len - (v[i] - 1 - max(v[i - 1], s)));
			}
			else {
				
			}
		}
		long long int wait = len+max(s-(v[i]-1), 0ll);
		if (v[i] - 1 + wait+t <= f)ans = min(ans, make_pair(wait, v[i] - 1));

		if(v[i]-1>=s)len = max(0ll, len - 1);
		len += t;
	}
	cout << ans.second << endl;
	return 0;
}