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

template <typename T>
class OffsetVec{
    public:
	int n;
    vector<T> v;
	T& operator[](int x) {
        return v[x+n];
	}
    void print(){
        for(int i = -n; i <= n; i++) cout << v[i+n] << ' ';
        cout << endl;
    }
    OffsetVec(int _n){
        n = _n;
        v = vector<T>(2*n+1);
    }
    OffsetVec(int _n, T x){
        n = _n;
        v = vector<T>(2*n+1, x);
    }
};

const int INF = 1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<int> add(n);
    vector<OffsetVec<vector<int>>> v(n, OffsetVec(0, vector<int>()));
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int m = s.size();
        v[i] = OffsetVec(m, vector<int>());
        int sum = 0;
        for(int j = 0; j < m; j++){
            if(s[j] == '(') sum++;
            else sum--;
            v[i][sum].push_back(j);
        }
        add[i] = sum;
    }
    int ans = 0;
    vector<int> dp(1<<n, 0);
    vector<int> dp_ok(1<<n, 0);
    vector<bool> ok(1<<n, false);
    ok[0] = true;
    for(int s = 0; s < (1<<n); s++){
        if(!ok[s]) continue;
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(!(s&(1<<i))) continue;
            sum += add[i];
        }
        // cout << s << ' ' << sum << ' ' << dp[s] << endl;
        int mn = -sum-1;
        for(int i = 0; i < n; i++){
            if(s&(1<<i)) continue;
            int t = s+(1<<i);
            if(v[i].n < sum+1 || v[i][mn].empty()){
                int same = v[i].n < sum ? 0: v[i][-sum].size();
                chmax(dp[t], dp_ok[s]+same);
                chmax(dp_ok[t], dp_ok[s]+same);
                chmax(ans, dp[t]);
                ok[t] = true;
            }else{
                int j = v[i][mn][0];
                auto p = lower_bound(v[i][-sum].begin(), v[i][-sum].end(), j);
                int same = p-v[i][-sum].begin();
                chmax(dp[t], dp_ok[s]+same);
                chmax(ans, dp[t]);
            }
        }
    }
    cout << ans << endl;
}