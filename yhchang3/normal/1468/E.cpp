#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		vector<int> v(4);
		for(int i=0;i<4;i++)
			cin >> v[i];
		sort(v.begin(), v.end());
		cout << v[0] * v[2] << '\n';
	}
}