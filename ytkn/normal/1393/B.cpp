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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<int> cnt(100001);
    multiset<int> st;
    for(int i = 1; i <= 100000; i++) st.insert(0);
    auto add = [&](int x){
        st.erase(st.find(cnt[x]));
        cnt[x]++;
        st.insert(cnt[x]);
    };
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        add(x);
    }
    auto erase = [&](int x){
        st.erase(st.find(cnt[x]));
        cnt[x]--;
        st.insert(cnt[x]);
    };
    auto ok = [&](){
        if(st.empty()) return false;
        int r = *prev(st.end());
        if(r < 4) return false;
        r -= 4;
        if(r >= 4) return true;
        int rem = 2;
        rem -= r/2;
        if(st.size() == 1) return false;
        int c = *prev(prev(st.end()));
        rem -= c/2;
        if(rem <= 0) return true;
        if(st.size() == 2) return false;
        int l = *prev(prev(prev(st.end())));
        rem -= l/2;
        return rem <= 0;
    };
    
    int q; cin >> q;
    while(q--){
        char c; cin >> c;
        int x; cin >> x;
        if(c == '+') add(x);
        else erase(x);
        if(ok()) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}