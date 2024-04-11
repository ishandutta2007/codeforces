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

// calc ceil(a/b) 
template<typename T>
T ceil_div(T a, T b){
    return (a+b-1)/b;
}

using P = pair<int, int>;

vector<P> solve(int n){
    vector<P> ans;
    int mx = n;
    for(int x = n-1; x >= 2; x--){
        if(x == 2 || x == 4 || x == 16 || x == 256){
            int v = mx;
            while(v > 1){
                ans.push_back(P(mx, x));
                v = ceil_div(v, x);
            }
            mx = x;
        }else{
            ans.push_back(P(x, mx));
        }
    }
    return ans;
}

void verify(int n, vector<P> ans){
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        a[i] = i;
    }
    for(auto [x, y]: ans){
        a[x] = ceil_div(a[x], a[y]);
    }
    print_vector(a);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        auto p = solve(n);
        // verify(n, p);
        cout << p.size() << endl;
        for(auto [x, y]: p) cout << x << ' ' << y << endl;
    }
}