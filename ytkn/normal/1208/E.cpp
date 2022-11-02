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

using P = pair<int, int>;
using T = tuple<ll, int, int>;
const int inf = 1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, w; cin >> n >> w;
    vector<ll> imos(w+1);
    for(int i = 0; i < n; i++){
        int len; cin >> len;
        vector<ll> a(len);
        for(int j = 0; j < len; j++) cin >> a[j];
        vector<T> vp;
        int rem = w-len;
        for(int l = 0; l < len; l++) {
            int r = l+rem+1;
            vp.push_back(T(a[l], l, r));
        }
        vp.push_back(T(0, 0, rem));
        vp.push_back(T(0, w-rem, w));
        sort(vp.begin(), vp.end(), greater<T>());
        set<P> st;
        st.insert(P(-inf, 0));
        st.insert(P(w, w+inf));
        for(auto [x, l, r]: vp){
            auto p = st.lower_bound(P(l, r));
            auto [l1, r1] = *prev(p);
            auto [l2, r2] = *p;
            // debug_value(prev(p)->second)
            // cout << l1 << ' ' << r1 << ' ' << l << ' ' << r << ' ' << l2 << ' ' << r2 << endl;
            // assert(l1 <= l);
            // assert(r <= r2);
            int lx = max(l, r1);
            int rx = min(r, l2);
            if(lx >= rx) continue;
            // cout << lx << ' ' << rx << endl;
            imos[lx] += x;
            imos[rx] -= x;
            if(lx == r1){
                st.erase(P(l1, r1));
                lx = l1;
            }
            if(rx == l2){
                st.erase(P(l2, r2));
                rx = r2;
            }
            st.insert(P(lx, rx));
        }
        // for(auto it: mp) {
        //     auto [l, r] = it.first;
        //     cout << l << ',' << r << ':' << it.second << ' ';
        // }
        // cout << endl;
    }

    for(int i = 1; i < w; i++) imos[i] += imos[i-1];
    for(int i = 0; i < w; i++) cout << imos[i] << ' ';
    cout << endl;
}