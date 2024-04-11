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

//1-indexed
template <typename T>
struct bit{
    int n;
    vector<T> data;

    bit(int n_){
        n = 1;
        while(n < n_) n *= 2;
        data = vector<T>(n+1);
        for(int i = 0; i <= n; i++) data[i] = 0;
    }
    
    T sum(int i){
        T ret = 0;
        while(i > 0){
            ret += data[i];
            i -= i&-i;
        }
        return ret;
    }

    void add(int i, T x){
        while(i <= n){
            data[i] += x;
            i += i&-i;
        }
    }
};

const int inf = 1e9;

void solve(){
    int n, k; cin >> n >> k;
    vector<int> p(n);
    vector<int> pos(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i]; p[i]--;
        pos[p[i]] = i;
    }
    auto invs = vec2d(n+1, n, 0);
    bit<int> bt(n);
    for(int i = 0; i <= n; i++){
        for(int j = i; j < n; j++){
            invs[i][j] = bt.sum(n) - bt.sum(pos[j]+1);
        }
        if(i == n) break;
        bt.add(pos[i]+1, 1);
    }
    auto dp = vec3d(n+1, k+1, 1<<k, inf);
    dp[0][0][0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= k; j++){
            int x = i-j;
            if(x < 0) continue;
            // [0, x-1]
            //  x
            for(int s = 0; s < (1<<k); s++){
                if(dp[i][j][s] == inf) continue;
                auto count_inv = [&](int l){
                    int ans = 0;
                    int added = pos[x+l];
                    for(int idx = 1; idx < l; idx++){
                        if(s&(1<<(idx-1))){
                            // debug_value(x+idx)
                            int already = pos[x+idx];
                            if(already > added) ans++;
                        }
                    }
                    return ans;
                };
                // x
                int next_unfilled = min(x+k+1, n);
                for(int l = 1; l <= k && x+l < n; l++){
                    if(s&(1<<(l-1))) continue;
                    next_unfilled = x+l;
                    break;
                }
                int next_s = s>>(next_unfilled-x);
                int next_j = (i+1)-next_unfilled;
                chmin(dp[i+1][next_j][next_s], dp[i][j][s]+invs[x][x]+count_inv(0));
                if(j == k){ // x
                    continue;
                }
                for(int l = 1; l <= k && x+l < n; l++){
                    if(s&(1<<(l-1))) continue;
                    int next_s = s+(1<<(l-1));
                    assert(j+1 <= k);
                    assert(next_s < (1<<k));
                    chmin(dp[i+1][j+1][next_s], dp[i][j][s]+invs[x][x+l]+count_inv(l));
                }
            }
        }
    }
    cout << dp[n][0][0] << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}