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

int n, k;
const int maxn = 1e5 + 5;

vector<int> G[maxn];
int dep[maxn];
int fa[maxn];
void dfs(int u, int par, int d){
    dep[u] = d;
    fa[u] = par;
    for(auto v : G[u]){
        if(v == par)
            continue;
        dfs(v, u, d + 1);
    }
}

int main(){
    cin >> n >> k;
    for(int i = 1;i < n;i++){
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 1, 0);
    int mx = 1;
    for(int i = 1;i <= n;i++){
        if(dep[i] > dep[mx]){
            mx = i;
        }
    }
    dfs(mx, mx, 0);
    int root = mx;
    for(int i = 1;i <= n;i++){
        if(dep[i] > dep[root]){
            root = i;
        }
    } 
    if((dep[root] - dep[mx]) != 2 * k){
        cout << "No" << endl;
        return 0;
    }else{
        int len = (dep[root] - dep[mx]) / 2;
        for(int i = 1;i <= len;i++){
            root = fa[root];
        }
        dfs(root, root, 0);
        bool flag = true;
        for(int i = 1;i <= n;i++){
            if(dep[i] < k and dep[i] > 0){
                if(G[i].size() < 4)
                    flag = false;
            }else if(dep[i] == k){
                if(G[i].size() > 1)
                    flag = false;
            }else{
                if(G[i].size() < 3)
                    flag = false;
            }
        }
        if(flag){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    return 0;
}