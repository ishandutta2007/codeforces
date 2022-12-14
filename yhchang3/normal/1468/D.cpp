#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		int n, m, a, b;
		cin >> n >> m >> a >> b;
		if(b < a) a = n + 1 - a, b = n + 1 - b;
		vector<int> s(m);
		for(int &x:s)
			cin >> x;
		sort(s.begin(), s.end());
		int l = 0, r = m;
		auto check = [&](const int& x) -> bool {
			int M = 0;
			for(int i=0;i<x;i++)
				M = max(s[i] + x - i, M);
			if(b - a > x && b - 1 > M - 1)
				return true;
			return false;
		};
		while(l < r) {
			int mid = (l + r + 1) >> 1;
			if(check(mid))
				l = mid;
			else
				r = mid - 1;
		}
		cout << l << '\n';
	}
}