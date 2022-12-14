#include<bits/stdc++.h>
using namespace std;

int a[110], b[110], t[110];

int main() {
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> a[i] >> b[i];
		for(int i=1;i<=n;i++)
			cin >> t[i];
		int ans = 0;
		for(int i=0;i<n;i++) {
			if(i != 0) {
				ans = max(b[i], ans + (b[i] - a[i] + 1) / 2);
			}
			ans += a[i + 1] - b[i] + t[i + 1];
		}
		cout << ans << '\n';
	}
}