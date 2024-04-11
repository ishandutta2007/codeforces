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
    int h, n; cin >> h >> n;
    vector<int> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    reverse(p.begin(), p.end());
    vector<P> sects;
    int c = 1;
    int pre = p[0];
    int l = p[0];
    int ans = 0;
    auto add = [&](int l, int r){
        if(l == 1) return;
        if(r != h) r++;
        if((r-l+1)%2 == 1) return;
        sects.push_back(P(l, r));
    };
    for(int i = 1; i < n; i++){
        if(pre+1 != p[i]){
            add(l, pre);
            l = p[i];
        }
        pre = p[i];
    }
    add(l, pre);
    cout << sects.size() << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}