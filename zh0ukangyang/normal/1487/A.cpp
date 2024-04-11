#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 7;
int val, n, a[N];
void Main() {
	val = 1e9;
	cin >> n;
	for(int i =1 ; i <= n; i++) cin >> a[i], val = min(val, a[i]);
	int ans = 0;
	for(int i = 1; i <= n; i++) if(a[i] > val) ans++;
	cout << ans << "\n"; 
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while(T--) Main();
	return 0;
}