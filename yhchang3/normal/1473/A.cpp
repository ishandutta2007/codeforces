#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		int n, d;
		cin >> n >> d;
		vector<int> v(n);
		for(int &it:v)
			cin >> it;
		sort(v.begin(), v.end());
		if(v.back() <= d || v[0] + v[1] <= d)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}