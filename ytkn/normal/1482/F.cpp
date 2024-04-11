#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <functional>
#include <cassert>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;

#define MOD 998244353
#define root 3
    
unsigned int add(const unsigned int x, const unsigned int y){
    return (x + y < MOD) ? x + y : x + y - MOD;
}
    
unsigned int sub(const unsigned int x, const unsigned int y){
    return (x >= y) ? (x - y) : (MOD - y + x);
}
    
unsigned int mul(const unsigned int x, const unsigned int y){
    return (unsigned long long)x * y % MOD;
}
    
unsigned int mod_pow(unsigned int x, unsigned int n){
    unsigned int res = 1;
    while(n > 0){
        if(n & 1){ res = mul(res, x); }
        x = mul(x, x);
        n >>= 1;
    }
    return res;
}
    
unsigned int inverse(const unsigned int x){
    return mod_pow(x, MOD - 2);
}
    
void ntt(vector<int>& a, const bool rev = false){
    unsigned int i, j, k, l, p, q, r, s;
    const unsigned int size = a.size();
    if(size == 1) return;
    vector<int> b(size);
    r = rev ? (MOD - 1 - (MOD - 1) / size) : (MOD - 1) / size;
    s = mod_pow(root, r);
    vector<unsigned int> kp(size / 2 + 1, 1);
    for(i = 0; i < size / 2; ++i) kp[i + 1] = mul(kp[i], s);
    for(i = 1, l = size / 2; i < size; i <<= 1, l >>= 1){
        for(j = 0, r = 0; j < l; ++j, r += i){
            for(k = 0, s = kp[i * j]; k < i; ++k){
                p = a[k + r], q = a[k + r + size / 2];
                b[k + 2 * r] = add(p, q);
                b[k + 2 * r + i] = mul(sub(p, q), s);
            }
        }
        swap(a, b);
    }
    if(rev){
        s = inverse(size);
        for(i = 0; i < size; i++){ a[i] = mul(a[i], s); }
    }
}
    
vector<int> convolute(const vector<int>& a, const vector<int>& b){
    const int size = (int)a.size() + (int)b.size() - 1;
    int t = 1;
    while(t < size){ t <<= 1; }
    vector<int> A(t, 0), B(t, 0);
    for(int i = 0; i < (int)a.size(); i++){ A[i] = a[i]; }
    for(int i = 0; i < (int)b.size(); i++){ B[i] = b[i]; }
    ntt(A), ntt(B);
    for (int i = 0; i < t; i++){ A[i] = mul(A[i], B[i]); }
    ntt(A, true);
    A.resize(size);
    return A;
}

vector<int> calc(vector<int> v){
    if(v.size() == 1){
        return vector<int>(v[0]+1, 1);
    }
    int sum = accumulate(v.begin(), v.end(), 0);
    int lsum = 0;
    vector<int> vl, vr;
    for(int x : v){
        if(2*lsum < sum) {
            vl.push_back(x);
            lsum += x;
        }else{
            vr.push_back(x);
        }
    }
    if(vr.empty()){
        vr.push_back(vl.back());
        vl.pop_back();
    }
    return convolute(calc(vl), calc(vr));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    map<int, int> cnt;
    for(int i = 0; i < n; i++){
        int p; cin >> p;
        if(cnt.count(p)) cnt[p]++;
        else cnt[p] = 1;
    }
    vector<int> v;
    for(auto [a, b]: cnt) v.push_back(b);
    auto u = calc(v);
    cout << u[n/2] << endl;
}