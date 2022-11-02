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
int t, n;
const int maxn = 1005;
vector<int> G[maxn];
int k1, k2;
vector<int> x, y;

bool vis[maxn];

int query(int x, int type){
    if(type == 0){
        cout << "A " << x << endl;
    }else{
        cout << "B " << x << endl;
    }
    fflush(stdout);
    int ret;
    cin >> ret;
    return ret;
}

void answer(int x){
    cout << "C " << x << endl;
    fflush(stdout);
}
int dep[maxn];
void dfs(int u, int fa, int d){
    dep[u] = d;
    for(auto v : G[u]){
        if(v == fa)
            continue;
        dfs(v, u, d + 1);
    }
}

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1;i <= n;i++){
            G[i].clear();
            vis[i] = false;
        }
        x.clear();
        y.clear();
        for(int i = 1;i < n;i++){
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        cin >> k1;
        for(int i = 1;i <= k1;i++){
            int num;
            scanf("%d", &num);
            x.emplace_back(num);
            vis[num] = true;
        }
        cin >> k2;
        for(int i = 1;i <= k2;i++){
            int num;
            scanf("%d", &num);
            y.emplace_back(num);
        }
        int root = query(y[0], 1);
        if(vis[root]){
            answer(root);
        }else{
            dfs(root, root, 0);
            int mi = x[0];
            for(int i = 1;i < x.size();i++){
                if(dep[x[i]] < dep[mi]){
                    mi = x[i];
                }
            }
            int num = query(mi, 0);
            bool flag = false;
            for(auto v : y){
                if(v == num){
                    flag = true;
                }
            }
            if(flag){
                answer(mi);
            }else{
                answer(-1);
            }
        }
    }
    return 0;
}