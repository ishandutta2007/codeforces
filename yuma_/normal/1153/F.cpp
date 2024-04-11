#include "bits/stdc++.h"
#pragma GCC optimize("Ofast")

#pragma GCC target("avx,avx2")
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ll=long long ;
#define Whats(x) cout<<#x<<" is "<<(x)<<endl
const ll mod = 998244353;
const ll mo=mod;
struct Mod {
public:
	int num;
	Mod() : Mod(0) { ; }
	Mod(long long int n) : num((n % mod + mod) % mod) {
		static_assert(mod<INT_MAX / 2, "mod is too big, please make num 'long long int' from 'int'");
	}
	Mod(int n) : Mod(static_cast<long long int>(n)) { ; }
	operator int() { return num; }
};

Mod operator+(const Mod a, const Mod b) { return Mod((a.num + b.num) % mod); }
Mod operator+(const long long int a, const Mod b) { return Mod(a) + b; }
Mod operator+(const Mod a, const long long int  b) { return b + a; }
Mod operator++(Mod &a) { return a + Mod(1); }
Mod operator-(const Mod a, const Mod b) { return Mod((mod + a.num - b.num) % mod); }
Mod operator-(const long long int a, const Mod b) { return Mod(a) - b; }
Mod operator--(Mod &a) { return a - Mod(1); }
Mod operator*(const Mod a, const Mod b) { return Mod(((long long)a.num * b.num) % mod); }
Mod operator*(const long long int a, const Mod b) { return Mod(a)*b; }
Mod operator*(const Mod a, const long long int b) { return Mod(b)*a; }
Mod operator*(const Mod a, const int b) { return Mod(b)*a; }
Mod operator+=(Mod &a, const Mod b) { return a = a + b; }
Mod operator+=(long long int &a, const Mod b) { return a = a + b; }
Mod operator-=(Mod &a, const Mod b) { return a = a - b; }
Mod operator-=(long long int &a, const Mod b) { return a = a - b; }
Mod operator*=(Mod &a, const Mod b) { return a = a * b; }
Mod operator*=(long long int &a, const Mod b) { return a = a * b; }
Mod operator*=(Mod& a, const long long int &b) { return a = a * b; }
Mod operator^(const Mod a, const int n) {
	if (n == 0) return Mod(1);
	Mod res = (a * a) ^ (n / 2);
	if (n % 2) res = res * a;
	return res;
}
Mod mod_pow(const Mod a, const long long  int n) {
	if (n == 0) return Mod(1);
	Mod res = mod_pow((a * a), (n / 2));
	if (n % 2) res = res * a;
	return res;
}

//mod extend euclid 
Mod inv(const Mod a) { return a ^ (mod - 2); }
Mod operator/(const Mod a, const Mod b) {
	assert(b.num != 0);
	return a * inv(b);
}
Mod operator/(const long long int a, const Mod b) {
	return Mod(a) / b;
}
Mod operator/=(Mod &a, const Mod b) {
	return a = a / b;
}

#define MAX_MOD_N 10240

Mod fact[MAX_MOD_N], factinv[MAX_MOD_N];
void init(const int amax = MAX_MOD_N) {
	fact[0] = Mod(1); factinv[0] = 1;
	for (int i = 0; i < amax - 1; ++i) {
		fact[i + 1] = fact[i] * Mod(i + 1);
		factinv[i + 1] = factinv[i] / Mod(i + 1);
	}
}
Mod comb(const int a, const int b) {
	return fact[a] * factinv[b] * factinv[a - b];
}
using Vec=vector<ll>;
Vec operator*(const Vec&l, const Vec&r) {
	Vec v(l.size()+r.size()-1);
	for (int i = 0; i < l.size(); ++i) {
		for (int j = 0; j < r.size(); ++j) {
			v[i+j]+=l[i]*r[j];
		}
	}
	for(auto&x:v)x%=mod;
	return v;
}


