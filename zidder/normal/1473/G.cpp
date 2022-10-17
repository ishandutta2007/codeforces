#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <complex>

using namespace std;

const int MOD = 998244353;

long long binpow(long long a, long long p){
	return p?binpow(a*a%MOD, p>>1)*(p&1?a:1)%MOD:1;
}

long long bininv(long long a){
	return binpow(a, MOD-2);
}

struct FFT {
    int n;
    vector<int> img;
    
    vector<int> w;
 
    void init(int _n) {
        n = _n;
 
        img.resize(n);
        w.resize(n);
        for (int i = 0, j = 0; i < n; i++) {
            if (i == 0) {   img[i] = 0; continue; }
            int bit = (n >> 1);
            while (j & bit) { j ^= bit; bit >>= 1;  }
            j ^= bit;   img[i] = j;
        }
 
        long double pi = acosl(-1.0);
        int primitive_root = 3;
        int step = (MOD - 1) / n;
        for (int i = 0, power=0; i < n; i++, power += step) {
            w[i] = binpow(primitive_root, power);
        }
    }
 
    void fft(vector<int>& arr) {
        for (int i = 0; i < n; i++) { if (i < img[i]) swap(arr[i], arr[img[i]]); }
        for (int len = 2; len <= n; len <<= 1) {
            for (int i = 0; i < n; i += len) {
                int i1 = i, i2 = i + len / 2;
                int wind = 0, wstep = n / len;
                for (; i2 < i + len; i1++, i2++, wind += wstep) {
                    int a = arr[i1], b = arr[i2] * 1ll * w[wind] % MOD;
                    arr[i1] = a + b;  if (arr[i1] >= MOD)  arr[i1] -= MOD;
                    arr[i2] = a - b;  if (arr[i2] < 0)      arr[i2] += MOD;
                }
            }
        }
    }
 
    void ifft(vector<int>& arr) {
        fft(arr);   reverse(arr.begin() + 1, arr.end());
        int inv = bininv(n);
        for (int i = 0; i < n; i++) arr[i] = arr[i] * 1ll * inv % MOD;
    }
 
    void multiply(vector<int>& a, vector<int>&  b) {
        fft(a);     fft(b);
        for (int i = 0; i < n; i++) { a[i] = a[i] * 1ll * b[i] % MOD; }
        ifft(a);
    }
};
 
vector<int> mul(vector<int> &a, vector<int> &b, FFT& fft){
	while (a.size() < fft.n) a.push_back(0);
	while (b.size() < fft.n) b.push_back(0);
	fft.multiply(a, b);
	return a;
}

void solve(int test_ind){
	FFT fft;
	fft.init((1<<14));
	vector<int> fact(300000, 1);
	for (int i=1;i<fact.size();++i) fact[i] = fact[i-1] * 1ll * i % MOD;
	vector<int> ifact(300000);
	for (int i=0;i<fact.size();++i) ifact[i] = bininv(fact[i]);
	auto C = [&](int n, int k) -> long long {
		if (k > n) return 0;
		return (fact[n] *  1ll * ifact[k] % MOD) * ifact[n-k] % MOD;
	};
	int n;
	cin >> n;
	vector<int> a = {1};
	for (int i=0;i<n;++i){
		int ai, bi;
		cin >> ai >> bi;
		// polynom * (1+x)^(ai+bi)
		vector<int> p;
		p.reserve((ai + a.size() - max(bi - (int)a.size() + 1, 0)));
		for (int k=max(bi - (int)a.size() + 1, 0);k<ai + a.size();++k){
			p.push_back(C(ai+bi, k));
		}
		int l = a.size();
		int pl = a.size();
		int d = bi - max(bi - (int)a.size() + 1, 0);
		// for (int i: a) cout << i << " "; cout << endl;
		// for (int i: p) cout << i << " "; cout << endl;
		vector<int> t = mul(p, a, fft);
		a.clear();
		// for (int i: t) cout << i << " "; cout << endl;
		for (int i=d;a.size()<l+ai-bi;++i) a.push_back(t[i]);
		// for (int i: a) cout << i << " "; cout << endl;
	}
	int ans = 0;
	for (int i: a) ans = (ans + i) % MOD;
	cout << ans << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}