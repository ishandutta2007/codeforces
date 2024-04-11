#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <tuple>
#include <cmath>
#include <numeric>
#include <functional>
#include <cassert>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;

template<typename T>
void print_vector(vector<T> v, char delimiter=' '){
    if(v.empty()) {
        cout << endl;
        return;
    }
    for(int i = 0; i+1 < v.size(); i++) cout << v[i] << delimiter;
    cout << v.back() << endl;
}

vector<int> as_base_k(int a, int k){
    vector<int> ans;
    while(a){
        ans.push_back(a%k);
        a /= k;
    }
    return ans;
}

int as_base_10(vector<int> v, int k){
    int len = v.size();
    int cur = 1;
    int ans = 0;
    for(int i = 0; i < len; i++){
        ans += cur*v[i];
        cur *= k;
    }
    return ans;
}

int k_base_xor_inv(int a, int b, int k){ // a^c = b (base k)c
    auto av = as_base_k(a, k);
    auto bv = as_base_k(b, k);
    while(av.size() < bv.size()) av.push_back(0);
    while(bv.size() < av.size()) bv.push_back(0);
    int len = av.size();
    vector<int> cv(len);
    for(int i = 0; i < len; i++){
        cv[i] = (bv[i]-av[i]+k)%k;
    }
    return as_base_10(cv, k);
}

class Judge{
    public:
    int n, k;
    int x;
    int init;
    Judge(int n, int k): n(n), k(k) {
        x = rand()%n;
        init = x;
    };
    int ask(int q){
        if(x == q) {
            cout << "OK" << endl;
            return 1;
        }
        x = k_base_xor_inv(x, q, k);
        return 0;
    }
};

// #define DEBUG

void solve(){
    int n, k; cin >> n >> k;
    #ifdef DEBUG
    auto jd = Judge(n, k);
    #endif
    auto ask = [&](int q){
        #ifdef DEBUG
        return jd.ask(q);
        #else
        cout << q << endl;
        int r; cin >> r;
        return r;
        #endif
    };
    auto n_base_k = as_base_k(n, k);
    int len = n_base_k.size();
    vector<int> x(len);
    int a = 1;
    for(int i = 0; i < n; i++){
        auto iv = as_base_k(i, k);
        while(iv.size() < len) iv.push_back(0);
        vector<int> query(len);
        for(int j = 0; j < len; j++){
            query[j] = (x[j]+iv[j]*a+k)%k;
        }
        int r = ask(as_base_10(query, k));
        if(r == 1) return;
        for(int j = 0; j < len; j++){
            x[j] = (query[j]-x[j]+k)%k;
        }
        a *= -1;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}