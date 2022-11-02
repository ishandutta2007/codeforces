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

int naive(int n, int m){
    int ans = 0;
    for(int x = 0; x < m; x++){
        if(__builtin_popcount(x^(x+n))%2 == 1) {
            ans++;
        }
    }
    return ans;
}

void solve(){
    ll n, m; cin >> n >> m;
    m--;
    ll dp[62][2][2][2];
    for(int i = 0; i <= 61; i++){
        for(int large = 0; large < 2; large++){
            for(int carry = 0; carry < 2; carry++){
                for(int p = 0; p < 2; p++){
                    dp[i][large][carry][p] = 0;
                }
            }
        }
    }
    dp[0][0][0][0] = 1;
    for(int i = 0; i <= 60; i++){
        bool m_standing = (m&(1ll<<i)) > 0;
        bool n_standing = (n&(1ll<<i)) > 0;
        for(int large = 0; large < 2; large++){
            for(int carry = 0; carry < 2; carry++){
                for(int p = 0; p < 2; p++){
                    for(int x = 0; x < 2; x++){
                        int next_large = [&](){
                            if(m_standing && x == 0) return 0;
                            if(!m_standing && x == 1) return 1;
                            return large;
                        }();
                        int next_carry = [&](){
                            int sum = carry+n_standing+x;
                            return sum >= 2;
                        }();
                        int next_p = [&](){
                            return carry^n_standing^p;
                        }();
                        dp[i+1][next_large][next_carry][next_p] += dp[i][large][carry][p];
                    }
                }
            }
        }
    }
    cout << dp[61][0][0][1] << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}