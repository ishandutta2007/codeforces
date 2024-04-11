#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
using namespace std;
const int N = 5e5 + 7;
int n, pw[26], c[N], a[N], ch[N];
string s[N];
int fi[5][20000], lst[5][200000];
int getid (string o) {
	int r = 0;
	for (auto u : o) r *= 26, r += u - 'a';
	return r;
}
bool check() {
	bool ok = false; 
	me(fi, 0);
	me(lst, 0);
	L(i, 1, n) {
		int len = sz(s[i]);
		L(o, 0, 1) {
			string q;
			R(x, len - 1, o) q.push_back(s[i][x]);
			if(fi[sz(q)][getid(q)]) ok = true;
		}
		int w = getid (s[i]);
		if(!fi[len][w]) fi[len][w] = i;
		lst[len][w] = i;
	}
	return ok;
}
void Main () {
	cin >> n;
	L(i, 1, n) cin >> s[i];
	L(i, 1, n) {
		auto t = s[i];
		reverse(t.begin(), t.end());
		if(t == s[i]) return cout << "YES\n", void ();
	}
	if(check()) return cout << "YES\n", void ();
	reverse(s + 1, s + n + 1);
	L(i, 1, n) reverse(s[i].begin(), s[i].end());
	if(check()) return cout << "YES\n", void ();
	cout << "NO\n";
}
int main () { 
	pw[0] = 1;
	L(i, 1, 10) pw[i] = pw[i - 1] * 26; 
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}
/*
1
3
a
b
bad
*/