#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int > 
#define sz(a) ((int) a.size()) 
#define uint unsigned int 
using namespace std;
const int N = 1e6 + 7, inf = 1e9;
int n, q, dp[4];
char s[N], op[N];
struct Mat {
	int f[4][4];
	Mat (int x = 0) {
		L(i, 0, 3) 
			L(j, 0, 3) 
				f[i][j] = i == j ? x : inf;
	}
} ;
Mat operator * (Mat a, Mat b) {
	Mat ret (inf); 
	L(i, 0, 3) L(j, 0, 3) L(k, 0, 3) ret.f[i][j] = min(ret.f[i][j], a.f[i][k] + b.f[k][j]);
	return ret;
}
Mat f[N];
void add (int x, int L, int R, int p, int c) {
	if(L == R) {
		f[x] = Mat (0);
		f[x].f[c + 1][c + 1] = 1;
		f[x].f[c][c + 1] = 0;
		return ;
	}
	int mid = (L + R) >> 1;
	if(p <= mid) add (x << 1, L, mid, p, c);
	else add (x << 1 | 1, mid + 1, R, p, c);
	f[x] = f[x << 1] * f[x << 1 | 1];
}
int main() { 
	ios :: sync_with_stdio (false);
	cin.tie (0); cout.tie (0);
	cin >> n >> q;
	cin >> (s + 1);
	L(i, 1, n) add (1, 1, n, i, s[i] - 'a');
	while (q--) {
		int p;
		cin >> p >> (op + 1);
		add (1, 1, n, p, op[1] - 'a');
		int ns = 1e9;
		L(i, 1, 3) ns = min(ns, f[1].f[i][3]);
		cout << ns << '\n';
	}
	return 0;
}