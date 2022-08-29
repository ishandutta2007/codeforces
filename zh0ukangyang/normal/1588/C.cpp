#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1 << 19;
struct RMQ { // getmin
	ll a[N];
	int mx[20][N], lg[N];
	void init (int n) {
		L(i, 2, n) lg[i] = lg[i >> 1] + 1;
		L(i, 1, n) mx[0][i] = i;
		L(i, 1, 19)
			L(j, 1, n - (1 << i) + 1) 
				mx[i][j] = a[mx[i - 1][j]] < a[mx[i - 1][j + (1 << (i - 1))]] ? 
					mx[i - 1][j] : mx[i - 1][j + (1 << (i - 1))];
	}
	int queryp (int l, int r) {
		int p = lg[r - l + 1];
		return a[mx[p][l]] > a[mx[p][r - (1 << p) + 1]] ? mx[p][r - (1 << p) + 1] : mx[p][l];
	}
	ll query (int l, int r) { return a[queryp (l, r)]; }
} ;
RMQ A, B;
int n, a[N], pos[N];
ll pre0[N];
ll pre1[N];
vector < pair < ll, int > > S[N];
map < ll, int > mp;
void Main () {
	cin >> n ;
	L(i, 1, n) 
		cin >> a[i];
	L(i, 1, n) {
		if(i & 1) pre0[i] = -a[i], pre1[i] = a[i];
		else pre0[i] = a[i], pre1[i] = -a[i];
		pre0[i] += pre0[i - 1];
		pre1[i] += pre1[i - 1];
	}
	L(i, 1, n) {
		if(i & 1) A.a[i] = pre1[i], B.a[i] = 1e18;
		else A.a[i] = 1e18, B.a[i] = pre0[i];
	}
	A.init(n);
	B.init(n);   
	ll ns = 0;
	L(i, 1, n) {
		int p = n ;
		int l = i, r = n;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if(B.query (i, mid) < pre0[i - 1]) 
				p = min(p, mid), r = mid - 1;
			else 
				l = mid + 1;
		}
		l = i, r = n;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if(A.query (i, mid) < pre1[i - 1]) 
				p = min(p, mid), r = mid - 1;
			else 
				l = mid + 1;
		}
		S[p].push_back ({pre0[i - 1], 1});
		S[i - 1].push_back ({pre0[i - 1], -1});
	}
	mp.clear ();
	L(i, 1, n) {
		mp[pre0[i]] += 1;
		for (auto u : S[i]) 
			ns += mp[u.first] * u.second;
	}
	cout << ns << '\n'; 
	L(i, 0, n + 1) S[i].clear ();
} 
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}