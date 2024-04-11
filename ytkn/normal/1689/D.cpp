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
        
    }
    /**
     * sum(v[il:ir)[jl:jr))
     */ 
    
    private:
    int n, m;
    vector<vector<T>> v;
    vector<vector<T>> v_cumsum;
};

int v[2005][2005];
int v_cumsum[2005][2005];



void solve(){
    int n, m; cin >> n >> m;
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];
    int black = 0;
    for(int i = 0; i < n+m-1; i++) {
        for(int j = 0; j < n+m-1; j++){
            v[i][j] = 0;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int x = i+j, y = i-j+(m-1);
            if(s[i][j] == 'B'){
                v[x][y] = 1;
                black++;
            }else{
                v[x][y] = 0;
            }
        }
    }
    
    for(int i = 0; i < n+m-1; i++) {
        for(int j = 0; j < n+m-1; j++){
            v_cumsum[i+1][j+1] = v_cumsum[i+1][j]+v_cumsum[i][j+1]-v_cumsum[i][j]+v[i][j];
        }
    }

    auto calc_sum = [&](int il, int ir, int jl, int jr){
        if(ir <= il) return 0;
        if(jr <= jl) return 0;
        if(ir > n+m-1) ir = n+m-1;
        if(jr > n+m-1) jr = n+m-1;
        if(il < 0) il = 0;
        if(jl < 0) jl = 0;
        return v_cumsum[ir][jr]-v_cumsum[ir][jl]-v_cumsum[il][jr]+v_cumsum[il][jl];
    };

    auto find_pos = [&](int len){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int x = i+j, y = i-j+(m-1);
                int sum = calc_sum(x-len, x+len+1, y-len, y+len+1);
                if(sum == black) return make_pair(i, j);
            }
        }
        return make_pair(-1, -1);
    };
    if(find_pos(0).first != -1){
        auto [i, j] = find_pos(0);
        cout << i+1 << ' ' << j+1 << '\n';
        return;
    }
    int l = 0, r = n+m;
    while(r-l > 1){
        int len = (l+r)/2;
        if(find_pos(len).first == -1) l = len;
        else r = len;
    }
    auto [i, j] = find_pos(r);
    cout << i+1 << ' ' << j+1 << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}