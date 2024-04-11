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

void verify(int n, int m, vector<P> ans){
    assert(ans.size() == n*m);
    set<P> visited, used;
    for(int i = 0; i < n*m; i++){
        visited.insert(ans[i]);
        if(i > 0){
            auto [x0, y0] = ans[i-1];
            auto [x1, y1] = ans[i];
            used.insert(P(x1-x0, y1-y0));
        }
    }
    assert(visited.size() == n*m);
    assert(used.size() == n*m-1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    vector<P> ans;
    for(int i = 0; i < n/2; i++){
        vector<int> v;
        for(int i = 0; i < m/2; i++){
            v.push_back(i);
            v.push_back(m-1-i);
        }
        if(m%2 == 1) v.push_back(m/2);
        auto u = v;
        reverse(u.begin(), u.end());
        vector<int> x = {i, n-1-i};
        for(int y: u) v.push_back(y);
        assert(v.size() == 2*m);
        for(int i = 0; i < 2*m; i++){
            ans.push_back(P(x[i%2], v[i]));
        }
    }
    if(n%2 == 1){
        vector<int> v;
        for(int i = 0; i < m/2; i++){
            v.push_back(i);
            v.push_back(m-1-i);
        }
        if(m%2 == 1) v.push_back(m/2);
        int x = n/2;
        for(int y: v) ans.push_back(P(x, y));
    }
    // verify(n, m, ans);
    for(auto [x, y]: ans) cout << x+1 << ' ' << y+1 << "\n";
}