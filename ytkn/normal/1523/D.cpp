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

template<typename T>
void print_vector(vector<T> v, char delimiter=' '){
    if(v.empty()) {
        cout << endl;
        return;
    }
    for(int i = 0; i+1 < v.size(); i++) cout << v[i] << delimiter;
    cout << v.back() << endl;
}

const double TIME_LIMIT = 2.0;

vector<int> mebius(vector<int> a, int n){
    vector<int> dp(1<<n);
    for(int i = 0; i < (1 << n); i++){
        dp[i] = a[i];
    }
    for(int j = 0; j < n; j++){
        for(int i = 0; i < (1 << n); i++){
            if(!(i & (1 << j))){
                dp[i] += dp[i ^ (1 << j)];
            }
        }
    }
    return dp;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    clock_t start = clock();
    random_device rnd;
    mt19937 mt(rnd());
    int n, m, p; cin >> n >> m >> p;
    vector<ll> likes(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c; cin >> c;
            if(c == '1'){
                likes[i] += 1ll<<j;
            }
        }
    }
    auto popcount = [&](ll s){
        int ans = 0;
        for(int i = 0; i < m; i++){
            if(s&(1ll<<i)) ans++;
        }
        return ans;
    };
    auto calc = [&](int idx) -> ll{
        vector<int> v;
        for(int j = 0; j < m; j++){
            if(likes[idx]&(1ll<<j)){
                v.push_back(j);
            }
        }
        int mm = v.size();
        assert(mm <= p);
        vector<int> cnt(1<<mm);
        for(int i = 0; i < n; i++){
            int s = 0;
            for(int j = 0; j < mm; j++){
                if(likes[i]&(1ll<<v[j])) s += 1<<j;
            }
            cnt[s]++;
        }
        auto mb = mebius(cnt, mm);
        ll ans = 0;
        for(int s = 0; s < (1<<mm); s++){
            ll mask = 0;
            for(int j = 0; j < mm; j++){
                if(s&(1<<j)) mask += 1ll<<v[j];
            }
            if(mb[s]*2 >= n){
                if(popcount(ans) < popcount(mask)) ans = mask;
            }
        }
        return ans;
    };
    ll ans = 0;
    while(true){
        clock_t cur_time = clock();
        if((double)(cur_time - start) / CLOCKS_PER_SEC > TIME_LIMIT) break;
        int idx = mt()%n;
        ll tmp = calc(idx);
        if(popcount(ans) < popcount(tmp)) ans = tmp;  
    }
    for(int j = 0; j < m; j++){
        if(ans&(1ll<<j)) cout << 1;
        else cout << 0;
    }
    cout << endl;
}