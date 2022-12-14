#include<bits/stdc++.h>
using namespace std;

int b[200010];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		int n, k, m;
		cin >> n >> k >> m;
		for(int i=1;i<=m;i++)
			cin >> b[i];
		if((n - m) % (k - 1)) {
			cout << "NO" << '\n';
			continue;
		}
		bool ok = false;
		for(int i=1;i<=m;i++)
			if(b[i] - 1 - (i - 1) >= (k - 1) / 2 && (n - b[i]) - (m - i) >= (k - 1) / 2)
				ok = true;
		if(ok)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
}