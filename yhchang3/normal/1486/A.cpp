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
		vector<long long> v(n);
		for(int i=0;i<n;i++)
			cin >> v[i];
		v.emplace_back(0);
		v[1] += v[0], v[0] = 0;
		bool ok = true;
		for(int i=1;i<n;i++)
			if(v[i] > v[i - 1]) {
				v[i + 1] += v[i] - v[i - 1] - 1;
				v[i] = v[i - 1] + 1;
			}
			else {
				ok = false;
			}
		if(ok)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
}