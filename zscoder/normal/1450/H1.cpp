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
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vector<int> fact;
vector<int> ifact;
vector<int> inv;
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
	fact.clear(); ifact.clear(); inv.clear(); pow2.clear();
	fact.resize(_n+1);
	ifact.resize(_n+1);
	inv.resize(_n+1);
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
	for(int i=1;i<=_n;i++)
	{
		inv[i] = mult(fact[i-1],ifact[i]);
	}
}

bool match(string s, string t)
{
	for(int i=0;i<s.length();i++)
	{
		if(s[i]!=t[i]&&s[i]!='?')
		{
			return false;
		}
	}
	return true;
}

bool valid(string s)
{
	int cnt=0;
	for(char c:s) cnt+=(c=='b');
	return (cnt%2==0);
}

int getcnt(string s)
{
	/*
	stack<char> S;
	for(char c:s)
	{
		if(!S.empty()&&S.top()==c)
		{
			S.pop();
		}
		else S.push(c);
	}
	return S.size();
	*/
	int ans=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='b')
		{
			if(i&1) ans++;
			else ans--;
		}
	}
	return abs(ans);
}

typedef long long ll;
typedef pair<int, int> Pii;

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
		assert((n ^ (n&-n)) == 0); //n = 2^k

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

		for (auto& x : a) if (x < 0) x += mod;
	}
	void ntt(vector<ll>& input) {
		_ntt(input, 1);
	}
	void intt(vector<ll>& input) {
		_ntt(input, -1);
		const int n_inv = mod_inv(sz(input), mod);
		for (auto& x : input) x = x * n_inv % mod;
	}

	// 
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

typedef NTT<998244353, 3> NTT_1;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	init(450000);
	int n,m; cin>>n>>m;
	string s; cin>>s;
	/*
	int cc=0; int posi=0;
	for(int i=0;i<(1<<n);i++)
	{
		string nw;
		for(int j=0;j<n;j++)
		{
			if(i&(1<<j)) nw+="b";
			else nw+="w";
		}
		if(match(s,nw))
		{
			if(valid(nw))
			{
				posi++;
				cc+=getcnt(nw);
			}
		}
	}
	cout<<cc/4<<' '<<posi<<'\n';
	
	*/
	int cnt[2]={0,0};
	int diff=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='?')
		{
			cnt[i&1]++;
		}
		if(s[i]=='b')
		{
			if(i&1) diff++;
			else diff--;
		}
	}
	
	int ans=0;
	int valid_ways=0;
	vector<ll> a(n+1);
	vector<ll> b(n+1);
	
	for(int i=0;i<=n;i++)
	{
		a[n-i]=choose(cnt[0],i);
		b[i]=choose(cnt[1],i);
	}
	NTT_1 ntt;
	vector<ll> c = ntt.convolution(a,b);
	/*
	for(int i=0;i<c.size();i++)
	{
		cerr<<c[i]<<' ';
	}
	cerr<<'\n';
	*/
	for(int i=-n;i<=n;i++)
	{
		//b-a = i de case
		int res = 0;
		if(n+i>=0&&n+i<c.size()) res=c[n+i];
		int d = i+diff;
		if(d%2==0)
		{
			//cerr<<d<<": "<<res<<" ways\n";
			radd(valid_ways,res);
			radd(ans,mult(res,abs(d)));
		}
	}
	if(valid_ways==0)
	{
		cout<<0<<'\n'; return 0;
	}
	//cerr<<ans<<'\n';
	rmult(ans,inv[2]);
	valid_ways = inverse(valid_ways);
	ans=mult(ans,valid_ways);
	cout<<ans<<'\n';
	//
}