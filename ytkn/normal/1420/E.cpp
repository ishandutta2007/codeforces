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

int dp[81][81][2000][2];
const int inf = 1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<vector<int>> indices(2);
    vector<int> cnt_zero;
    vector<int> cnt(2);
    for(int i = 0; i < n; i++){
        indices[a[i]].push_back(i);
        cnt[a[i]]++;
        if(a[i] == 1){
            cnt_zero.push_back(indices[0].size());
        }
    }
    auto count_move = vec3d(cnt[0]+1, cnt[1]+1, cnt[1]+1, 0);
    for(int i = 0; i <= cnt[0]; i++){
        for(int l = 0; l < cnt[1]; l++){
            for(int r = l+1; r <= cnt[1]; r++){
                count_move[i][l][r] = count_move[i][l][r-1] + abs(cnt_zero[r-1]-i);    
            }
        }
    }
    int max_swap = cnt[0]*cnt[1];
    for(int i = 0; i <= cnt[0]; i++){
        for(int j = 0; j <= cnt[1]; j++){
            for(int k = 0; k <= cnt[0]*j; k++){
                dp[i][j][k][0] = -inf;
                dp[i][j][k][1] = -inf;
            }
        }
    }
    dp[0][0][0][0] = 0;
    dp[0][0][0][1] = 0;
    for(int i = 0; i <= cnt[0]; i++){
        for(int j = 0; j <= cnt[1]; j++){
            for(int k = 0; k <= cnt[0]*j; k++){
                for(int l = 1; i+l <= cnt[0]; l++){
                    chmax(dp[i+l][j][k][0], dp[i][j][k][1]+i*l);
                }
                for(int l = 1; j+l <= cnt[1]; l++){
                    int nx_k = k+count_move[i][j][j+l];
                    assert(nx_k <= max_swap);
                    chmax(dp[i][j+l][nx_k][1], dp[i][j][k][0]);
                }
            }
        }
    }
    
    int ans = 0;
    for(int i = 0; i <= (n*(n-1))/2; i++){
        chmax(ans, dp[cnt[0]][cnt[1]][i][0]);
        chmax(ans, dp[cnt[0]][cnt[1]][i][1]);
        cout << ans << ' ';
    }
    cout << endl;
}