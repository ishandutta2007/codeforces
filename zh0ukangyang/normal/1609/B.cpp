#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int > 
#define sz(a) ((int) a.size()) 
#define uint unsigned int 
using namespace std;
const int N = 5e5 + 7;
int n, q, ret;
char s[N], op[N];
int get (int x) {
	return x > 0 && x <= n - 2 && s[x] == 'a' && s[x + 1] == 'b' && s[x + 2] == 'c';
}
int main() { 
	ios :: sync_with_stdio (false);
	cin.tie (0); cout.tie (0);
	cin >> n >> q >> (s + 1);
	L(i, 1, n) ret += get (i);
	while (q--) {
		int p;
		cin >> p >> (op + 1);
		ret -= get (p) + get (p - 1) + get (p - 2);
		s[p] = op[1];
		ret += get (p) + get (p - 1) + get (p - 2);
		cout << ret << '\n';
	}
	return 0;
}