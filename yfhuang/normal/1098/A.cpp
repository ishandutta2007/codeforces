#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int n;
const int maxn = 1e5 + 5;
vector<int> G[maxn];
int s[maxn];
int a[maxn];
void dfs(int u, int fa, int pre){
    if(s[u] == -1){
        int x = 1e9 + 7;
        for(auto v: G[u]){
            if(v == fa)
                continue;
            else
                x = min(x, s[v]);
        }
        if(x != 1e9 + 7){
            a[u] = x - pre;
            for(auto v:G[u]){
                if(v == fa)
                    continue;
                else
                    dfs(v, u, a[u] + pre);
            }
        }else{
            a[u] = 0;
        }
    }else{
        a[u] = s[u] - pre;
        for(auto v: G[u]){
            if(v == fa)
                continue;
            else{
                dfs(v, u, s[u]);
            }
        }
    } 
}

int main(){
    while(cin >> n){
        for(int i = 1;i <= n;i++){
            G[i].clear();
        }
        for(int i = 2;i <= n;i++){
            int p;
            scanf("%d", &p);
            G[i].push_back(p);
            G[p].push_back(i);
        }
        for(int i = 1;i <= n;i++){
            scanf("%d", &s[i]);
        }
        dfs(1, 1, 0);
        bool flag = true;
        for(int i = 1;i <= n;i++){
            if(a[i] < 0)
                flag = false;
        }
        long long ans = 0;
        for(int i = 1; i <= n;i++){
            ans += a[i];
        }
        if(!flag){
            cout << "-1" << endl;
        }else{
            cout << ans << endl;
        }
    }
    return 0;
}