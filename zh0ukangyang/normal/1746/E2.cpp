#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int > 
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long
#define ld __float128
using namespace std;
const int N = 1e5 + 7;
//inline pair < int, int > get(int x, int y) {
//	return make_pair(x / 2, (y + 1) / 2);
//}

map < int, int > mp[N];
int sx[14][14], sy[14][14]; 
inline int query(int x, int y) {
	if(x + y <= 2) return 0;
	if(mp[x].count(y)) return mp[x][y];
	int a = x / 2;
	int b = (y + 1) / 2;
	if(x == 1 && y == 2) a = 0, b = 2;
	int val = max(query(y - b, a + b), query(b, x - a + y - b)) + 1;
	mp[x][y] = val;
	if(x <= 10 && y <= 10) {
		L(a, 0, x) L(b, 0, y) {
			int ovo = max(query(y - b, a + b), query(b, x - a + y - b)) + 1;
			if(ovo < val) 
				sx[x][y] = a, sy[x][y] = b, val = ovo;
		}
	}
	return mp[x][y] = val;
}
int n, ok = 0;
int q0[N], tp0;
int q1[N], tp1;
bool vis[N];
void query(vi S) {
	cout << "? " << sz(S) << ' ';
	for(auto u : S) cout << u << ' ';
	cout << endl;
	string s;
	cin >> s;
	if(s == "NO") {
		me(vis, 1);
		for(auto u : S) vis[u] = 0; 
	} else {
		me(vis, 0);
		for(auto u : S) vis[u] = 1;
	}
	vi s0, s1; 
	L(i, 1, tp0) {
		if(vis[q0[i]]) {
			s1.emplace_back(q0[i]);
		}
	}
	L(i, 1, tp1) {
		if(vis[q1[i]]) {
			s1.emplace_back(q1[i]);
		} else {
			s0.emplace_back(q1[i]);
		}
	}
	tp0 = tp1 = 0;
	for(auto u : s0) q0[++tp0] = u;
	for(auto u : s1) q1[++tp1] = u;
}
int main() {
//	cout << query(0, 1e5) << '\n';
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	me(sx, -1), me(sy, -1);
	query(0, 1e5);
	
	L(i, 1, n) q1[++tp1] = i;
	while(tp0 + tp1 > 2) {
		vi S;
		int x = tp0 / 2, y = (tp1 + 1) / 2;
		if(tp0 == 1 && tp1 == 2) {
			x = 0, y = 2;
		}
		if(tp0 <= 10 && tp1 <= 10 && sx[tp0][tp1] != -1) {
			x = sx[tp0][tp1], y = sy[tp0][tp1];
		}
		L(i, 1, x) S.emplace_back(q0[i]);
		L(i, 1, y) S.emplace_back(q1[i]);
		query(S);
	}
	
	vi S;
	L(i, 1, tp0) S.emplace_back(q0[i]);
	L(i, 1, tp1) S.emplace_back(q1[i]); 
	for(auto u : S) {
		cout << "! " << u << endl;
		string a;
		cin >> a;
		if(a == ":)") break;
	} 
	return 0;
}