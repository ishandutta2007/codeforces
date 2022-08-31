#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 7;
int val, n, k;
void Main() {
	cin >> n >> k, --k;
	if(n % 2 == 0) cout << k % n + 1 << "\n";
	else cout << (k / (n / 2) + k) % n + 1 << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while(T--) Main();
	return 0;
}