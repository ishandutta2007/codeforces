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
int n, m;
pair < int, int > a[N]; 
void Main() {
	cin >> n;
	L(i, 1, n) {
		cin >> a[i].first;
		a[i].second = i;
	} 
	sort(a + 1, a + n + 1);
	cout << a[1].second << ' ' << a[n].second << '\n';
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}