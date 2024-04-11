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

using P = pair<ll, ll>;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int m = s.size();
    vector<P> points;
    points.push_back(P(0, 0));
    int dx = 0, dy = 0;
    for(int i = 0; i < m; i++){
        if(dx == 0 && dy == 0){
            if(s[i] == 'D') dx++;
            else dy++;
            continue;
        }
        if(s[i] == 'D'){
            if(dx > 0){
                dx++;
            }else{
                assert(dy > 0);
                auto [x, y] = points.back();
                points.push_back(P(x+dx, y+dy));
                dx = 1; dy = 0;
            }
        }else{
            if(dy > 0){
                dy++;
            }else{
                assert(dx > 0);
                auto [x, y] = points.back();
                points.push_back(P(x+dx, y+dy));
                dx = 0; dy = 1;
            }
        }
    }
    {
        auto [x, y] = points.back();
        points.push_back(P(x+dx, y+dy));
    }
    int np = points.size();
    auto [gx, gy] = points.back();
    bool used_d = false, used_r = false;
    ll ans = 0; 
    for(int i = 0; i+1 < np; i++){
        auto [x1, y1] = points[i];
        auto [x2, y2] = points[i+1];

        if(x1 == x2){
            assert(y1 < y2);
            if(used_d) ans += (y2-y1)*(n-gx);
            else ans += (y2-y1);
            used_r = true;
        }else{
            assert(y1 == y2);
            if(used_r) ans += (x2-x1)*(n-gy);
            else ans += (x2-x1);
            used_d = true;
        }
    }
    if(used_r && used_d){
        ans += (n-gx)*(n-gy);
    }else if(used_r){
        ans += (n-gy);
    }else if(used_d){
        ans += (n-gx);
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