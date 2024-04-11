// easy, tricky *2800 ? 
// and fuck for wasting my time.
#include<bits/stdc++.h>
using namespace std;
const int V = 1e6 + 5, N = 5e4 + 5;
int n, m, s[V], a[N], ans[N], mx[N];
vector < pair < int, int > > qr[N];
void ckmax(int &a, int b) { a = max(a, b); }
int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) 
		scanf("%d", &a[i]);
	for(int i = 1; i <= m; i++) {
		int l, r; scanf("%d %d", &l, &r);
		qr[r].push_back(make_pair(l, i));
	}
	for(int i = 1; i <= 1e6; i++) s[i] = s[i - 1] ^ i;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= i; j++) ckmax(mx[j], s[min(a[j], a[i]) - 1] ^ s[max(a[j], a[i])]);
		for(auto it : qr[i]) {
			for(int j = it.first; j <= i; j++) ckmax(ans[it.second], mx[j]);
		}
	}
	for(int i = 1; i <= m; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}