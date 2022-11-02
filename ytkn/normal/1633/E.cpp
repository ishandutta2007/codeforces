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


struct UnionFind {
    vector<int> data;
    UnionFind(int size) : data(size, -1) {}
    bool unionSet(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) {
        if (data[y] < data[x]) swap(x, y);
        data[x] += data[y]; data[y] = x;
        }
        return x != y;
    }
    bool findSet(int x, int y) {
        return root(x) == root(y);
    }
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    int size(int x) {
        return -data[root(x)];
    }
};

template<typename T>
class Compress{
    public:
    vector<T> data;
    int offset;
    Compress(vector<T> data_, int offset=0): offset(offset){
        set<T> st;
        for(T x: data_) st.insert(x);
        for(T x: st) data.push_back(x);
    };
    int operator[](T x) {
        auto p = lower_bound(data.begin(), data.end(), x);
        assert(x == *p);
        return offset+(p-data.begin());
	}
    T inv(int x){
        return data[x-offset];
    }
    int size(){
        return data.size();
    }
};

using P = pair<int, int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    vector<int> u(m), v(m);
    vector<ll> w(m);
    for(int i = 0; i < m; i++){
        cin >> u[i] >> v[i] >> w[i]; u[i]--; v[i]--;
        w[i]*= 2;
    }
    auto cp = Compress<ll>(w);
    int sz = cp.size();
    vector<vector<int>> indices(sz);
    for(int i = 0; i < m; i++) indices[cp[w[i]]].push_back(i);
    map<ll, vector<P>> swaps;
    swaps[0] = {};
    swaps[1e9] = {};
    for(int i = 0; i < sz; i++){
        ll w1 = cp.data[i];
        for(int j = i+1; j < sz; j++){
            ll w2 = cp.data[j];
            ll wc = (w1+w2)/2;
            swaps[wc].push_back(P(i, j));
        }
    }
    vector<ll> boundaries;
    for(auto [b, _]: swaps) boundaries.push_back(b);
    int p, k; ll a, b, c; cin >> p >> k >> a >> b >> c;
    vector<int> q(k);
    for(int i = 0; i < p; i++)cin >> q[i];
    for(int i = p; i < k; i++){
        q[i] = ((ll)q[i-1]*a+b)%c;
    }
    for(int i = 0; i < k; i++){
        q[i] *=2;
    }
    sort(q.begin(), q.end());
    vector<int> ord(sz), pos(sz);
    for(int i = 0; i < sz; i++) {
        ord[i] = i;
        pos[i] = i;
    }
    auto do_swap = [&](int i, int j){
        assert(abs(pos[i]-pos[j]) == 1);
        swap(ord[pos[i]], ord[pos[j]]);
        swap(pos[i], pos[j]);
    };
    int idx = 0;
    ll ans = 0;
    vector<ll> w_used(n-1);
    for(int i = 0; i+1 < (int)boundaries.size(); i++){
        int l = boundaries[i], r = boundaries[i+1];
        for(auto [j, k]: swaps[l]){
            do_swap(j, k);
        }
        // print_vector(ord);
       
        UnionFind uf(n);
        ll wsum = 0;
        int cnt = 0;
        for(int j: ord){
            ll ww = cp.data[j];
            for(int k: indices[j]){
                assert(ww == w[k]);
                if(!uf.findSet(u[k], v[k])){
                    w_used[cnt] = w[k];
                    wsum += ww;
                    cnt++;
                    uf.unionSet(u[k], v[k]);
                }
            }
        }
        sort(w_used.begin(), w_used.end());
        ll x_pos_cnt = 0, x_neg_cnt = n-1;
        int ii = 0;
        while(idx < k){
            if(q[idx] < r) {
                assert(q[idx] >= l);
                while(ii+1 < n && w_used[ii] <= q[idx]){
                    wsum -= w_used[ii]*2;
                    x_pos_cnt++;
                    x_neg_cnt--;
                    ii++;
                }
                // ll tmp = 0;
                // for(ll w: w_used) tmp += abs(w-q[idx]);
                ll tmp = wsum+q[idx]*(x_pos_cnt-x_neg_cnt);
                // cout << q[idx]/2 << ':' << tmp/2 << endl;;
                ans ^= tmp/2;
                idx++;
            }else{
                break;
            }
        }
    }
    cout << ans << endl;
}