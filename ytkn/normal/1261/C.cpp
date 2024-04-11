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


using P = pair<int, int>;
const int inf = 1e9;

int dh[4] = {0, 0, -1, 1};
int dw[4] = {-1, 1, 0, 0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];
    auto v = vec2d(n, m, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(s[i][j] == 'X') v[i][j] = 1;
        }
    }
    auto infield = [&](int i, int j){
        return i >= 0 && i < n+2 && j >= 0 && j < m+2;
    };
    auto imos = vec2d(n+1, m+1, 0);
    auto cumsum = CumsumGrid<int>(v);
    auto ok = [&](ll t)->bool{
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                imos[i][j] = 0;
            }
        }
        ll len = t*2+1;
        ll area = len*len;
        for(int i = 0; i+len <= n; i++){
            for(int j = 0; j+len <= m; j++){
                if(cumsum.sum(i, i+len, j, j+len) == area){
                    imos[i][j] += 1;
                    imos[i+len][j] += -1;
                    imos[i][j+len] += -1;
                    imos[i+len][j+len] += 1;
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= m; j++){
                imos[i+1][j] += imos[i][j];
            }
        }
        for(int i = 0; i <= n; i++){
            for(int j = 0; j < m; j++){
                imos[i][j+1] += imos[i][j];
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(imos[i][j] == 0 && v[i][j] == 1) return false;
            }
        }
        return true;
    };
    int l = 0, r = n;
    while(r-l > 1){
        int t = (l+r)/2;
        if(ok(t)) l = t;
        else r = t;
    }
    cout << l << endl;
    ll len = l*2+1;
    ll area = len*len;
    vector<string> ans(n, string(m, '.'));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(cumsum.sum(i, i+len, j, j+len) == area){
                ans[i+l][j+l] = 'X';
            }
        }
    }
    print_vector(ans, '\n');
}