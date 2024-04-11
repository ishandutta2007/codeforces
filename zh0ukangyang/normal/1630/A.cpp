#include <bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
using namespace std;
const int N = 1e6 + 7;
int n, k, lg, a[N], mat[N];
void Main () {
	cin >> n >> k;
	lg = log2(n);
	if(n == 4 && k == 3) {
		cout << -1 << '\n';
		return ;
	}
//	L(i, 0, n - 1) mat[i] = n - i - 1;
	if(k <= n - 2 && k) {
		cout << k << ' ' << n - 1 << '\n';
		cout << 0 << ' ' << ((n - 1) ^ k) << '\n';
		L(i, 0, n / 2 - 1) if(i != k && i != n - 1 
			&& i != 0 && i != ((n - 1) ^ k)) cout << i << ' ' << n - i - 1 << '\n';
	} else if(!k) {
		L(i, 0, n / 2 - 1) 
			cout << i << ' ' << n - i - 1 << '\n';
	} else {
		int mid = n / 4;
		cout << mid - 1 << ' ' << mid * 3 - 1 << '\n';
		cout << mid << ' ' << mid * 3 << '\n';
		cout << 0 << ' ' << n / 2 - 1 << '\n';
		cout << n / 2 << ' ' << n - 1 << '\n';
		L(i, 1, n / 2 - 2) if(i != mid && i != mid - 1) {
			cout << i << ' ' << n - i - 1 << '\n';
		}
	}
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) Main (); 
	return 0;
}