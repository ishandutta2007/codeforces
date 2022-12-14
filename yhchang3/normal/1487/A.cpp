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
		map<int,int> M;
		for(int i=0,x;i<n;i++)
			cin >> x, M[x]++;
		cout << n - M.begin() -> second << '\n';
	}
}