#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 256;
int n, m, a[N], b[N], c[N];
int col[N][N]; 
bitset < 256 > lb[256][3];
int qt[256], ok;
void ins (bitset < 256 > x[3], int w) {
	R(i, 255, 0) {
		if(x[2][i]) 
			swap(x[1], x[2]), w = w * 2 % 3;
		if(x[1][i]) {
			if(qt[i] == -1) {
				L(o, 0, 2) lb[i][o] = x[o];
				qt[i] = w;
				return ;
			} 
			else {
				w -= qt[i];
				if(w < 0) w += 3;
				
				bitset < 256 > ns[3];
				L(u, 0, 2) L(v, 0, 2) 
					ns[(u - v + 3) % 3] |= x[u] & lb[i][v];
				L(o, 0, 2) x[o] = ns[o];
			}
		}
//		if(i > 3) continue;
//		L(t, 0, 2) {
//			L(o, 0, 2) if(x[o][t]) cout << o << ' ';
//		}
//		cout << '\n';
	}
	if(w != 0) 
		ok = false;
}
int ns[N];
void Main () {
	memset(col, -1, sizeof(col));
	ok = true;
	cin >> n >> m;
	L(i, 0, m - 1) {
		qt[i] = -1;
		L(o, 0, 2) lb[i][o].reset ();	
	}
	L(i, 0, m - 1) {
		cin >> a[i] >> b[i] >> c[i];
		col[a[i]][b[i]] = col[b[i]][a[i]] = i;
		if(c[i] == -1) continue ;
		bitset < 256 > o[3];
		L(j, 0, m - 1) o[0].set(j);
		o[1].set (i), o[0].reset (i);
		ins (o, c[i]);
	} 
	L(i, 1, n) 
		L(j, i + 1, n) 
			L(k, j + 1, n) 
				if(col[i][j] != -1 && col[j][k] != -1 && col[k][i] != -1) {
					bitset < 256 > o[3];
					L(j, 0, m - 1) o[0].set(j);
					o[1].set (col[i][j]), o[0].reset (col[i][j]);
					o[1].set (col[j][k]), o[0].reset (col[j][k]);
					o[1].set (col[k][i]), o[0].reset (col[k][i]);
					ins (o, 0);
				}
	if(!ok) {
		cout << "-1" << '\n';
		return ;
	}
	L(i, 0, m - 1) if(qt[i] != -1) {
		ns[i] = qt[i];
		L(j, 0, i - 1) L(o, 1, 2) if(lb[i][o][j]) {
			ns[i] -= ns[j] * o % 3;
			if(ns[i] < 0) ns[i] += 3;
		}
		if(lb[i][2][i]) ns[i] = ns[i] * 2 % 3;
	} else ns[i] = 0;
	L(i, 0, m - 1) cout << (ns[i] ? ns[i] : 3) << ' ';
	cout << '\n';
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}