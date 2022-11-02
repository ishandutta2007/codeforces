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
#include <random>

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

vector<int> gen_array(int n, int l, int r){
    int d = r-l;
    random_device rnd;
    mt19937 mt(rnd());
    vector<int> ans(n);
    int x = mt();
    for(int i = 0; i < n; i++) ans[i] = l+(mt()%d);
    return ans;
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

int dp[2][105][10105];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<int> a(n);
    set<int> st;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        st.insert(a[i]);
    }
    // a = gen_array(n, 98, 101);
    vector<int> cnt(101);
    for(int x: a) cnt[x]++;
    // print_vector(cnt);
    dp[0][0][0] = 1;
    for(int w = 0; w <= 100; w++){
        int pre = w%2;
        int cur = pre^1;
        for(int j = 0; j <= 100; j++){
            for(int k = 0; k <= 100*100; k++){
                dp[cur][j][k] = 0;
            }
        }
        for(int j = 0; j <= 100; j++){
            for(int k = 0; k <= 100*100; k++){
                assert(dp[pre][j][k] >= 0);
                if(dp[pre][j][k] == 0) continue;
                dp[cur][j][k]+=dp[pre][j][k];
                dp[cur][j+cnt[w]+1][k+cnt[w]*w+w]-=dp[pre][j][k];
                assert(k+cnt[w]*w <= n*100);
                assert(j+cnt[w] <= n);
            }
        }
        for(int j = 0; j <= 100; j++){
            for(int k = 0; k <= 100*100; k++){
                if(k >= w && j >= 1) dp[cur][j][k] += dp[cur][j-1][k-w];
            }
        }
         for(int j = 0; j <= 100; j++){
            for(int k = 0; k <= 100*100; k++){
                chmin(dp[cur][j][k], 2);
            }
        }
    }
    int sum = accumulate(a.begin(), a.end(), 0);
    int ans = 0;
    for(int w = 1; w <= 100; w++){
        for(int c = 1; c <= cnt[w]; c++){
            assert(dp[1][c][w*c] >= 1);
            if(dp[1][c][w*c] == 1){
                if(st.size() == 2 && c == cnt[w]){
                    chmax(ans, n);
                }
                chmax(ans, c);
            }
        }
    }
    cout << ans << endl;
}