#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i) 
#define R(i, j, k) for(int i = (j); i >= (k); --i) 
#define ll long long 
#define sz(a) ((int) (a).size())
#define vi vector < int > 
#define me(a, x) memset(a, x, sizeof(a)) 
using namespace std;
const int N = 1e6 + 7, mod = 998244353;
int n, z, a[N]; 
void Main() {
	cin >> n >> z;
	int ns = 0;
	L(i, 1, n) 
		cin >> a[i], ns = max(ns, a[i] | z);
	cout << ns << '\n';
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--) Main(); 
	return 0;
}