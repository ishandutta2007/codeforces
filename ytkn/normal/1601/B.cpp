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
struct segtree{
    int n;
    T UNIT;
    vector<T> dat;
    T (*calc)(T, T);

    segtree(int n_, T unit, T (*_calc)(T, T)){
        UNIT = unit;
        calc = _calc;
        n = 1;
        while(n < n_) n *= 2;
        dat = vector<T>(2*n);
        for(int i = 0; i < 2*n; i++) dat[i] = UNIT;
    }

    void insert(int k, T a){
        dat[k+n-1] = a;
    }
    void update_all(){
        for(int i = n-2; i >= 0; i--){
            dat[i] = calc(dat[i*2+1], dat[i*2+2]);
        }
    }
    //k(0-indexed)a
    void update(int k, T a){
        k += n-1;
        dat[k] = a;
        while(k > 0){
            k = (k-1)/2;
            dat[k] = calc(dat[k*2+1], dat[k*2+2]);
        }
    }

    //[a, b)
    //[a, b]query(a, b+1)
    T query(int a, int b, int k=0, int l=0, int r=-1){
        if(r < 0) r = n;
        if(r <= a || b <= l) return UNIT;
        if(a <= l && r <= b) return dat[k];
        else{
            T vl = query(a, b, k*2+1, l, (l+r)/2);
            T vr = query(a, b, k*2+2, (l+r)/2, r);
            return calc(vl, vr);
        }
    }
};

struct node{
    int val, idx;
};

node calc_min(node n1, node n2){
    if(n1.val <= n2.val) return n1;
    return n2;
}

const int INF = 1e9;

node unit = node{INF, -1};

using P = pair<int, int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<int> a(n+1), b(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    vector<vector<int>> pre(n+1);
    for(int i = 1; i <= n; i++){
        pre[i+b[i]].push_back(i);
    }
    segtree<node> sgt(n+1, unit, calc_min);
    
    for(int i = 1; i <= n; i++) {
        sgt.update(i, node{i-a[i], i});
    }
    auto dist = vec2d(n+1, 2, -1);
    auto nx = vec2d(n+1, 2, P(-1, -1));
    queue<P> que;
    auto push = [&](int i, int j, int d){
        if(dist[i][j] != -1) {
            assert(false);
            return;
        }
        dist[i][j] = d;
        que.push(P(i, j));
    };
    push(0, 1, 0);
    while(!que.empty()){
        auto [i, j] = que.front(); que.pop();
        if(j == 0){
            for(int v: pre[i]){
                push(v, 1, dist[i][j]);
                nx[v][1] = P(i, j);
            }
        }else{
            while(true){
                auto nd = sgt.query(i+1, n+1);
                if(nd.val > i) break;
                push(nd.idx, 0, dist[i][j]+1);
                sgt.update(nd.idx, unit);
                nx[nd.idx][0] = P(i, j);
            }
        }
    }
    if(dist[n][0] == -1){
        cout << -1 << endl;
        return 0;
    }
    vector<int> ans;
    P cur(n, 0);
    while(cur != P(0, 1)){
        auto [i, j] = cur;
        cur = nx[i][j];
        if(cur.second == 1) ans.push_back(cur.first);
    }
    cout << ans.size() << endl;
    print_vector(ans);
}