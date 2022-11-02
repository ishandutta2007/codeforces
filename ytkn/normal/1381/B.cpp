#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

int p[4005];
bool dp[4005][4005];

void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < 2*n; i++) cin >> p[i];
    int cnt = 1;
    int cur = p[0];
    vector<int> v;
    for(int i = 1; i < 2*n; i++){
        if(cur > p[i]) cnt++;
        else{
            v.push_back(cnt);
            cnt = 1;
            cur = p[i];
        }
    }
    v.push_back(cnt);
    dp[0][0] = true;
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j <= 2*n; j++){
            if(dp[i][j]) {
                dp[i+1][j] = true;
                dp[i+1][j+v[i]] = true;
            }
        }
    }
    int sz = v.size();
    cout << (dp[sz][n] ? "YES" : "NO") << endl;
    for(int i = 0; i <= 2*n; i++){
        for(int j = 0; j <= 2*n; j++){
            dp[i][j] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    for(int i = 0; i < t; i++) solve();
}