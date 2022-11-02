#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <deque>
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
vector<vector<T>> vec2d(int n, int m, T v){
    return vector<vector<T>>(n, vector<T>(m, v));
}

template<typename T>
vector<vector<vector<T>>> vec3d(int n, int m, int k, T v){
    return vector<vector<vector<T>>>(n, vector<vector<T>>(m, vector<T>(k, v)));
}

template<typename T>
void print_vector(vector<T> v, char delimiter=' '){
    if(v.empty()) {
        cout << endl;
        return;
    }
    for(int i = 0; i+1 < v.size(); i++) cout << v[i] << delimiter;
    cout << v.back() << endl;
}


//1-indexed
template <typename T>
struct bit{
    int n;
    vector<T> data;

    bit(int n_){
        n = 1;
        while(n < n_) n *= 2;
        data = vector<T>(n+1);
        for(int i = 0; i <= n; i++) data[i] = 0;
    }
    
    T sum(int i){
        T ret = 0;
        while(i > 0){
            ret += data[i];
            i -= i&-i;
        }
        return ret;
    }

    void add(int i, T x){
        while(i <= n){
            data[i] += x;
            i += i&-i;
        }
    }
};

const int N = 400000;
const int M = 200000;
vector<int> divs[N];

void init(){
    for(int x = 1; x <= N; x++){
        for(int i = 0; i*x <= N; i++){
            divs[x*i].push_back(x);
        }
    }
}

ll tri(ll x){
    return (x*(x-1))/2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    init();
    int t; cin >> t;
    vector<int> l(t), r(t);
    vector<vector<int>> queries(M+1);
    for(int i = 0; i < t; i++){
        cin >> l[i] >> r[i];
        queries[r[i]].push_back(i);
    }
    auto count = [&](int x, int l, int r){
        if(l >= r) return 0ll;
        auto pr = lower_bound(divs[x].begin(), divs[x].end(), r);
        auto pl = lower_bound(divs[x].begin(), divs[x].end(), l);
        return (ll)(pr-pl);
    };
    bit<ll> neg(M);
    vector<ll> ans(t);
    for(int k = 3; k <= M; k++){
        for(int i: divs[2*k]){
            if(i >= k) break;
            neg.add(i, count(2*k, i+1, k));
            neg.add(i, -count(2*k, i+1, k-i+1));
        }
        for(int i: divs[k]){
            if(i >= k) break;
            neg.add(i, count(k, i+1, k-i+1));
        }
        for(int i: queries[k]){
            ll cnt = r[i]-l[i]+1;
            ans[i] = (cnt*(cnt-1)*(cnt-2))/6;
            ans[i] -= neg.sum(M)-neg.sum(l[i]-1);
        }
    }
    print_vector(ans, '\n');
}