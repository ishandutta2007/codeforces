#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f)) 
#define uint unsigned int
using namespace std;
const int N = 1e6 + 7;
int n, a[N]; 
void Main() {
	cin >> n;
	L(i, 1, n) {
		cin >> a[i];
	}
	int ns = a[n] - a[1];
	L(i, 1, n - 1) {
		ns = max(ns, a[i] - a[i + 1]);
		ns = max(ns, a[n] - a[i]);
		ns = max(ns, a[i + 1] - a[1]);
	}
	cout << ns << '\n';
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}