#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int mod3 = 998244353;

long long binpow(long long a, long long p) {
    return p?binpow(a*a%mod3, p>>1)*(p&1?a:1)%mod3:1;
}

long long bininv(long long a){
    return binpow(a, mod3-2);
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

        int primitive_root = 3;
        int step = (mod3 - 1) / n;

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
                    int a = arr[i1], b = arr[i2] * 1ll * w[wind] % mod3;
                    arr[i1] = a + b;  if (arr[i1] >= mod3)  arr[i1] -= mod3;
                    arr[i2] = a - b;  if (arr[i2] < 0)      arr[i2] += mod3;
                }
            }
        }
    }

    void ifft(vector<int>& arr) {
        fft(arr);   reverse(arr.begin() + 1, arr.end());
        int inv = bininv(n);
        for (int i = 0; i < n; i++) arr[i] = arr[i] * 1ll * inv % mod3;
    }

    void multiply(vector<int>& a, vector<int>&  b) {
        fft(a);     fft(b);
        for (int i = 0; i < n; i++) { a[i] = a[i] * 1ll * b[i] % mod3; }
        ifft(a);
    }
} fftHelper[20];


void solve(int test_ind){
    for (int i = 0; i < 20; i++) {
        fftHelper[i].init((1 << i));
    }

    int n;
    cin >> n;
    int k, f;
    cin >> k >> f;

    vector<vector<int> > v(n + 1);

    v[1] = vector<int>((1<<19), 0);
    for (int i=0;i<=k;++i) v[1][i] = 1;

    for (int i=2;i<=n;++i) {
        vector<int> b = v[i-1], a = v[i-1];
        fftHelper[19].multiply(a, b);
        v[i].resize(v[i-1].size());
        for (int j=0;j<=k;++j) {
            v[i][j] = (a[j] * 1ll * (k - j)) % mod3;
        }
        vector<int> pv(a.size(),0);
        for (int j=a.size()-2;j>=0;--j) pv[j] = (pv[j+1] + a[j]) % mod3;
        for (int j=0;j<=k;++j) {
            v[i][j] = (v[i][j] + pv[j]) % mod3;
        }
    }

    // for (int i=0;i<=k;++i) cout << v[n][i] << " "; cout << endl;

    // v[n], v[n]
    int ans = 0;
    for (int i=0;i<=k;++i){
        int j = f - i;
        if (j >= 0 && j <= k) {
            ans = (ans + v[n][i] * 1ll * v[n][j]) % mod3;
        }
    }
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