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
		vector<int> ans;
		while(n != 2) {
			int x = sqrt(n);
			while(x * x < n)	x++;
			for(int i=x+1;i<n;i++)
				ans.emplace_back(i), ans.emplace_back(n);
			ans.emplace_back(n), ans.emplace_back(x);
			ans.emplace_back(n), ans.emplace_back(x);
			n = x;
		}
		cout << ans.size() / 2 << '\n';
		for(int i=0;i<ans.size();i+=2)
			cout << ans[i] << ' ' << ans[i+1] << '\n';
	}
}