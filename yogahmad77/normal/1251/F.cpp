#include "bits/stdc++.h"
using namespace std;
#define f first
#define s second
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a);
#define ALL(x) x.begin(),x.end()
 
template <typename T>
void cetak(T t){cout << t << ')' << endl;}
template <typename T, typename... V>
void cetak(T t, V... v) {cout << t; if (sizeof...(v)) cerr << ", "; cetak(v...);}
 
#define debug(x...) cout<< '(' << #x << ") = ("; cetak(x) 
#define sz(x) (int)(x.size())
#define lt(x) (int)(x.length())

const int MOD = 998244353;
const int mx = 3e5 + 10;

struct NTT {
public:
  NTT(const int _mod) : mod(_mod) {
    proot = find_primitive_root();
    int totient = mod-1;
    max_len = 1;
    while ((totient & max_len) == 0)
      max_len <<= 1;
  }
 
  void fft(vector<int> & a, bool invert) {
    int n = (int) a.size();
    if (n & (n-1)) {
      int pw = 1;
      while (pw < n) pw <<= 1;
      n = pw;
      a.resize(n, 0);
    }
    assert(n <= max_len);
 
    for (int i=1, j=0; i<n; ++i) {
      int bit = n >> 1;
      for (; j>=bit; bit>>=1)
        j -= bit;
      j += bit;
      if (i < j)
        swap (a[i], a[j]);
    }
 
    int root = powmod(proot, (mod-1) / n);
    if (invert)
      root = inverse(root);
 
    for (int len = 2; len <= n; len <<= 1) {
      int wlen = root;
      for (int i = len; i < n; i <<= 1)
        wlen = int (wlen * 1ll * wlen % mod);
      for (int i = 0; i < n; i += len) {
        int w = 1;
        for (int j = 0; j < len/2; ++j) {
          int u = a[i+j], v = int (a[i+j+len/2] * 1ll * w % mod);
          a[i+j] = u+v < mod ? u+v : u+v-mod;
          a[i+j+len/2] = u-v >= 0 ? u-v : u-v+mod;
          w = int (w * 1ll * wlen % mod);
        }
      }
    }
    if (invert) {
      int nrev = inverse(n);
      for (int i = 0; i < n; ++i)
        a[i] = int (a[i] * 1ll * nrev % mod);
    }
  }
 
  vector<int> multiply(vector<int> a, vector<int> b) {
    int len = a.size() + b.size() - 1;
    int pw = 1;
    while (pw < len) pw <<= 1;
    len = pw;
    a.resize(len, 0);
    b.resize(len, 0);
    fft(a, false);
    fft(b, false);
    for (int i = 0; i < len; ++i)
      a[i] = 1LL * a[i] * b[i] % mod;
    fft(a, true);
    while (len > 0 && a[len-1] == 0)
      --len;
    a.resize(len);
    return a;
  }
  
  long long powmod(long long b, long long p) {
    long long r = 1;
    for (; p; p >>= 1, b = b * b % mod)
      if (p & 1)
        r = r * b % mod;
    return r;
  }
 
  long long inverse(int x) {
    return powmod(x, mod-2);
  }
 
private:
  const int mod;
  int proot;
  int max_len = 1;
 
  int find_primitive_root() {
    int totient = mod - 1;
    vector<int> checks;
    int tmp = totient;
    for (int p = 2; p * p <= tmp; ++p) {
      if (tmp % p) continue;
      checks.push_back(totient/p);
      while ((tmp % p) == 0) tmp /= p;
    }
    if (tmp > 1)
      checks.push_back(totient/tmp);
    for (int r = 2; ; ++r) {
      bool ok = 1;
      for (int f : checks) {
        if (powmod(r, f) == 1) {
          ok = 0;
          break;
        }
      }
      if (ok)
        return r;
    }
    assert(false);
  }
};
 
const int mod = 998244353;
 
NTT ntt(mod);
 



long long POW(long long a, int b){
    long long ret = 1;
    while(b > 0){
        if(b & 1) ret = ret * a % MOD;
        b >>= 1;
        a = a * a % MOD;
    }
    return ret;
}

long long fak[mx], inv[mx];

long long C(int n, int k){
    if(k > n || k < 0) return 0;
    return fak[n] * inv[k] % MOD * inv[n - k] % MOD;
}

long long jaw[1200000 + 10];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(k);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < k; i++) cin >> b[i];
    fak[0] = 1;
    for(int i = 1; i <= n; i++) fak[i] = fak[i - 1] * i % MOD;
    inv[n] = POW(fak[n], MOD - 2);
    for(int i = n - 1; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % MOD;
    map<int, int> cnt;
    for(int i = 0; i < n; i++) cnt[a[i]] += 1;
    for(int i = 0; i < k; i++){
        int satu = 0, dua = 0;
        for(auto x : cnt){
            if(x.f >= b[i]) break;
            if(x.s == 1) satu += 1;
            else dua += 1;
        }
        vector<int> du(dua * 2 + 1), sa(satu + 1);
        for(int i = 0; i <= dua * 2; i++){
            du[i] = C(dua * 2, i);
        }
        for(int i = 0; i <= satu; i++){
            sa[i] = 1LL * C(satu, i) * POW(2, i) % MOD;
        }
        auto ret = ntt.multiply(sa, du);
        for(int j = 0; j < sz(ret); j++){
            if(j * 2 + b[i] * 2 + 2 > 1200000) continue;
            jaw[j * 2 + b[i] * 2 + 2] += ret[j];
            jaw[j * 2 + b[i] * 2 + 2] %= MOD;
        }
    }
    int q;
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        cout << jaw[x] << '\n';
    }
}