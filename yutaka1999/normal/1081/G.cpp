#include <bits/stdc++.h>
#define SIZE 100005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)

template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }

template<int mod, int primitive_root>
class NTT {
public:
	int get_mod() const { return mod; }
	void _ntt(vector<ll>& a, int sign) {
		const int n = sz(a);
		//assert((n ^ (n&-n)) == 0); //n = 2^k
		const int g = 3; //g is primitive root of mod
		int h = (int)mod_pow(g, (mod - 1) / n, mod); // h^n = 1
		if (sign == -1) h = (int)mod_inv(h, mod); //h = h^-1 % mod
		//bit reverse
		int i = 0;
		for (int j = 1; j < n - 1; ++j) {
			for (int k = n >> 1; k >(i ^= k); k >>= 1);
			if (j < i) swap(a[i], a[j]);
		}
		for (int m = 1; m < n; m *= 2) {
			const int m2 = 2 * m;
			const ll base = mod_pow(h, n / m2, mod);
			ll w = 1;
			FOR(x, m) {
				for (int s = x; s < n; s += m2) {
					ll u = a[s];
					ll d = a[s + m] * w % mod;
					a[s] = u + d;
					if (a[s] >= mod) a[s] -= mod;
					a[s + m] = u - d;
					if (a[s + m] < 0) a[s + m] += mod;
				}
				w = w * base % mod;
			}
		}
		for (int i=0;i<a.size();i++) if (a[i] < 0) a[i] += mod;
	}
	void ntt(vector<ll>& input) {
		_ntt(input, 1);
	}
	void intt(vector<ll>& input) {
		_ntt(input, -1);
		const int n_inv = mod_inv(sz(input), mod);
		for (int i=0;i<input.size();i++) input[i] = input[i] * n_inv % mod;
	}
	vector<ll> convolution(const vector<ll>& a, const vector<ll>& b){
		int ntt_size = 1;
		while (ntt_size < sz(a) + sz(b)) ntt_size *= 2;
		vector<ll> _a = a, _b = b;
		_a.resize(ntt_size); _b.resize(ntt_size);
		ntt(_a);
		ntt(_b);
		FOR(i, ntt_size){
			(_a[i] *= _b[i]) %= mod;
		}
		intt(_a);
		return _a;
	}
};
typedef NTT<167772161, 3> NTT_1;
typedef NTT<469762049, 3> NTT_2;
typedef NTT<1224736769, 3> NTT_3;

ll MOD;
ll inv[SIZE],fac[SIZE],finv[SIZE];
void make()
{
	fac[0]=fac[1]=1;
	finv[0]=finv[1]=1;
	inv[1]=1;
	for(int i=2;i<SIZE;i++)
	{
		inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
		fac[i]=fac[i-1]*(ll) i%MOD;
		finv[i]=finv[i-1]*inv[i]%MOD;
	}
}
ll C(int a,int b)
{
	if(a<b) return 0;
	return fac[a]*(finv[b]*finv[a-b]%MOD)%MOD;
}
vector<ll> fast_int32mod_convolution(vector<ll> a, vector<ll> b){
	NTT_1 ntt1; NTT_2 ntt2; NTT_3 ntt3;
	//assert(ntt1.get_mod() < ntt2.get_mod() && ntt2.get_mod() < ntt3.get_mod());
	vector <ll> x = ntt1.convolution(a, b);
	vector <ll> y = ntt2.convolution(a, b);
	vector <ll> z = ntt3.convolution(a, b);
	const ll m1 = ntt1.get_mod(), m2 = ntt2.get_mod(), m3 = ntt3.get_mod();
	const ll m1_inv_m2 = mod_inv<ll>(m1, m2);
	const ll m12_inv_m3 = mod_inv<ll>(m1 * m2, m3);
	const ll m12_mod = m1 * m2 % MOD;
	vector<ll> ret(sz(x));
	FOR(i, sz(x)){
		ll v1 = (y[i] - x[i]) *  m1_inv_m2 % m2;
		if (v1 < 0) v1 += m2;
		ll v2 = (z[i] - (x[i] + m1 * v1) % m3) * m12_inv_m3 % m3;
		if (v2 < 0) v2 += m3;
		ll constants3 = (x[i] + m1 * v1 + m12_mod * v2) % MOD;
		if (constants3 < 0) constants3 += MOD;
		ret[i] = constants3;
	}
	return ret;
}
int cnt[SIZE];
ll rt[SIZE];
int n;

void dfs(int l,int r,int k)
{
	if(l>r) return;
	if(k==1||l==r) cnt[r-l+1]++;
	else
	{
		int m=(l+r)/2;
		dfs(l,m,k-1);
		dfs(m+1,r,k-1);
	}
}
int main()
{
	int k;
	scanf("%d %d %lld",&n,&k,&MOD);
	make();
	dfs(0,n-1,k);
	vector <int> vl;
	for(int i=0;i<=n;i++) if(cnt[i]!=0) vl.push_back(i);
	for(int i=0;i<vl.size();i++)
	{
		for(int j=0;j<vl.size();j++)
		{
			ll w;
			if(i==j) w=(ll) cnt[vl[i]]*(ll) (cnt[vl[i]]-1);
			else w=(ll) cnt[vl[i]]*(ll) cnt[vl[j]];
			w%=MOD;
			int a=vl[i],b=vl[j];
			if(a>b) swap(a,b);
			if(w>0)
			{
				for(int k=2;k<=a+1;k++) rt[k-1]+=w*(ll) (k-1)%MOD;
				for(int k=a+2;k<=b+1;k++) rt[k-1]+=w*(ll) a%MOD;
				for(int k=b+2;k<=a+b;k++) rt[k-1]+=w*(ll) (a+b+1-k)%MOD;
			}
		}
	}
	for(int i=0;i<=n;i++) rt[i]%=MOD;
	vector <ll> A,B;
	A.resize(n,0);
	B.resize(n,0);
	for(int i=1;i<n;i++) A[i]=fac[n-i-1]*(ll) rt[i]%MOD;
	for(int i=0;i<n;i++) B[i]=finv[i];
	vector <ll> vec=fast_int32mod_convolution(A,B);
	ll ret=0;
	for(int i=0;i<n;i++)
	{
		ret+=fac[i]*vec[i]%MOD;
		if(ret>=MOD) ret-=MOD;
	}
	//printf("%lld\n",ret);
	ll all=fac[n]*C(n,2)%MOD;
	all-=ret;
	if(all<0) all+=MOD;
	if(all%2==1) all+=MOD;
	all/=2;
	//printf("* %lld\n",all);
	printf("%lld\n",all*finv[n]%MOD);
	return 0;
}