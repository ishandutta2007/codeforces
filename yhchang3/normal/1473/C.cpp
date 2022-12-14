#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		int n, k;
		cin >> n >> k;
		int x = k - (n - k + 1);
		for(int i=1;i<=x;i++)
			cout << i << ' ' ;
		for(int i=k;i>x;i--)
			cout << i << ' ';
		cout << '\n';
	}
}