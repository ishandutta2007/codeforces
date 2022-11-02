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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    auto ask = [&](vector<bool> &v){
        string s;
        for(int i = 0; i < m; i++){
            if(v[i]) s += '1';
            else s += '0';
        }
        cout << "? " << s << endl;
        int ans; cin >> ans;
        return ans;
    };
    vector<int> w(m);
    vector<bool> v(m);
    for(int i = 0; i < m; i++){
        v[i] = true;
        w[i] = ask(v);
        v[i] = false;
    }
    int sum = 0;
    int ans = 0;
    vector<P> vp(m);
    for(int i = 0; i < m; i++){
        vp[i] = P(w[i], i);
    }
    sort(vp.begin(), vp.end());
    for(auto [_, i]: vp){
        v[i] = true;
        int x = ask(v);
        if(sum+w[i] == x){
            ans += w[i];
        }
        sum = x;
    }
    cout << "! " << ans << endl;
}