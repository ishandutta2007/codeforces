#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int > 
#define sz(a) ((int) a.size()) 
#define uint unsigned int 
using namespace std;
const int N = 1e6 + 7;
int n, d, f[N], siz[N];
int find (int x) {
	return f[x] == x ? x : f[x] = find (f[x]);
}
int nt = 1;
int main() { 
	ios :: sync_with_stdio (false);
	cin.tie (0); cout.tie (0);
	cin >> n >> d;
	L(i, 1, n) f[i] = i, siz[i] = 1;
	L(i, 1, d) {
		int x, y;
		cin >> x >> y;
		int u = find(x), v = find (y);
		if (u != v) f[u] = v, siz[v] += siz[u];
		else nt += 1;
		int ns = 0;
		vi S;
		L(j, 1, n) if(find(j) == j) S.push_back(siz[j]);
		sort(S.begin(), S.end());
		int g = 0;
		R(j, sz(S) - 1, 0) {
			g += 1;
			if(g <= nt) ns += S[j];
		}
		cout << ns - 1 << '\n';
	}
	return 0;
}