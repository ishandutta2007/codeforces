#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
vector<int> fact;
vector<int> ifact;
vector<int> pow2;
const int MOD = 998244353;
int add(int a, int b)
{
	a+=b;
	while(a>=MOD) a-=MOD;
	return a;
}
void radd(int &a, int b)
{
	a=add(a,b); 
}
int mult(int a, int b)
{
	return (a*1LL*b)%MOD;
}
void rmult(int &a, int b)
{
	a=mult(a,b);
}
int modpow(int a, int b)
{
	int r=1;
	while(b)
	{
		if(b&1) r=mult(r,a);
		a=mult(a,a);
		b>>=1;
	}
	return r;
}
int choose(int a, int b)
{
	if(a<b) return 0;
	if(b==0) return 1;
	if(a==b) return 1;
	return mult(fact[a],mult(ifact[b],ifact[a-b]));
}
int inverse(int a)
{
	return modpow(a,MOD-2);
}
void init(int _n)
{
	fact.clear(); ifact.clear(); pow2.clear();
	fact.resize(_n+1);
	ifact.resize(_n+1);
	pow2.resize(_n+1);
	pow2[0]=1;
	ifact[0]=1;
	fact[0]=1;
	for(int i=1;i<=_n;i++)
	{
		pow2[i]=add(pow2[i-1],pow2[i-1]);
		fact[i]=mult(fact[i-1],i);
		//ifact[i]=mult(ifact[i-1],inv[i]);
	}
	ifact[_n] = inverse(fact[_n]);
	for(int i=_n-1;i>=1;i--)
	{
		ifact[i] = mult(ifact[i + 1], i + 1);
	}
}

#define mp make_pair
#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rsz resize
#define bk back()
#define pb push_back

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

const ld PI = acos((ld)-1);
template<class T> bool ckmin(T& a, const T& b) { 
	return b < a ? a = b, 1 : 0; }
mt19937 rng; // or mt19937_64

void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
	cerr << h; if (sizeof...(t)) cerr << ", ";
	DBG(t...); }
#ifdef LOCAL // compile with -DLOCAL
	#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
	#define dbg(...) 42
#endif

const int root = 3;
struct mi {
	typedef decay<decltype(MOD)>::type T; 
 	/// don't silently convert to T
	T v; explicit operator T() const { return v; }
	mi() { v = 0; }
	mi(ll _v) { 
		v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
		if (v < 0) v += MOD;
	}
	friend bool operator==(const mi& a, const mi& b) { 
		return a.v == b.v; }
	friend bool operator!=(const mi& a, const mi& b) { 
		return !(a == b); }
	friend bool operator<(const mi& a, const mi& b) { 
		return a.v < b.v; }
   
