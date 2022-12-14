#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		int c[3], a[5];
		for(int i=0;i<3;i++)
			cin >> c[i];
		for(int i=0;i<5;i++)
			cin >> a[i];
		if(a[0] <= c[0] && a[1] <= c[1] && max(0, a[3] - (c[0] - a[0])) + max(0, a[4] - (c[1] - a[1])) + a[2] <= c[2])
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}