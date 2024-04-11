#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		string s, t;
		cin >> s >> t;
		int l = lcm(s.size(), t.size());
		string ss, tt;
		while(ss.size() != l)
			ss += s;
		while(tt.size() != l)
			tt += t;
		if(ss == tt)
			cout << ss << '\n';
		else
			cout << -1 << '\n';
	}
}