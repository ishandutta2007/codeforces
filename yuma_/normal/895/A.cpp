#include "bits/stdc++.h"
using namespace std;
using ld= long double;

int main() {  
	

	int N; cin >> N;
	vector<int>as(N);
	for (int i = 0; i < N; ++i) {
		cin >> as[i];
	}
	int ans=360;
	for (int l = 0; l <= N; ++l) {
		for (int r = 0; r <= N; ++r) {
			if (l <= r) {
				int t=accumulate(as.begin()+l,as.begin()+r,0);
				ans=min(ans,2*(180-min(t,360-t)));
			}
			else {
				int t=accumulate(as.begin(),as.begin()+l,0);
				t+=accumulate(as.begin()+r,as.end(),0);
				ans = min(ans, 2 * (180 - min(t, 360 - t)));
			}
		}
	}

	cout << ans << endl;

	return 0;
}