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

using P = pair<ll, int>;
const ll inf = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, p, k; cin >> n >> p >> k;
    vector<ll> a(n);
    vector<P> vp(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        vp[i] = P(a[i], i);
    }
    auto score = vec2d(n, p, 0ll);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < p; j++){
            cin >> score[i][j];
        }
    }
    sort(vp.begin(), vp.end(), greater<P>());
    vector<int> popcount(1<<p);
    for(int s = 0; s < (1<<p); s++){
        for(int i = 0; i < p; i++){
            if(s&(1<<i)) popcount[s]++;
        }
    }
    auto dp = vec2d(2, 1<<p, -inf);
    dp[0][0] = 0;
    for(int i = 0; i < n; i++){
        int pre = i%2;
        int cur = pre^1;
        int idx = vp[i].second;
        for(int s = 0; s < (1<<p); s++) dp[cur][s] = -inf;
        for(int s = 0; s < (1<<p); s++){
            if(k > i-popcount[s]){
                chmax(dp[cur][s], dp[pre][s]+a[idx]);
            }else{
                chmax(dp[cur][s], dp[pre][s]);
            }
            for(int j = 0; j < p; j++){
                if(s&(1<<j)) continue;
                chmax(dp[cur][s+(1<<j)], dp[pre][s]+score[idx][j]);
            }
        }
    }
    cout << dp[n%2][(1<<p)-1] << endl;
}