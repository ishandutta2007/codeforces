#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
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

int n, k;
string s;

vector<bool> ok[20];
const int INF = 1e9;

bool judge(int len){
    vector<vector<int>> cont(k, vector<int>(n+1));
    vector<vector<int>> enough(k);
    for(int i = 0; i < k; i++){
        for(int j = n-1; j >= 0; j--){
            if(!ok[i][j]) cont[i][j] = 0;
            else cont[i][j] = cont[i][j+1]+1;
        }
    }
    for(int i = 0; i < k; i++){
        for(int j = 0; j < n; j++){
            if(cont[i][j] >= len) enough[i].push_back(j);
        }
    }

    vector<int> dp(1<<k, INF);
    dp[0] = 0;
    for(int s = 0; s < (1<<k); s++){
        for(int i = 0; i < k; i++){
            if(s&(1<<i)) continue;
            int nx = s+(1<<i);
            auto p = lower_bound(enough[i].begin(), enough[i].end(), dp[s]);
            if(p == enough[i].end()) continue;
            chmin(dp[nx], (*p)+len);
        }
    }
    return dp[(1<<k)-1] != INF;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> n >> k;
    cin >> s;
    for(int i = 0; i < k; i++){
        ok[i].assign(n, false);
        for(int j = 0; j < n; j++){
            if(s[j] == '?' || s[j] == ('a'+i)) ok[i][j] = true;
        }
    }
    if(!judge(1)){
        cout << 0 << endl;
        return 0;
    }
    int l = 1, r = 2*n;
    while(r-l > 1){
        int len = (l+r)/2;
        if(judge(len)) l = len;
        else r = len;
    }
    cout << l << endl;
}