#include<bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int n, k;
		cin >> n >> k;
		cout << k / 2 + n - k << '\n';
		for(int i=(k+1)/2;i<k;i++)
			cout << i << ' ';
		for(int i=k+1;i<=n;i++)
			cout << i << ' ';
		cout << '\n';
	}
}