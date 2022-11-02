#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
ll dp0[200000];
ll dp1[200000];
ll dp01[200000];
ll dp10[200000];

struct edge{
    int to, cost;
};

vector<edge> G[200000];
bool used[200000];
ll ans;

ll pow2(ll n){
    return n*n;
}

// return if v is a leaf
bool dfs(int v){
    used[v] = true;
    bool ret = false;
    for(int i = 0; i < G[v].size(); i++){
        int to = G[v][i].to;
        int cost = G[v][i].cost;
        if(!used[to]){
            ret = true;
            bool isLeaf = dfs(to);
            if(cost == 0){
                dp0[v]++;
                dp0[v] += dp0[to];
                dp10[v] += (dp1[to]+dp10[to]);
                ans -= pow2(dp0[to]+1);
                ans -= ((dp0[to]+1)*(dp10[to]+dp1[to]));
            }else{
                dp1[v]++;
                dp1[v] += dp1[to];
                dp01[v] += (dp01[to]+dp0[to]);
                ans -= pow2(dp1[to]+1);
                ans -= ((dp1[to]+1)*(dp01[to]+dp0[to]));
            }
        }
    }
    ans += dp0[v]*2;
    ans += dp1[v]*2;
    ans += dp10[v];
    ans += dp01[v];
    ans += pow2(dp0[v]);
    ans += pow2(dp1[v]);
    ans += (dp1[v]*dp01[v]);
    ans += (dp1[v]*dp0[v]);
    ans += (dp0[v]*dp10[v]);
    // cout << v << ' ' << dp0[v] << ' ' << dp1[v] << ' ' << dp01[v] << ' ' << dp10[v] << endl;
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int N;
    cin >> N;
    for(int i = 0; i < N-1; i++){
        int x, y, c;
        cin >> x >> y >> c;
        x--; y--;
        G[x].push_back((edge){y, c});
        G[y].push_back((edge){x, c});
    }
    dfs(0);
    cout << ans << endl;
}