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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int R, G, B; cin >> R >> G >> B;
    vector<int> r(R), g(G), b(B);
    for(int i = 0; i < R; i++) cin >> r[i];
    for(int i = 0; i < G; i++) cin >> g[i];
    for(int i = 0; i < B; i++) cin >> b[i];
    sort(r.begin(), r.end(), greater<int>());
    sort(g.begin(), g.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    auto dp = vec3d(R+1, G+1, B+1, 0);
    for(int i = 0; i <= R; i++){
        for(int j = 0; j <= G; j++){
            for(int k = 0; k <= B; k++){
                if(i+1 <= R && j+1 <= G){
                    chmax(dp[i+1][j+1][k], dp[i][j][k]+r[i]*g[j]);
                }
                if(j+1 <= G && k+1 <= B){
                    chmax(dp[i][j+1][k+1], dp[i][j][k]+g[j]*b[k]);
                }
                if(k+1 <= B && i+1 <= R){
                    chmax(dp[i+1][j][k+1], dp[i][j][k]+b[k]*r[i]);
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i <= R; i++){
        for(int j = 0; j <= G; j++){
            for(int k = 0; k <= B; k++){
                chmax(ans, dp[i][j][k]);
            }
        }
    }
    cout << ans << endl;
}