	mi& operator+=(const mi& m) { 
		if ((v += m.v) >= MOD) v -= MOD; 
		return *this; }
	mi& operator-=(const mi& m) { 
		if ((v -= m.v) < 0) v += MOD; 
		return *this; }
	mi& operator*=(const mi& m) { 
		v = (ll)v*m.v%MOD; return *this; }
	mi& operator/=(const mi& m) { return (*this) *= inv(m); }
	friend mi pow(mi a, ll p) {
		mi ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend mi inv(const mi& a) { assert(a.v != 0); 
		return pow(a,MOD-2); }
		
	mi operator-() const { return mi(-v); }
	mi& operator++() { return *this += 1; }
	mi& operator--() { return *this -= 1; }
	friend mi operator+(mi a, const mi& b) { return a += b; }
	friend mi operator-(mi a, const mi& b) { return a -= b; }
	friend mi operator*(mi a, const mi& b) { return a *= b; }
	friend mi operator/(mi a, const mi& b) { return a /= b; }
	friend ostream& operator<<(ostream& os, const mi &m)
	{
		os<<int(m);
		return os;
	}
};

typedef vector<mi> vmi;
typedef pair<mi,mi> pmi;
typedef vector<pmi> vpmi;

vector<vmi> comb;
void genComb(int SZ) {
	comb.assign(SZ,vmi(SZ)); comb[0][0] = 1;
	FOR(i,1,SZ) F0R(j,i+1) 
		comb[i][j] = comb[i-1][j]+(j?comb[i-1][j-1]:0);
}

// For p < 2^30 there is also e.g. (5<<25, 3), (7<<26, 3) 
/// (479<<21, 3) and (483<<21, 5). Last two are > 10^9.
void genRoots(vmi& roots) { // REPLACE DEF OF MOD
	int n = sz(roots); mi r = pow(mi(root),(MOD-1)/n);
	roots[0] = 1; FOR(i,1,n) roots[i] = roots[i-1]*r; 
}
int size(int s) { return s > 1 ? 32-__builtin_clz(s-1) : 0; }
template<class T> void fft(vector<T>& a, 
  const vector<T>& rts, bool inv = 0) {
	int n = sz(a);
	for (int i = 1, j = 0; i < n; i++) { 
		int bit = n>>1; for (; j&bit; bit /= 2) j ^= bit;
		j ^= bit; if (i < j) swap(a[i],a[j]);
	} // sort #s from 0 to n-1 by reverse binary
	for (int len = 1; len < n; len *= 2)
		for (int i = 0; i < n; i += 2*len) F0R(j,len) {
			T u = a[i+j], v = a[i+j+len]*rts[n/2/len*j];
			a[i+j] = u+v, a[i+j+len] = u-v;
		}
	if (inv) {
		reverse(1+all(a));
		T i = T(1)/T(n); trav(x,a) x *= i; 
	}
}
template<class T> vector<T> mul(vector<T> a, vector<T> b) {
	if (!min(sz(a),sz(b))) return {};
	int s = sz(a)+sz(b)-1, n = 1<<size(s);
	vector<T> roots(n); genRoots(roots);
	a.rsz(n), fft(a,roots); b.rsz(n), fft(b,roots);
	F0R(i,n) a[i] *= b[i];
	fft(a,roots,1); a.rsz(s); return a;
}
typedef mi T; using poly = vector<T>;
void remz(poly& p) { while (sz(p) && p.bk==0) p.pop_back(); }
poly rev(poly p) { reverse(all(p)); return p; }
poly shift(poly p, int x) { p.insert(begin(p),x,0); return p; }
poly RSZ(poly p, int x) { p.rsz(x); return p; }
T eval(const poly& p, T x) {
	T res = 0; R0F(i,sz(p)) res = x*res+p[i]; 
	return res; }
poly dif(const poly& p) { // differentiate
	poly res; FOR(i,1,sz(p)) res.pb(i*p[i]); 
	return res; }
poly integ(const poly& p) { // integrate
	poly res(sz(p)+1); F0R(i,sz(p)) res[i+1] = p[i]/(i+1);
	return res; }

poly& operator+=(poly& l, const poly& r) {
	l.rsz(max(sz(l),sz(r))); F0R(i,sz(r)) l[i] += r[i]; 
	return l; }
poly& operator-=(poly& l, const poly& r) {
	l.rsz(max(sz(l),sz(r))); F0R(i,sz(r)) l[i] -= r[i]; 
	return l; }
poly& operator*=(poly& l, const T& r) { trav(t,l) t *= r; 
	return l;	 }
poly& operator/=(poly& l, const T& r) { trav(t,l) t /= r; 
	return l; }
poly operator+(poly l, const poly& r) { return l += r; }
poly operator-(poly l, const poly& r) { return l -= r; }
poly operator-(poly l) { trav(t,l) t *= -1; return l; }
poly operator*(poly l, const T& r) { return l *= r; }
poly operator*(const T& r, const poly& l) { return l*r; }
poly operator/(poly l, const T& r) { return l /= r;	 }
poly operator*(const poly& l, const poly& r) {
	if (!min(sz(l),sz(r))) return {};
	poly x(sz(l)+sz(r)-1); 
	F0R(i,sz(l)) F0R(j,sz(r)) x[i+j] += l[i]*r[j];
	return x;
}
poly& operator*=(poly& l, const poly& r) { return l = l*r; }

pair<poly,poly> quoRem(poly a, poly b) { 
	assert(sz(b)); auto B = b.bk; assert(B != 0);
	B = 1/B; trav(t,b) t *= B;
	remz(a); poly q(max(sz(a)-sz(b)+1,0));
	while (sz(a) >= sz(b)) {
		q[sz(a)-sz(b)] = a.bk;
		F0R(i,sz(b)) a[i+sz(a)-sz(b)] -= a.bk*b[i];
		remz(a);
	}
	trav(t,q) t *= B; 
	return {q,a};
}
poly interpolate(vector<pair<T,T>> v) {
	poly ret, prod = {1}; trav(t,v) prod *= poly({-t.f,1});
	F0R(i,sz(v)) {
		T fac = 1; F0R(j,sz(v)) if (i != j) fac *= v[i].f-v[j].f;
		ret += v[i].s/fac*quoRem(prod,{-v[i].f,1}).f;
	}
	return ret;
}
bool small(const poly& a, const poly& b) { // multiply directly
	return (ll)sz(a)*sz(b) <= 5000; } 
vmi smart(const vmi& a, const vmi& b) { return mul(a,b); }
poly conv(const poly& a, const poly& b) {
	return small(a,b) ? a*b : smart(a,b); } 
	
poly inv(poly A, int n) { // Q-(1/Q-A)/(-Q^{-2})
	poly B = {1/A[0]};
	while (sz(B) < n) {
		int x = 2*sz(B);
		B = RSZ(2*B-conv(RSZ(A,x),conv(B,B)),x);
	}
	return RSZ(B,n);
}
poly sqrt(const poly& A, int n) {  // Q-(Q^2-A)/(2Q)
	assert(A[0] == 1); poly B = {1};
	while (sz(B) < n) {
		int x = 2*sz(B);
		B = T(1)/T(2)*RSZ(B+mul(RSZ(A,x),inv(B,x)),x);
	}
	return RSZ(B,n);
}
pair<poly,poly> divi(const poly& f, const poly& g) { 
	if (sz(f) < sz(g)) return {{},f};
	auto q = mul(inv(rev(g),sz(f)-sz(g)+1),rev(f));
	q = rev(RSZ(q,sz(f)-sz(g)+1));
	auto r = RSZ(f-mul(q,g),sz(g)-1); return {q,r};
}
poly log(poly A, int n) { assert(A[0] == 1); // (ln A)' = A'/A
	return RSZ(integ(conv(dif(A),inv(A,n))),n); }
poly exp(poly A, int n) { // Q-(lnQ-A)/(1/Q)
	assert(A[0] == 0); poly B = {1};
	while (sz(B) < n) {
		int x = 2*sz(B);
		B = RSZ(B+conv(B,RSZ(A,x)-log(B,x)),x);
	}
	return RSZ(B,n);
}
poly power(const poly &A, int n, int N)
{
	poly bad = log(A,N);
	for(int i=0;i<bad.size();i++) bad[i]*=mi(n);
	bad=exp(bad,N);
	return bad;
}

mi ans[222222];
mi coeff[222222];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	init(122222);
	//step 1: find phi(x) = x/ln(x+1) = 1/((ln(x+1)/x))
	int N = n+4; 
	poly lnx1 = log({1,1},N);
	assert(lnx1[0]==0);
	poly phi;
	for(int i=1;i<N;i++) phi.pb(lnx1[i]);
	phi = inv(phi,N);
	/*
	cerr<<phi.size()<<'\n';
	for(int i=0;i<N;i++)
	{
		cout<<phi[i]<<' ';
	}
	cout<<'\n';
	*/
	//step 2: compute the difficult term
	poly tmp = phi;
	for(int i=0;i<N;i++) tmp[i]=-tmp[i];
	tmp[0]=tmp[0]+1; //1-phi(x)
	assert(tmp[0]==0);
	for(int i=0;i+1<tmp.size();i++)
	{
		tmp[i]=tmp[i+1];
	}
	tmp.pop_back();
	//1/((1 - phi(x))/x)
	mi itmp = inv(tmp[0]); 
	for(int i=0;i<tmp.size();i++) tmp[i]*=itmp;
	poly inv1phi = inv(tmp,N);
	for(int i=0;i<inv1phi.size();i++) inv1phi[i]*=itmp;
	poly expophi = power(phi,n+1,N);
	poly p1 = conv(expophi,inv1phi);
	poly p2 = conv(dif(phi),conv(inv1phi,p1));
	//F/(1-F)
	poly F;
	for(int i=0;i<N;i++)
	{
		F.pb(ifact[i]);
	}
	F[0]=F[0]-mi(1);
	assert(F[0]==0);
	for(int i=0;i+1<N;i++)
	{
		F[i]=F[i+1];
	}
	F.pop_back(); //(e^x-1)/x
	tmp = F;
	for(int i=0;i<N-1;i++) tmp[i]=-tmp[i];
	tmp[0]=tmp[0]+1; //1-F
	for(int i=0;i+1<tmp.size();i++)
	{
		tmp[i]=tmp[i+1];
	}
	//tmp = (1-F)/x
	itmp = inv(tmp[0]);
	for(int i=0;i<tmp.size();i++) tmp[i]*=itmp;
	poly invtmp = inv(tmp,N);
	for(int i=0;i<invtmp.size();i++) invtmp[i]*=itmp;
	//poly invi = ; //1/1-F
	poly G = conv(F,invtmp); //F/(1-F) * x^(-1)
	//extract coefficients
	for(int i=0;i<n;i++)
	{
		coeff[i] = G[i+1];
		mi res = 0;
		res+=mi(n-i+1)*p1[i+1];
		res+=p2[i+1];
		res/=mi(n+1);
		coeff[i]-=res;
	}
	const int BAKA = n-1;
	poly a(n,0);
	poly b(n,0);
	for(int i=0;i<n;i++)
	{
		a[BAKA-i]=mi(fact[i])*coeff[i];
	}
	for(int i=0;i<n;i++)
	{
		b[i]=mi(ifact[i])*(i&1?MOD-1:1);
	}
	poly c = conv(a,b);
	for(int i=0;i<n;i++)
	{
		mi res = c[BAKA-i];
		res*=mult(fact[n],ifact[i]);
		ans[i+1]=res;
	}
	/*
	//let's chill with easy sol first
	for(int i=0;i<n;i++)
	{
		mi res = 0;
		for(int j=i;j<n;j++)
		{
			int sgn = ((j-i)&1?MOD-1:1);
			sgn=mult(sgn,mult(fact[j],ifact[j-i]));
			res+=coeff[j]*sgn;
		}
		res*=mult(fact[n],ifact[i]);
		ans[i+1]=res;
	}
	*/
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i];
		if(i+1<=n) cout<<' ';
	}
	cout<<'\n';
}