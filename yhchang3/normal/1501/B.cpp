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
		vector<int> a(n), c(n + 1);
		for(int i=0;i<n;i++)
			cin >> a[i], c[i + 1]--, c[max(0, i - a[i] + 1)]++;
		for(int i=1;i<=n;i++)
			c[i] += c[i - 1];
		for(int i=0;i<n;i++)
			cout << (c[i] != 0) << ' ';
		cout << '\n';
	}
}