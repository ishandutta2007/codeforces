#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;
const int N = 1e6 + 7, mod = 998244353;
int n, m, a[N];
void Main() {
	cin >> n >> m;
	L(i, 1, n) {
		cin >> a[i];
	} 
	sort(a + 1, a + n + 1);
	L(i, 1, n) {
		int p = lower_bound(a + 1, a + n + 1, a[i] + m) - a;
		if(p <= n && a[p] == a[i] + m) {
			cout << "YES\n";
			return ;
		} 
	}
	cout << "NO\n";
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}