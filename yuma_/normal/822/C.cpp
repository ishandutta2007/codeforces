

#include "bits/stdc++.h"
using namespace std;
struct aa {
	int l;
	int r;
	long long int cost;
};
int main() {
	int N, M; cin >> N >> M;
	vector<aa>vouas, voubs;
	for (int i = 0; i < N; ++i) {
		int a, b; long long int c; cin >> a >> b >> c;
		vouas.push_back(aa{ a,b,c });
	}
	voubs = vouas;
	sort(vouas.begin(), vouas.end(),
		[](const aa&l, const aa&r) {
		return l.r > r.r;
	});
	sort(voubs.begin(), voubs.end(),
		[](const aa&l, const aa&r) {
		return l.l < r.l;
	});
	long long int ans = 1e13;
	map<int, long long int>mp;
	for (auto voua : vouas) {
		int r = voua.r;
		while (!voubs.empty() && voubs.back().l > r) {
			auto vou(voubs.back());
			int len = vou.r - vou.l + 1;
			if (mp.find(len) == mp.end()) {
				mp[len] = 1e10;
			}
			mp[len] = min(mp[len], vou.cost);
			voubs.pop_back();
		}
		int alen(voua.r - voua.l + 1);
		if (mp.find(M - alen) != mp.end()) {
			ans = min(ans, voua.cost + mp[M - alen]);
		}
	}
	if (ans > 1e10)ans = -1;
	cout << ans << endl;
	return 0;
}