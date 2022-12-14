#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	map<char,int> M = {
		{'U', 0},
		{'D', 1},
		{'R', 2},
		{'L', 3}
	};
	while(T--) {
		int x, y;
		string s;
		vector<int> cnt(4);
		cin >> x >> y >> s;
		for(char c:s)
			cnt[M[c]]++;
		if(x >= -cnt[3] && x <= cnt[2] && y >= -cnt[1] && y <= cnt[0])
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
}