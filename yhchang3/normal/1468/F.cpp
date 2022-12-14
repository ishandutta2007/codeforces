#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		int x, y, u, v;
		map<pair<int,int>,int> st;
		auto norm = [&](int dx,int dy) {
			int g = abs(gcd(dx, dy));
			dx /= g, dy /= g;
			return make_pair(dx, dy);
		};
		for(int i=0;i<n;i++) {
			cin >> x >> y >> u >> v;
			st[norm(u - x, v - y)]++;
		}
		long long res = 0;
		for(auto it:st) {
			auto opp = norm(-it.first.first, -it.first.second);
			if(st.count(opp))
				res += 1LL * it.second * st[opp];
		}
		cout << res / 2 << '\n';
	}
}