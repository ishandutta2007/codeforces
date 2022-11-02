#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int T;
int n;

const int maxn = 2e5 + 5;
vector<int> G[maxn];
ll p[maxn][22], a[maxn], b[maxn];
ll suma[maxn], sumb[maxn];
int dep[maxn];

void dfs(int u, int d){
    dep[u] = d;
    if(u==1){
        suma[u] = sumb[u] = 0;
    }else{
        suma[u] = suma[p[u][0]] + a[u];
        sumb[u] = sumb[p[u][0]] + b[u];
    }
    for(auto v : G[u]){
        dfs(v, d + 1);
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 1;i <= n;i++){
            G[i].clear();
        }
        for(int i = 2;i <= n;i++){
            cin >> p[i][0] >> a[i] >> b[i];
            G[p[i][0]].push_back(i);
        }
        p[1][0] = 1;
        for(int j = 1;j <= 20;j++){
            for(int i = 1;i <= n;i++){
                p[i][j] = p[p[i][j-1]][j-1];
            }
        }
        dfs(1, 0);
        for(int i = 2;i <= n;i++){
            int u = i;
            for(int j = 20;j >= 0;j--){
                if(sumb[p[u][j]] > suma[i]){
                    u = p[u][j]; 
                }
            }
            if(sumb[u] > suma[i]){
                u = p[u][0];
            }
            cout << dep[u] << " \n"[i == n];
        }
    }
    return 0;
}