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

const int Color = 0, Add = 1, Query = 2;
using T = tuple<int, int, int, int>;
using P = pair<int, int>;

class RangeAddPointGet {
    public:
    int n;
    bit<ll> bt = bit<ll>(1);
    RangeAddPointGet(int n): n(n) {
        bt = bit<ll>(n+2);
    }
    void add(int l, int r, ll x){
        l++; r++;
        bt.add(l, x);
        bt.add(r, -x);
    }
    ll get_val(int idx){
        return bt.sum(idx+1);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, q; cin >> n >> q;
    vector<T> queries(q);
    vector<ll> col_sum(n);
    for(int i = 0; i < q; i++){
        string s; cin >> s;
        if(s[0] == 'C'){
            int l, r, c; cin >> l >> r >> c;
            r++; c--;
            queries[i] = T(Color, l, r, c);
        }else if(s[0] == 'A'){
            int c, x; cin >> c >> x; c--;
            queries[i] = T(Add, c, x, -1);
            col_sum[c] += x;
        }else{
            int idx; cin >> idx;
            queries[i] = T(Query, idx, -1, -1);
        }
    }
    set<int> boundaries = {0, n+2};
    map<P, int> colors;
    RangeAddPointGet rp(n+5);
    auto erase_col = [&](int l, int r){
        int c = colors[P(l, r)];
        rp.add(l, r, -col_sum[c]);
        colors.erase(P(l, r));
    };
    auto add_col = [&](int l, int r, int c){
        colors[P(l, r)] = c;
        rp.add(l, r, col_sum[c]);
    };
    add_col(0, n+2, 0);
    auto color = [&](int l, int r, int c){
        auto p = boundaries.lower_bound(l);
        int lb = *prev(p);
        vector<int> v = {};
        while(true){
            if(*p > r) break;
            v.push_back(*p);
            p++;
        }
        int rb = *p;
        if(!v.empty()){
            int l_col = colors[P(lb, v[0])];
            erase_col(lb, v[0]);
            add_col(lb, l, l_col);
            int r_col = colors[P(v.back(), rb)];
            erase_col(v.back(), rb);
            add_col(r, rb, r_col);
        }else{
            int col = colors[P(lb, rb)];
            erase_col(lb, rb);
            add_col(lb, l, col);
            add_col(r, rb, col);
        }
        int m = v.size();
        for(int i = 0; i < m; i++){
            boundaries.erase(v[i]);
            if(i+1 < m){
                erase_col(v[i], v[i+1]);
            }
        }
        boundaries.insert(l);
        boundaries.insert(r);
        add_col(l, r, c);
        // for(auto [p, c]: colors){
        //     auto [l, r] = p;
        //     cout << l << ',' << r << ':' << c << endl;
        // }
        // for(int i = 1; i <= n; i++) cout << rp.get_val(i) << ' ';
        // cout << endl;
    };
    for(int i = 0; i < q; i++){
        int tp = get<0>(queries[i]);
        if(tp == Color){
            auto [_, l, r, c] = queries[i];
            color(l, r, c);
        }else if(tp == Add){
            auto [_, c, x, __] = queries[i];
            col_sum[c] -= x;
        }else{
            auto [_, idx, __, ___] = queries[i];
            ll ans = rp.get_val(idx);
            auto p = boundaries.upper_bound(idx);
            int r = *p;
            int l = *prev(p);
            int col = colors[P(l, r)];
            ans -= col_sum[col];
            cout << ans << "\n";
        }
    }
}