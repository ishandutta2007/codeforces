#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, d;
	cin >> n >> d;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin >> a[i];
	int ans = 0;
	for(int i=1;i<n;i++) {
		if(a[i] <= a[i - 1]) {
			int D = a[i - 1] + 1 - a[i];
			ans += (D - 1) / d + 1;
			a[i] += ((D - 1) / d + 1) * d;
		}
	}
	cout << ans << endl;
}