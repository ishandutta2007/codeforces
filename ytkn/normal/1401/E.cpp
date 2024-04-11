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

    T all(){
        return sum(n);
    }

    void add(int i, T x){
        while(i <= n){
            data[i] += x;
            i += i&-i;
        }
    }
};

using P = pair<int, int>;

const int M = 1000000;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    vector<vector<int>> adds(M+1), erases(M+1);
    vector<vector<P>> queries(M+1);
    bit<int> bt(M+1);
    bt.add(1, 1);
    bt.add(M+1, 1);
    for(int i = 0; i < n; i++){
        int y, lx, rx; cin >> y >> lx >> rx;
        lx++; rx++;
        queries[y].push_back(P(lx, rx));
    }
    for(int i = 0; i < m; i++){
        int x, ly, ry; cin >> x >> ly >> ry; x++;
        if(ly == 0){
            bt.add(x, 1);
            erases[ry].push_back(x);
        }else{
            adds[ly].push_back(x);
        }
    }
    set<int> not_intersect;
    auto add = [&](int x){
        not_intersect.insert(x);
    };
    auto erase = [&](int x){
        if(not_intersect.count(x)) not_intersect.erase(x);
        else {
            bt.add(x, -1);
        }
    };
    auto query = [&](int l, int r) -> int{
        int x = bt.sum(r)-bt.sum(l-1);
        if(x >= 2) return x-1;
        return 0;
    };
    auto add_horizontal = [&](int l, int r){
        auto p = not_intersect.lower_bound(l);
        vector<int> erased;
        while(p != not_intersect.end() && *p <= r){
            erased.push_back(*p);
            bt.add(*p, 1);
            p++;
        }
        for(int x: erased) not_intersect.erase(x);
    };
    ll ans = 0;
    for(int y = 0; y <= M; y++){
        for(int x: adds[y]) add(x);
        for(auto [l, r]: queries[y]) {
            // cout << y << ' ' << l << ' ' << r << ' ' << query(l, r) << endl;
            ans += query(l, r);
        }
        if(y == M) ans += query(1, M+1);
        for(auto [l, r]: queries[y]) add_horizontal(l, r);
        for(int x: erases[y]) erase(x);
    }
    // cout << M << ' ' << 1 << ' ' << M+1 << ' ' << query(1, M+1) << endl;
    cout << ans << endl;
}