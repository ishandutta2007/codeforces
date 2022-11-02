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

using namespace std;

int n, m;
const int maxn = 1e5 + 5;

vector<pair<int, int> > G[maxn];
int col[maxn];
void addedge(int u, int v, int c){
    G[u].push_back(make_pair(v, c));
    G[v].push_back(make_pair(u, c));
}

const int mod = 1e9 + 7;

bool dfs(int u){
    bool flag = true;
    for(auto edge : G[u]){
        int v = edge.first;
        int c = edge.second;
        if(col[v] == -1){
            col[v] = col[u] ^ c ^ 1;
            flag &= dfs(v);
        }else{
            if((col[v] ^ col[u]) != (c ^ 1)){
                return false;
            }
        } 
    }
    return flag;
}

int main(){
    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        addedge(a, b, c);
    }
    bool flag = true;
    int cnt = 0;
    memset(col, -1, sizeof(col));
    for(int i = 1;i <= n;i++){
        if(col[i] == -1){
            col[i] = 0;
            flag &= dfs(i);
            cnt++;
        }
    }
    if(!flag){
        cout << 0 << endl;
    }else{
        int ans = 1;
        for(int i = 1;i < cnt;i++){
            ans *= 2;
            if(ans >= mod)
                ans -= mod;
        }
        cout << ans << endl;
    }
    return 0;
}