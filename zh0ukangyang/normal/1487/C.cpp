#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 7;
int val, n, k;
void Main() {
	cin >> n; 
	if(n % 2 == 0) {
		for(int i = 1; i <= n; i++) for(int j = i + 1; j <= n; j++) {
			if(abs(i - j) == n / 2) cout << "0 ";
			if(abs(i - j) < n / 2) cout << "1 ";
			if(abs(i - j) > n / 2) cout << "-1 ";
		}
	}
	else {
		for(int i = 1; i <= n; i++) for(int j = i + 1; j <= n; j++) {
			if(abs(i - j) <= n / 2) cout << "1 ";
			else cout << "-1 ";
		}
	}
	cout << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while(T--) Main();
	return 0;
}