#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rsz resize
//testing template below from Benq's github
namespace input {
	template<class T> void re(complex<T>& x);
	template<class T1, class T2> void re(pair<T1,T2>& p);
	template<class T> void re(vector<T>& a);
	template<class T, size_t SZ> void re(array<T,SZ>& a);

	template<class T> void re(T& x) { cin >> x; }
	void re(double& x) { string t; re(t); x = stod(t); }
	void re(ld& x) { string t; re(t); x = stold(t); }
	template<class T, class... Ts> void re(T& t, Ts&... ts) { 
		re(t); re(ts...); 
	}

	template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
	template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
	template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
	template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}

using namespace input;

namespace output {
	void pr(int x) { cout << x; }
	void pr(long x) { cout << x; }
	void pr(ll x) { cout << x; }
	void pr(unsigned x) { cout << x; }
	void pr(unsigned long x) { cout << x; }
	void pr(unsigned long long x) { cout << x; }
	void pr(float x) { cout << x; }
	void pr(double x) { cout << x; }
	void pr(ld x) { cout << x; }
	void pr(char x) { cout << x; }
	void pr(const char* x) { cout << x; }
	void pr(const string& x) { cout << x; }
	void pr(bool x) { pr(x ? "true" : "false"); }
	template<class T> void pr(const complex<T>& x) { cout << x; }
	
	template<class T1, class T2> void pr(const pair<T1,T2>& x);
	template<class T> void pr(const T& x);
	
	template<class T, class... Ts> void pr(const T& t, const Ts&... ts) { 
		pr(t); pr(ts...); 
	}
	template<class T1, class T2> void pr(const pair<T1,T2>& x) { 
		pr("{",x.f,", ",x.s,"}"); 
	}
	template<class T> void pr(const T& x) { 
		pr("{"); // const iterator needed for vector<bool>
		bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0; 
		pr("}");
	}
	
	void ps() { pr("\n"); } // print w/ spaces
	template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
		pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
	}
	
	void pc() { pr("]\n"); } // debug w/ commas
	template<class T, class... Ts> void pc(const T& t, const Ts&... ts) { 
		pr(t); if (sizeof...(ts)) pr(", "); pc(ts...); 
	}
	#define dbg(x...) pr("[",#x,"] = ["), pc(x);
}

using namespace output;

namespace io {
	void setIn(string s) { freopen(s.c_str(),"r",stdin); }
	void setOut(string s) { freopen(s.c_str(),"w",stdout); }
	void setIO(string s = "") {
		cin.sync_with_stdio(0); cin.tie(0); // fast I/O
		// cin.exceptions(cin.failbit); // ex. throws exception when you try to read letter into int
		if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
	}
}

using namespace io;
const int MOD = (119 << 23) + 1, root = 3; // = 998244353

template<class T> struct modular {
	T val; 
	explicit operator T() const { return val; }
	modular() { val = 0; }
	modular(const ll& v) { 
		val = (-MOD <= v && v <= MOD) ? v : v % MOD;
		if (val < 0) val += MOD;
	}
	// friend ostream& operator<<(ostream& os, const modular& a) { return os << a.val; }
	friend void pr(const modular& a) { pr(a.val); }
	friend void re(modular& a) { ll x; re(x); a = modular(x); }
   
	friend bool operator==(const modular& a, const modular& b) { 
		return a.val == b.val; }
	friend bool operator!=(const modular& a, const modular& b) { 
		return !(a == b); }
	friend bool operator<(const modular& a, const modular& b) { 
		return a.val < b.val; }

	modular operator-() const { return modular(-val); }
	modular& operator+=(const modular& m) { 
		if ((val += m.val) >= MOD) val -= MOD; return *this; }
	modular& operator-=(const modular& m) { 
		if ((val -= m.val) < 0) val += MOD; return *this; }
	modular& operator*=(const modular& m) { 
		val = (ll)val*m.val%MOD; return *this; }
	friend modular pow(modular a, ll p) {
		modular ans = 1; 
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend modular inv(const modular& a) { 
		assert(a != 0); return pow(a,MOD-2); 
	}
	modular& operator/=(const modular& m) { 
		return (*this) *= inv(m); }
	
	friend modular operator+(modular a, const modular& b) { 
		return a += b; }
	friend modular operator-(modular a, const modular& b) { 
		return a -= b; }
	friend modular operator*(modular a, const modular& b) { 
		return a *= b; }
	
	friend modular operator/(modular a, const modular& b) { 
		return a /= b; }
};

typedef modular<int> mi;
typedef pair<mi,mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;
const ld PI = acos(-1);
typedef complex<double> cd;
typedef vector<cd> vcd;
// NTT: For p < 2^30 there is also e.g. (5 << 25, 3), 
// (7 << 26, 3), (479 << 21, 3) and (483 << 21, 5). 
// The last two are > 10^9.

int size(int s) { return s > 1 ? 32-__builtin_clz(s-1) : 0; }
void genRoots(vcd& roots) { // primitive n-th roots of unity
	int n = sz(roots); double ang = 2*PI/n;
	// is there a way to compute these trig functions more quickly w/o issues?
	F0R(i,n) roots[i] = cd(cos(ang*i),sin(ang*i)); 
}
void genRoots(vmi& roots) { 
	int n = sz(roots); mi r = pow(mi(root),(MOD-1)/n);
	roots[0] = 1; FOR(i,1,n) roots[i] = roots[i-1]*r;
}

template<class T> void fft(vector<T>& a, const vector<T>& roots, bool inv = 0) {
	int n = sz(a);
	// sort numbers from 0 to n-1 by reverse bit representation
	for (int i = 1, j = 0; i < n; i++) { 
		int bit = n>>1;
		for (; j&bit; bit >>= 1) j ^= bit;
		j ^= bit; if (i < j) swap(a[i], a[j]);
	}
	for (int len = 2; len <= n; len <<= 1) 
		for (int i = 0; i < n; i += len) 
			F0R(j,len/2) {
				int ind = n/len*j; if (inv && ind) ind = n-ind;
				// for xor conv don't multiply by roots[ind]
				auto u = a[i+j], v = a[i+j+len/2]*roots[ind]; 
				a[i+j] = u+v, a[i+j+len/2] = u-v;
			}
	if (inv) { T i = T(1)/T(n); trav(x,a) x *= i; }
}
template<class T> vector<T> mult(vector<T> a, vector<T> b) {
	if (!min(sz(a),sz(b))) return {};
	int s = sz(a)+sz(b)-1, n = 1<<size(s);
	vector<T> roots(n); genRoots(roots);
	a.rsz(n), fft(a,roots); b.rsz(n), fft(b,roots);
	F0R(i,n) a[i] *= b[i];
	fft(a,roots,1); a.rsz(s); return a;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	map<int,int> ma;
	for(int i=0;i<n;i++)
	{
		int x; cin>>x; ma[x]++;
	}
	deque<vector<mi> > polyprod;
	for(auto it:ma)
	{
		int siz=it.se;
		vector<mi> nw(siz+1,1);
		polyprod.pb(nw);
	}
	while(polyprod.size()>=2)
	{
		vector<mi> res = mult(polyprod[0],polyprod[1]);
		polyprod.pop_front(); polyprod.pop_front(); polyprod.pb(res);
	}
	cout<<int(polyprod[0][n/2])<<'\n';
}