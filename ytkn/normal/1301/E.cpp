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
    CumsumGrid(vector<vector<T>> v): v(v){
        n = v.size();
        m = v[0].size();
        v_cumsum = vector<vector<T>>(n+1, vector<T>(m+1, T(0)));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++){
                v_cumsum[i+1][j+1] = v_cumsum[i+1][j]+v_cumsum[i][j+1]-v_cumsum[i][j]+v[i][j];
            }
        }
    }
    /**
     * sum(v[il:ir)[jl:jr))
     */ 
    T sum(int il, int ir, int jl, int jr){
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
    vector<vector<T>> v;
    vector<vector<T>> v_cumsum;
};

int cnt_cumsum[505][505][505];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m, q; cin >> n >> m >> q;
    auto a = vec2d(n, m, 0);
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        for(int j = 0; j < m; j++){
            if(s[j] == 'R') a[i][j] = 0;
            if(s[j] == 'G') a[i][j] = 1;
            if(s[j] == 'Y') a[i][j] = 2;
            if(s[j] == 'B') a[i][j] = 3;
        }
    }
    vector<CumsumGrid<int>> cumsum_color;
    for(int k = 0; k < 4; k++){
        auto cnt = vec2d(n, m, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] == k) cnt[i][j] = 1;
            }
        }
        cumsum_color.push_back(CumsumGrid<int>(cnt));
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            auto ok = [&](int x){
                if(cumsum_color[0].sum(i-x, i, j-x, j) < x*x) return false;
                if(cumsum_color[1].sum(i-x, i, j, j+x) < x*x) return false;
                if(cumsum_color[2].sum(i, i+x, j-x, j) < x*x) return false;
                if(cumsum_color[3].sum(i, i+x, j, j+x) < x*x) return false;
                return true;
            };
            int l = 0, r = min(n, m)+1;
            while(r-l > 1){
                int x = (l+r)/2;
                if(ok(x)) l = x;
                else r = x;
            }
            for(int x = 0; x <= l; x++){
                cnt_cumsum[i+1][j+1][x] = cnt_cumsum[i+1][j][x]+cnt_cumsum[i][j+1][x]-cnt_cumsum[i][j][x]+1;
            }
            for(int x = l+1; x <= 500; x++){
                cnt_cumsum[i+1][j+1][x] = cnt_cumsum[i+1][j][x]+cnt_cumsum[i][j+1][x]-cnt_cumsum[i][j][x];
            }
        }
    }
    while(q--){
        int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2; r1--; c1--; r2++; c2++;
        int lr = r2-r1;
        int lc = c2-c1;
        auto ok = [&](int x){
            if(x*2 > min(lr, lc)) return false;
            int sum = cnt_cumsum[r2-x][c2-x][x]-cnt_cumsum[r2-x][c1+x][x]-cnt_cumsum[r1+x][c2-x][x]+cnt_cumsum[r1+x][c1+x][x];
            // cout << x << ':' << sum << endl;
            return sum > 0; 
        };
        int l = 0, r = 500;
        while(r-l > 1){
            int x = (l+r)/2;
            if(ok(x)) l = x;
            else r = x;
        }
        cout << 4*l*l << '\n';
    }
}