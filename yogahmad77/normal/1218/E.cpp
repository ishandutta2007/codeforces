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

const int MOD = 1e9 + 7;
const int mx = 1e5 + 10;


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
 
vector<int> kali(vector<vector<int>> &ve, int l, int r){
    if(l == r) return ve[l];
    int mid = (l + r) >> 1;
    auto kiri = kali(ve, l, mid);
    auto kanan = kali(ve, mid + 1, r);
    return ntt.multiply(kiri, kanan);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int q;
    cin >> q;
    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int q, x, d;
            cin >> q >> x >> d;
            x -= 1;
            auto b = a;
            b[x] = d;
            for(int i = 0; i < n; i++) b[i] = q - b[i];
            for(int &i : b){
                i %= mod;
                if(i < 0) i += mod;
            }
            vector<vector<int>> ve(n, vector<int> (2));
            for(int i = 0; i < n; i++){
                ve[i][0] = 1;
                ve[i][1] = b[i];
            }
            auto res = kali(ve, 0, n - 1);
            if(k >= sz(res)) cout << 0 << '\n';
            else cout << res[k] << '\n';
        }
        else{
            int q, l, r, d;
            cin >> q >> l >> r >> d;
            l -= 1, r -= 1;
            auto b = a;
            for(int i = l; i <= r; i++) b[i] = a[i] + d;
            for(int &i : b) i = q - i;
            for(int &i : b){
                i %= mod;
                if(i < 0) i += mod;
            }
            vector<vector<int>> ve(n, vector<int> (2));
            for(int i = 0; i < n; i++){
                ve[i][0] = 1;
                ve[i][1] = b[i];
            }
            auto res = kali(ve, 0, n - 1);
            if(k >= sz(res)) cout << 0 << '\n';
            else cout << res[k] << '\n';
        }
    }
}