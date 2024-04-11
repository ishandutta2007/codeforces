#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;


int n;
const int maxn = 2e5 + 5;

int fa[maxn][2];
int sz[maxn][2];

int Find(int x, int id){
    return fa[x][id] == x ? x : fa[x][id] = Find(fa[x][id], id);
}


int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        fa[i][0] = fa[i][1] = i;
        sz[i][0] = sz[i][1] = 1;
    }
    for(int i = 1;i < n;i++){
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        int fx = Find(u, c);
        int fy = Find(v, c);
        if(fx != fy){
            fa[fx][c] = fy;
            sz[fy][c] += sz[fx][c];
        }
    }
    long long ans = 0;
    for(int i = 1;i <= n;i++){
        int fx0 = Find(i, 0);
        int fx1 = Find(i, 1);
        ans += 1LL * (sz[fx0][0] - 1) * (sz[fx1][1] - 1) + (sz[fx0][0] - 1) + (sz[fx1][1] - 1);
    }
    cout << ans << endl;
    return 0;
}