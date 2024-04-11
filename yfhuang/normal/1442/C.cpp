#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cassert>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int n, m;
const int maxn = 2e5 + 5;

vector<int> G[2][maxn];

ll dis[26][maxn];
bool vis[26][maxn];

const int mod = 998244353;

int qpow(int a, int n){
    int ret = 1;
    while(n > 0){
        if(n & 1){
            ret = 1LL * ret * a % mod;
        }
        a = 1LL * a * a % mod;
        n >>= 1;
    }
    return ret;
}

void shortest_path(int s){
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    for(int i = 1;i <= n;i++){
        for(int j = 0;j < 26;j++){
            dis[j][i] = 1e18;
            vis[j][i] = 0;
        }
    }
    ll base = 1e9;
    dis[0][1] = 0;
    pq.push(mp(0, 26));
    while(!pq.empty()){
        auto it = pq.top(); pq.pop();
        int st = it.se;
        int u = st / 26;
        int i = st % 26;
        if(vis[i][u])
            continue;
        vis[i][u] = 1;
        if(i < 24 and dis[i + 1][u] > dis[i][u] + (1 << i)){
            dis[i + 1][u] = dis[i][u] + (1 << i);
            pq.push(mp(dis[i + 1][u], u * 26 + (i + 1)));
        }
        if(i >= 24 and dis[i ^ 1][u] > dis[i][u] + base){
            dis[i ^ 1][u] = dis[i][u] + base;
            pq.push(mp(dis[i ^ 1][u], u * 26 + (i ^ 1)));
        } 
        for(auto v : G[i & 1][u]){
            if(dis[i][v] > dis[i][u] + 1){
                dis[i][v] = dis[i][u] + 1;
                pq.push(mp(dis[i][v], v * 26 + i));
            }
        }
    }
    ll ans = dis[0][n];;
    int bestj = 0;
    for(int j = 1;j < 26;j++){
        if(dis[j][n] < ans){
            ans = dis[j][n];
            bestj = j;
        }
    }
    if(bestj <= 23){
        cout << ans << endl;
    }else{
        ans -= (1 << 24) - 1;
        ll cnt = ans / base;
        ll reminder = ans % base;
        cnt += 24;
        ans = (qpow(2, cnt) + mod - 1) % mod;
        ans = (ans + reminder) % mod; 
        cout << ans << endl;
    }
}


int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        int u, v;
        cin >> u >> v;
        G[0][u].push_back(v);
        G[1][v].push_back(u);
    }
    shortest_path(1);
    return 0;
}