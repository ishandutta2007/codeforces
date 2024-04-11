#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int > 
#define sz(a) ((int) a.size()) 
using namespace std;
const int N = 1e6 + 7; 
int n, a[N], b[N], tp;
bool check (int x) {
	tp = 0;
	L(i, 1, n) if(a[i] != x) b[++tp] = a[i];
	L(i, 1, tp) if(b[i] != b[tp - i + 1]) return false;
	return true;
}
void Main () {
	cin >> n;
	L(i, 1, n) cin >> a[i];
	L(i, 1, n / 2) if(a[i] != a[n - i + 1]) {
		if(check(a[i]) || check(a[n - i + 1])) cout << "YES\n";
		else cout << "NO\n";
		return ;
	}
	cout << "YES\n";
}
int main() { 
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	int T;
	cin >> T;
	while(T--) Main ();
	return 0;
}