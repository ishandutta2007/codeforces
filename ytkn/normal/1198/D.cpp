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

int n;
char s[50][50];

bool seen[55][55][55][55];
int dp[55][55][55][55];

int solve(int il, int jl, int ir, int jr){
    if(seen[il][jl][ir][jr]) return dp[il][jl][ir][jr];
    int h = ir-il, w = jr-jl;
    int cnt = 0;
    for(int i = il; i < ir; i++){
        for(int j = jl; j < jr; j++){
            if(s[i][j] == '#') cnt++;
        }
    }
    int ans = cnt > 0 ? max(h, w) : 0;
    for(int ic = il+1; ic < ir; ic++){
        chmin(ans, solve(il, jl, ic, jr)+solve(ic, jl, ir, jr));
    }
    for(int jc = jl+1; jc < jr; jc++){
        chmin(ans, solve(il, jl, ir, jc)+solve(il, jc, ir, jr));
    }
    seen[il][jl][ir][jr] = true;
    dp[il][jl][ir][jr] = ans;
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        string t; cin >> t;
        for(int j = 0; j < n; j++) s[i][j] = t[j];
    }
    cout << solve(0, 0, n, n) << endl;
}