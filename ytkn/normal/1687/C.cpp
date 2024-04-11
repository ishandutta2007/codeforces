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

template<typename T>
class Cumsum{
    public:
    Cumsum(vector<T> v): v(v){
        n = v.size();
        v_cumsum = vector<T>(n+1, T(0));
        for(int i = 0; i < n; i++) v_cumsum[i+1] = v_cumsum[i]+v[i];
    }
    /**
     * v[l] + ... + v[r-1]
     */ 
    T sum(int l, int r){
        if(r <= l) return T(0);
        if(r > n) r = n;
        if(l < 0) l = 0;
        return v_cumsum[r]-v_cumsum[l];
    }
    int n;
    vector<T> v;
    vector<T> v_cumsum;
};

void solve(){
    int n, m; cin >> n >> m;
    vector<ll> a(n), b(n), c(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) c[i] = a[i]-b[i];
    auto cumsum = Cumsum<ll>(c).v_cumsum;
    vector<int> l(m), r(m);
    vector<bool> used(m);
    vector<vector<int>> sects(n+1);
    for(int i = 0; i < m; i++) {
        cin >> l[i] >> r[i]; l[i]--;
        sects[l[i]].push_back(i);
        sects[r[i]].push_back(i);
    }
    queue<int> que;
    auto push = [&](int i){
        if(!used[i] && cumsum[l[i]] == 0 && cumsum[r[i]] == 0){
            used[i] = true;
            que.push(i);
        }
    };
    for(int i = 0; i < m; i++){
        push(i);
    }
    set<int> st;
    for(int i = 0; i <= n; i++) st.insert(i);
    while(!que.empty()){
        int idx = que.front(); que.pop();
        auto p = st.lower_bound(l[idx]);
        vector<int> erased;
        while(p != st.end()){
            if(*p <= r[idx]) {
                erased.push_back(*p);
                p++;
            }else{
                break;
            }
        }
        for(int x: erased){
            cumsum[x] = 0;
            for(int idx: sects[x]) push(idx);
            st.erase(x);
        }
    }
    for(int i: st){
        if(cumsum[i] != 0){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}