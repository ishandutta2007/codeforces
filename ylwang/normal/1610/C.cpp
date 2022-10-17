#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5; 
int n, a[N], b[N];
int check(int x) {
	int c = 0; 
	for(int i = 1; i <= n; i++) 
		if(x - c - 1 <= a[i] && c <= b[i]) c++;
	return c >= x;
}
void works() {
	scanf("%d", &n); 
	for(int i = 1; i <= n; i++) {
		scanf("%d %d", &a[i], &b[i]);
	}
	int l = 1, r = n, ans = -1; 
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}	
	cout << ans << endl; 
}
int main() {
	int t; cin >> t;
	while(t--) 
		works(); 	
}