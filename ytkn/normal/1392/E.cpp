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

class Simulator{
    public:
    int n;
    vector<vector<ll>> a;
    Simulator(int n): n(n){
        a = vec2d(n, n, 0ll);
    }
    void set_field(vector<vector<ll>> b){
        a = b;
    }
    ll gen(){

    }
    private:
    vector<P> path;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    auto in_field = [&](int i, int j){
        return 0 <= i && i < n && 0 <= j && j < n;
    };
    auto a = vec2d(n, n, 0ll);
    auto l = vec2d(n, n, 0ll);
    auto r = vec2d(n, n, 0ll);
    for(int d = 0; d < 2*n-1; d++){
        for(int i = 0; i < 2*n; i++){
            int j = d-i;
            if(!in_field(i, j)) continue;
            int ir = i-1, jr = j+1;
            if(!in_field(ir, jr)){
                a[i][j] = 0;
                l[i][j] = 0;
                if(i != 0) chmax(r[i][j], r[i-1][j] + a[i][j]);
                if(j != 0) chmax(r[i][j], r[i][j-1] + a[i][j]);
            }else{
                l[i][j] = max(0ll, r[ir][jr]+1);
                if(i != 0) chmax(a[i][j], l[i][j] - a[i-1][j]);
                if(j != 0) chmax(a[i][j], l[i][j] - a[i][j-1]);
                if(i != 0) chmax(r[i][j], r[i-1][j] + a[i][j]);
                if(j != 0) chmax(r[i][j], r[i][j-1] + a[i][j]);
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    int q; cin >> q;
    while(q--){
        vector<P> path;
        ll k; cin >> k;
        int x = n-1, y = n-1;
        while(true){
            path.push_back(P(x, y));
            if(x == 0 && y == 0) break;
            if(x == 0){
                y--; continue;
            }
            if(y == 0){
                x--; continue;
            }
            k -= a[x][y];
            if(k <= r[x-1][y]) x--;
            else y--;
        }
        reverse(path.begin(), path.end());
        for(auto [x, y]: path) cout << x+1 << ' ' << y+1 << endl;
    }
}