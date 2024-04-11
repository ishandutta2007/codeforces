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

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    vector<int> pos(n);
    for(int i = 0; i < n; i++){
        cin >> a[i]; a[i]--;
        pos[a[i]] = i;
    }
    set<int> st;
    vector<int> next_small(n, n);
    for(int i = 0; i < n; i++){
        int idx = pos[i];
        auto p = st.lower_bound(idx);
        if(p != st.end()) {
            next_small[idx] = *p;
        }
        st.insert(idx);
    }
    st.clear();
    vector<int> next_large(n, n);
    for(int i = n-1; i >= 0; i--){
        int idx = pos[i];
        auto p = st.lower_bound(idx);
        if(p != st.end()) {
            next_large[idx] = *p;
        }
        st.insert(idx);
    }

    auto calc_next = [&](int i) -> int{
        assert(i != n-1);
        if(a[i] < a[i+1]){
            int cur = i;
            int mx = next_small[i];
            while(true){
                if(next_large[cur] >= mx) return cur;
                cur = next_large[cur];
            }
        }else{
            int cur = i;
            int mx = next_large[i];
            while(true){
                if(next_small[cur] >= mx) return cur;
                cur = next_small[cur];
            }
        }
    };
    int ans = 0;
    int cur = 0;
    while(cur != n-1){
        ans++;
        cur = calc_next(cur);
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}