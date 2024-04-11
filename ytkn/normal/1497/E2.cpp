#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
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
const int N_MAX = 10000000;

int norm[N_MAX+1];

void init(){
    for(int i = 1; i <= N_MAX; i++) norm[i] = i;
    for(int i = 2; i*i <= N_MAX; i++){
        for(int j = 1; i*i*j <= N_MAX; j++){
            while(norm[i*i*j]%(i*i) == 0) norm[i*i*j]/=(i*i);
        }
    }
}

class Counter{
    public:
    int n;
    vector<int> cnt;
    int unique_cnt = 0;
    Counter(int n): n(n){
        cnt.resize(n);
    }
    void add(int x){
        sum++;
        if(cnt[x] > 0) cnt[x]+=1;
        else{
            cnt[x] = 1;
            unique_cnt++;
        }
    }
    void erase(int x){
        cnt[x]--;
        if(cnt[x] == 0) unique_cnt--;
        sum--;
    }
    int dupliactes(){
        return sum-unique_cnt;
    }
    int size(){
        return sum;
    }
    private:
    int sum = 0;
};

const int INF = 1e9;

std::random_device rd;
std::mt19937 mt(rd());

inline int get_int(){
    // int x; cin >> x; return x;
    return (mt()%10000000)+1;
}

/**
 * 
 */ 
void solve(){
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        // a[i] = get_int();
        a[i] = norm[a[i]];
    }
    map<int, int> compress = [&](){
        map<int, int> mp;
        for(int x : a){
            if(mp.count(x)) continue;
            mp[x] = mp.size();
        }
        return mp;
    }();
    vector<int> b(n);
    for(int i = 0; i < n; i++) b[i] = compress[a[i]];

    vector<vector<int>> dp(n+1, vector<int>(k+1, INF));
    vector<Counter> counter(k+1, Counter(n));
    dp[0][0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= k; j++){
            counter[j].add(b[i]);
            while(counter[j].dupliactes() > j) {
                int pre = i+1-counter[j].size();
                counter[j].erase(b[pre]);
            }
        }
        for(int j = 0; j <= k; j++){
            for(int l = 0; j+l <= k; l++){
                int pre = i+1-counter[l].size();
                chmin(dp[i+1][j+l], dp[pre][j]+1);
            }
        }
    }
    int ans = INF;
    for(int j = 0; j <= k; j++) chmin(ans, dp[n][j]);
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    init();
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
}