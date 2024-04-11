#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;
const int N = 1 << 19, inf = 1e9;


struct RMQ {
	int a[N], mx[20][N], lg[N];
	void init (int n) {
		L(i, 2, n) lg[i] = lg[i >> 1] + 1;
		L(i, 1, n) mx[0][i] = i;
		L(i, 1, 19)
			L(j, 1, n - (1 << i) + 1) 
				mx[i][j] = a[mx[i - 1][j]] > a[mx[i - 1][j + (1 << (i - 1))]] ? 
					mx[i - 1][j] : mx[i - 1][j + (1 << (i - 1))];
	}
	int queryp (int l, int r) {
		int p = lg[r - l + 1];
		return a[mx[p][l]] < a[mx[p][r - (1 << p) + 1]] ? mx[p][r - (1 << p) + 1] : mx[p][l];
	}
	int query (int l, int r) { return a[queryp (l, r)]; }
} ;


int n, q;
int op[N], ql[N], qr[N], qw[N];

int need[N], mn[N];
void build(int x, int L, int R) {
	need[x] = R - L + 1;
	if(L == R) return ;
	int mid = (L + R) >> 1;
	build(x << 1, L, mid);
	build(x << 1 | 1, mid + 1, R);
}
void cov(int x, int L, int R, int l, int r, int w) {
	if(!need[x]) return ;
	if(L == R) {
		mn[L] = w;
		need[x] = 0;
		return ;
	}
	int mid = (L + R) >> 1;
	if(l <= mid) cov(x << 1, L, mid, l, r, w);
	if(r > mid) cov(x << 1 | 1, mid + 1, R, l, r, w);
	need[x] = need[x << 1] + need[x << 1 | 1];
}

int pa, sum ;
int chk[N];
inline void query(int x, int L, int R, int l, int r) {
	if(sum > 1) return ;
	if(!need[x]) return ;
	if(L == R) {
		sum += 1;
		pa = L;
		return ;
	}
	int mid = (L + R) >> 1;
	if(l <= mid) query(x << 1, L, mid, l, r);
	if(r > mid) query(x << 1 | 1, mid + 1, R, l, r);
}

RMQ a;

void Main () {
	cin >> n >> q;
	L(i, 1, q) {
		cin >> op[i];
		if(op[i] == 0) {
			cin >> ql[i] >> qr[i] >> qw[i]; 
		} else {
			cin >> ql[i];
		}
	} 
	
	build(1, 1, n);
	L(i, 1, n) mn[i] = inf;
	L(i, 1, q) if(op[i] == 0 && !qw[i]) {
//		cout << ql[i] << " to " << qr[i] << '\n';
		cov(1, 1, n, ql[i], qr[i], i);
	}
	
//	cout << "Need = " << need[1] << '\n';
	
	L(i, 1, n) {
		if(mn[i] == inf) a.a[i] = 0;
		else a.a[i] = mn[i];
	}
	a.init(n);
	
	
	L(i, 1, q) if(op[i] == 0 && qw[i]) {
		sum = 0, pa = 0;
		query(1, 1, n, ql[i], qr[i]);
		if(!sum) assert(false);
//		cout << sum << ' ' << pa << endl;
		if(sum == 1) 
			mn[pa] = min(mn[pa], max(a.query(ql[i], qr[i]), i)), chk[pa] = 1;
	}
	
//	L(i, 1, n) {
//		cout << mn[i] << ' ';
//	}
//	cout << endl;
	
	L(i, 1, q) {
		if(op[i] == 1) {
			int x = ql[i];
			if(mn[x] > i) {
				cout << "N/A\n";
			} else {
				if(chk[x]) cout << "YES\n";
				else cout << "NO\n";
			}
		}
	}
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	Main ();
	return 0;
}