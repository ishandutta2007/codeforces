#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

struct edge{
    ll to, cost;
};

bool used[600000];
ll cnt[600000];
vector<edge> G[600000];
ll N;
ll g, b;
void clear(ll n){
    g = 0;
    b = 0;
    for(ll i = 0; i < 2*n; i++){
        used[i] = false;
        G[i].clear();
    }
}

void dfs(ll v){
    cnt[v] = 1;
    used[v] = true;
    for(ll i = 0; i < G[v].size(); i++){
        if(!used[G[v][i].to]){
            dfs(G[v][i].to);
            ll tmp = cnt[G[v][i].to];
            ll cost = G[v][i].cost;
            ll rem = 2*N-tmp;
            g += (tmp%2 == 1 ? cost : 0);
            b += min(tmp, rem)*cost;
            cnt[v] += tmp;
        }
    }
    // cout << v << ' ' << cnt[v] << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    ll t;
    cin >> t;
    for(ll _ = 0; _ < t; _++){
        cin >> N;
        clear(N);
        for(ll i = 0; i < 2*N-1; i++){
            ll a, b, t;
            cin >> a >> b >> t;
            a--; b--;
            G[a].push_back((edge){b, t});
            G[b].push_back((edge){a, t});
        }
        dfs(0);
        cout << g << ' ' << b << endl;
    }
}