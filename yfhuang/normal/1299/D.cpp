#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;

const int mod = 1e9 + 7;

int n, m;
const int maxn = 1e5 + 5;
const int maxm = 405;
int a[maxn], b[maxn], w[maxn], p[maxn];
int fa[maxn];
int from[maxn], sum[maxn];
vector<pair<int, int> > G[maxn];
int Find(int x){
    return fa[x] == x ? x : fa[x] = Find(fa[x]);
}

typedef bitset<32> info;

info q[maxm];
int l, r, trans[maxn][32];
unordered_set<info> s;
unordered_map<info, int> home;
vector<int> v[maxn][2];
void preprocess(){
    q[l = r = 1] = 1;
    s.insert(q[1]);
    while(l <= r){
        info tmp = q[l++];
        for(int i = 0;i < 32;i++){
            info res = tmp;
            for(int j = 0;j < 32;j++){
                res[i ^ j] = (res[i ^ j] | tmp[j]);
            }
            if(!s.count(res)){
                s.insert(res);
                q[++r] = res;
            }
        }
    }
    for(int i = 1;i <= r;i++){
        home[q[i]] = i;
    }
    for(int i = 1;i <= r;i++){
        info tmp = q[i];
        for(int j = 0;j < 32;j++){
            info res = tmp;
            for(int k = 0;k < 32;k++){
                res[k ^ j] = (res[k ^ j] | tmp[k]);
            }
            if(res.count() == tmp.count() * 2) trans[i][j] = home[res];
            else trans[i][j] = 0;
        }
    }
}

void dfs(int u, int par, int top, int len){
    sum[u] = len, from[u] = top;
    for(auto v : G[u]){
        if(v.first == par)
            continue;
        dfs(v.first, u, top, len ^ v.second);
    }
}

bool cmp(int x, int y){
    return (a[x] == 1 || b[x] == 1) < (a[y] == 1 || b[y] == 1);
}

void add(int &a, int b){
    a += b;
    if(a >= mod)
        a -= mod;
}

bool vis[maxn];
bool key[maxn];


int dp[maxn][maxm];

int main(){
    preprocess();
    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        scanf("%d%d%d", &a[i], &b[i], &w[i]);
        p[i] = i;
    } 
    sort(p + 1, p + 1 + m, cmp);
    for(int i = 1;i <= n;i++){
        fa[i] = i;
    }
    for(int i = 1;i <= m;i++){
        int id = p[i];
        int fx = Find(a[id]);
        int fy = Find(b[id]);
        if(fx != fy){
            fa[fx] = fy;
            G[a[id]].emplace_back(b[id], w[id]);
            G[b[id]].emplace_back(a[id], w[id]);
        }else{
            vis[id] = true;
        }
    }
    for(auto v : G[1]){
        dfs(v.first, 1, v.first, v.second);
        key[v.first] = true;
    }
    for(int i = 1;i <= m;i++){
        if(vis[i]){
            int len = sum[a[i]] ^ sum[b[i]] ^ w[i];
            if(from[a[i]] == from[b[i]]){
                v[from[a[i]]][0].push_back(len);
            }else{
                if(from[a[i]] == 0){
                    v[from[b[i]]][1].push_back(len);
                }else{
                    v[from[a[i]]][1].push_back(len);
                }       
            }
        }
    }
    dp[0][1] = 1;
    for(int i = 1;i <= n;i++){
        if(!key[i]){
            memcpy(dp[i], dp[i - 1], sizeof(dp[i - 1]));
        }else{
            if(v[i][1].size()){
                for(int j = 1;j <= r;j++){
                    add(dp[i][j], dp[i - 1][j]);
                    int res = j;
                    for(auto len : v[i][0]){
                        res = trans[res][len];
                    }
                    if(res != 0) add(dp[i][res], 2LL * dp[i - 1][j] % mod);
                    for(auto len : v[i][1]){
                        res = trans[res][len];
                    }
                    if(res != 0) add(dp[i][res], dp[i - 1][j]);
                }
            }else{
                for(int j = 1;j <= r;j++){
                    add(dp[i][j], dp[i - 1][j]);
                    int res = j;
                    for(auto len : v[i][0]){
                        res = trans[res][len];
                    }
                    if(res != 0) add(dp[i][res], dp[i - 1][j]);
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1;i <= r;i++){
        add(ans, dp[n][i]);
    }
    cout << ans << endl;
    return 0;
}