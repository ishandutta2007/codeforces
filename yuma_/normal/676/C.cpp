#include "bits/stdc++.h"
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps=1e-9;

int main() {
	int N, K; cin >> N >> K;
	string st; cin >> st;
	vector<int>oks(N);
	for (int i = 0; i < N; ++i) {
		oks[i] = st[i] == 'a';

	}
	int ans = 0;
	{
		int l = 0, r = 0, no = 0;
		while (r<N) {
			if (oks[r]) {
				r++;
				
				if (no <= K)ans = max(ans, r - l);
			}
			else if (no < K) {
				r++;
				no++;
				ans = max(ans, r - l);
			}
			else if (r == l) {
				r++;
				l++;
			}
			else if (no >= K) {
				if (!oks[l])no--;
				l++;

			}
			else {
				r++;
				no++;
				ans = max(ans, r - l);
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		oks[i] = st[i] == 'b';
	}
	{
		int l = 0, r = 0, no = 0;
		while (r<N) {
			if (oks[r]) {
				r++;

				if (no <= K)ans = max(ans, r - l);
			}
			else if (no < K) {
				r++;
				no++;
				ans = max(ans, r - l);
			}
			else if (r == l) {
				r++;
				l++;
			}
			else if (no >= K) {
				if (!oks[l])no--;
				l++;

			}
			else {
				r++;
				no++;
				ans = max(ans, r - l);
			}
		}
	}
	cout << ans << endl;
	return 0;
}