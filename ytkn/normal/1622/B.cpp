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

void solve(){
    int n; cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    string s; cin >> s;
    vector<int> q(n);
    int cur = 1;
    vector<P> vp;
    for(int i = 0; i < n; i++){
        if(s[i] == '0') {
            vp.push_back(P(p[i], i));
        }
    }
    sort(vp.begin(), vp.end());
    for(auto [_, i]: vp){
        q[i] = cur;
        cur++;
    }
    vp.clear();
    for(int i = 0; i < n; i++){
        if(s[i] == '1') {
            vp.push_back(P(p[i], i));
        }
    }
    sort(vp.begin(), vp.end());
    for(auto [_, i]: vp){
        q[i] = cur;
        cur++;
    }
    print_vector(q);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}