ll modpow(ll a, ll n = mo - 2) {
	ll r = 1;
	while (n) r = r*((n % 2) ? a : 1) % mo, a = a*a%mo, n >>= 1;
	return r;
}
vector<ll> fft(vector<ll> v, bool rev = false) {
	int n = v.size(), i, j, m;

	for (i = 0, j = 1; j<n - 1; j++) {
		for (int k = n >> 1; k>(i ^= k); k >>= 1);
		if (i>j) swap(v[i], v[j]);
	}
	for (int m = 2; m <= n; m *= 2) {
		ll wn = modpow(5, (mo - 1) / m);
		if (rev) wn = modpow(wn);
		for (i = 0; i<n; i += m) {
			ll w = 1;
			for (int j1 = i, j2 = i + m / 2; j2<i + m; j1++, j2++) {
				ll t1 = v[j1], t2 = w*v[j2] % mo;
				v[j1] = t1 + t2;
				v[j2] = t1 + mo - t2;
				while (v[j1] >= mo) v[j1] -= mo;
				while (v[j2] >= mo) v[j2] -= mo;
				w = w*wn%mo;
			}
		}
	}
	if (rev) {
		ll rv = modpow(n);
		for(int i=0;i<n;++i)v[i] = v[i] * rv%mo;
	}
	return v;
}

vector<ll> MultPoly(vector<ll> P, vector<ll> Q, bool resize = false) {
	if (resize) {
		int maxind = 0, pi = 0, qi = 0, i;
		int s = 2;
		for(int i=0;i<P.size();++i)if(P[i])pi=i;
		for(int i=0;i<Q.size();++i)if(Q[i])qi=i;
		maxind = pi + qi + 1;
		while (s * 2<maxind) s *= 2;
		P.resize(s * 2); Q.resize(s * 2);
	}
	P = fft(P), Q = fft(Q);
	for (int i = 0; i<P.size(); i++) P[i] = P[i] * Q[i] % mo;
	return fft(P, true);
}
int main() {
	int N,K,L;cin>>N>>K>>L;
	init();
	vector<Vec>anss(N+1);
	Vec ok = Vec{0,1 };
	Vec ng = Vec{ 1,-1 };
	Vec mu = Vec{0, 2,-2 };

	vector<Vec>oks(N+1),ngs(N+1),ms(N+1);
	oks[0] = Vec{ 1 };
	ngs[0] = Vec{ 1 };
	ms[0] = Vec{ 1 };
	for (int i = 0; i < N; ++i) {
		oks[i+1]=oks[i]*ok;
		ngs[i+1]=ngs[i]*ng;
		ms[i+1]=ms[i]*mu;
	}
	//if(N>1500)return 0;
	ll ans=0;
	vector<ll>sums(3000);


	for (int ok_cnt = K; ok_cnt <= N; ++ok_cnt) {
		int ng_cnt = N - ok_cnt;
		vector<ll>vs(N);
		for (int t = ok_cnt; t <= N; ++t) {
			int flag=(t-ok_cnt)%2;
			Mod naum=flag?-1:1;
			sums[t]+=ll(naum*comb(ng_cnt,t-ok_cnt)*comb(N,ok_cnt))%mod;
		}

	}
	
	
	//if(N>1500&&abs(K-1000)<100)return 0;
	{
		Vec ous(7000);
		for (int i = 0; i < 3000; ++i) {
			sums[i]%=mod;
			if(!sums[i])continue;
			Vec s{ sums[i] };
			Vec vv =s*ms[i];
			for (int j = 0; j < vv.size(); ++j) {
				ous[j]+=vv[j];
			}
		}
		for(auto&ou:ous)ou%=mod;
		sums=ous;
	}
	vector<ll>sekis(sums.size() + 1);
	for (int i = 0; i < sums.size(); ++i) {
		sekis[i + 1] = (Mod(sums[i]) / Mod(i + 1)).num;
	}
	for (int i = 1; i < sekis.size(); ++i) {
		ans += sekis[i];
	}
	ans=ans%mod*L%mod;
	cout<<ans<<endl;
	return 0;
}