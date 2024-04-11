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


template<typename T>
class CumsumGrid{
    public:
    vector<vector<T>> v;
    CumsumGrid(vector<vector<T>> v): v(v){
        n = v.size();
        m = v[0].size();
        v_cumsum = vector<vector<T>>(n+1, vector<T>(m+1, T(0)));
        init();
    }
    void init(){
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++){
                v_cumsum[i][j] = 0;
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++){
                v_cumsum[i+1][j+1] = v_cumsum[i+1][j]+v_cumsum[i][j+1]-v_cumsum[i][j]+v[i][j];
            }
        }
    }
    /**
     * sum(v[il:ir)[jl:jr))
     */ 
    T sum(int il, int jl, int ir, int jr){
        if(ir <= il) return T(0);
        if(jr <= jl) return T(0);
        if(ir > n) ir = n;
        if(jr > m) jr = m;
        if(il < 0) il = 0;
        if(jl < 0) jl = 0;
        return v_cumsum[ir][jr]-v_cumsum[ir][jl]-v_cumsum[il][jr]+v_cumsum[il][jl];
    }
    private:
    int n, m;
    vector<vector<T>> v_cumsum;
};

ll sum_square(ll x){
    return (x*(x+1)*(2*x+1))/6;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    vector<string> s(n);
    auto cnt = vec2d(n, m, 0);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        // s[i] = string(m, 'a');
    }
    auto same_up = vec2d(n, m, 0);
    auto same_down = vec2d(n, m, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == 0) same_up[i][j] = 1;
            else{
                if(s[i][j] == s[i-1][j]) same_up[i][j] = same_up[i-1][j]+1;
                else same_up[i][j] = 1;
            }
        }
    }
    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j < m; j++){
            if(i == n-1) same_down[i][j] = 1;
            else{
                if(s[i][j] == s[i+1][j]) same_down[i][j] = same_down[i+1][j]+1;
                else same_down[i][j] = 1;
            }
        }
    }
    auto ok_left = vec2d(n, m, 0);
    auto ok_right = vec2d(n, m, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(j == 0) ok_left[i][j] = 1;
            else{
                if(s[i][j-1] == s[i][j]){
                    ok_left[i][j] = min({ok_left[i][j-1]+1, same_up[i][j], same_down[i][j]});
                }else{
                    ok_left[i][j] = 1;
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = m-1; j >= 0; j--){
            if(j == m-1) ok_right[i][j] = 1;
            else{
                if(s[i][j+1] == s[i][j]){
                    ok_right[i][j] = min({ok_right[i][j+1]+1, same_up[i][j], same_down[i][j]});
                }else{
                    ok_right[i][j] = 1;
                }
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            ans += min(ok_left[i][j], ok_right[i][j]);
        }
    }
    cout << ans << endl;
}