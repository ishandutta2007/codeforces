#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int > 
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long
#define ld __float128
using namespace std;
const int N = 1e6 + 7;
int n, k, a[N], cnt[2], tmp[2];
void Main() {
	cin >> n ;
	L(i, 1, n) cin >> a[i];
	me(cnt, 0), me(tmp, 0);
	L(i, 1, n) {
		cnt[a[i]] += 1;
	}
	
	int ns = cnt[0];
	L(i, 1, n) {
		if(a[i] == 1) {
			ns = max(ns, tmp[0] + cnt[1] - tmp[1] + min(tmp[1], cnt[0] - tmp[0]));
		}
		tmp[a[i]] += 1;
	}
	
	cout << n - ns << '\n';
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main(); 
	return 0;
}