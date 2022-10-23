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
int n, x, a[N], cnt[N];
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> x;
	L(i, 1, n) {
		cin >> a[i];
		cnt[a[i]] += 1;
	}
	L(i, 1, x - 1) {
		if(cnt[i] % (i + 1)) {
			cout << "No\n";
			return 0;
		}
		cnt[i + 1] += cnt[i] / (i + 1);
	}
	cout << "Yes\n";
	return 0;
}