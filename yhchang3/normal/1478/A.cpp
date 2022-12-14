#include<bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		map<int, int> M;
		for(int i=0,x;i<n;i++)
			cin >> x, M[x]++;
		int ans = 0;
		for(auto [_, x]:M)
			ans = max(ans, x);
		cout << ans << endl;
	}
}