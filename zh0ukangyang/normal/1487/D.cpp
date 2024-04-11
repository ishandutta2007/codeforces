#include<bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
const int N = 1e6 + 7;
int val, n, k;
void Main() {
	cin >> n;
	cout << ((int) floor(sqrt((db) 2 * n - 1)) - 1) / 2 << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while(T--) Main();
	return 0;
}