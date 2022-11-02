#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

vector<int> v[20];
ll cnt[20][20];
ll dp[1<<20];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int a;
        cin >> a;
        a--;
        v[a].push_back(i);
    }
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            if(i == j) continue;
            if(v[i].size() == 0) continue;
            if(v[j].size() == 0) continue;
            for(auto k : v[j]){
                auto p = upper_bound(v[i].begin(), v[i].end(), k);
                cnt[i][j] += p-v[i].begin();
            }
        }
    }
    for(int i = 1; i < (1<<20); i++) {
        dp[i] = 1e15;
    }
    for(int i = 0; i < (1<<20); i++){
        for(int j = 0; j < 20; j++){
            int m = (1<<j);
            if(i&m) continue;
            ll tmp = dp[i];
            for(int k = 0; k < 20; k++){
                int l = (1<<k);
                if(!(i&l)) continue;
                tmp += cnt[k][j];
            }
            dp[i|m] = min(dp[i|m], tmp);
        }
    }
    cout << dp[(1<<20)-1] << endl;
}