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
int n, k, a[N], ns[N];
void Main() {
	cin >> n;
	L(i, 1, n) {
		cin >> a[i];
	}
	priority_queue < pair < int, int > > q;
	L(i, 1, n - 1) {
		if(a[i] > a[i + 1]) {
			q.push(make_pair(a[i] - a[i + 1], i + 1));
		}
	}
	R(i, n, 1) {
		if(sz(q)) {
			auto u = q.top();
			q.pop();
			ns[i] = u.second;
			u.first -= i;
			if(u.first > 0) q.push(u);
		} else {
			ns[i] = 1;
		}
	}
	assert(!sz(q));
	L(i, 1, n) cout << ns[i] << ' ';
	cout << '\n';
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main(); 
	return 0;
}