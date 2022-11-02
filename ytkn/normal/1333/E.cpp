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

using Arr33 = array<array<int, 3>, 3>;
using P = pair<int, int>;

bool reachable(P p1, P p2, bool is_queen){
    auto [x1, y1] = p1;
    auto [x2, y2] = p2;
    if(x1 == x2) return true;
    if(y1 == y2) return true;
    if(is_queen){
        if(x1+y1 == x2+y2) return true;
        if(x1-y1 == x2-y2) return true;
    }
    return false;
}

bool ok(Arr33 v){
    vector<P> idx(10);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            idx[v[i][j]] = P(i, j);
        }
    }
    auto count = [&](bool is_queen){
        int ans = 0;
        P cur = idx[1];
        vector<bool> seen(10, false);
        seen[1] = true;
        int rem = 9;
        while(rem--){
            int mn = 100;
            int mn_reachable = 100;
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    if(seen[v[i][j]]) continue;
                    if(reachable(cur, P(i, j), is_queen)){
                        chmin(mn_reachable, v[i][j]);
                    }else{
                        chmin(mn, v[i][j]);
                    }
                }
            }
            if(mn_reachable != 100){
                seen[mn_reachable] = true;
                cur = idx[mn_reachable];
            }else{
                seen[mn] = true;
                ans++;
                cur = idx[mn];
            }
        }
        return ans;
    };
    int rook = count(false);
    int queen = count(true);
    // cout << queen << ' ' << rook << endl;
    return queen > rook;
}

void test(){
    vector<int> v(9);
    iota(v.begin(), v.end(), 1);
    do{
        Arr33 f;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                f[i][j] = v[i*3+j];
            }
        }
        if(ok(f) && f[0][2] == 1){
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    cout << f[i][j] << ' ';
                }
                cout << endl;
            }
            cout << "===" << endl;
        }
    }while(next_permutation(v.begin(), v.end()));
}

vector<vector<int>> ans3 = {
    {3, 7, 1},
    {6, 5, 2},
    {9, 4, 8}
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    // test();
    int n; cin >> n;
    if(n <= 2){
        cout << -1 << endl;
        return 0;
    }
    auto ans = vec2d(n, n, 0);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            ans[i][j] = ans3[i][j]+n*n-9;
        }
    }
    auto nx = [&](int i, int j) -> P{
        if(i == j){
            if(i%2 == 0){
                return P(i-1, j);
            }else{
                return P(i, j-1);
            }
        }
        if(i < j){
            if(j%2 == 0){
                if(i == 0) return P(i, j+1);
                return P(i-1, j);
            }else{
                return P(i+1, j);
            }
        }
        if(j < i){
            if(i%2 == 0){
                return P(i, j+1);
            }else{
                if(j == 0) return P(i+1, j);
                return P(i, j-1);
            }
        }
    };
    int cur = n*n-9;
    int i = 0, j = 3;
    for(int cur = n*n-9; cur >= 1; cur--){
        ans[i][j] = cur;
        P p = nx(i, j);
        i = p.first;
        j = p.second;
    }
    for(int i = 0; i < n; i++) print_vector(ans[i]);
}