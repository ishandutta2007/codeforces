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

int n, m, q;
const int maxn = 2e6 + 5;

typedef pair<int, int> pii;

vector<pii> add[maxn], del[maxn];

int a[305][305], fa[maxn], rk[maxn];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int diff[2000005];

bool in(int x, int y){
    return x >= 0 and x < n and y >= 0 and y < m;
}

int Find(int x){
    return x == fa[x] ? x : fa[x] = Find(fa[x]);
}

int Union(int x, int y){
    int fx = Find(x);
    int fy = Find(y);
    if(fx == fy)
        return 0;
    if(rk[fx] == rk[fy]){
        fa[fx] = fy;
        rk[fy]++;
        return 1;
    }
    if(rk[fx] > rk[fy]){
        swap(fx, fy);
    }
    fa[fx] = fy;
    return 1;
}

void solve(vector<pii> changes, int coeff, int col){
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            fa[i * m + j] = i * m + j;
            rk[i * m + j] = 1;
            a[i][j] = -1;
        }
    }
    for(auto it : changes){
        int p = it.first, id = it.second;
        int x = p / m, y = p % m;
        int now = 1;
        a[x][y] = col;
        for(int i = 0;i < 4;i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(in(nx, ny)){
                if(a[nx][ny] == a[x][y]){
                    now -= Union(nx * m + ny, p);                  
                }
            }
        }
        diff[id] += coeff * now;
    }
}

int main(){
    cin >> n >> m >> q;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            a[i][j] = 0;
        }
    }
    int colors = 1;
    for(int i = 0;i < q;i++){
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        x--; y--;
        add[c].emplace_back(x * m + y, i);
        del[a[x][y]].emplace_back(x * m + y, i);
        if(a[x][y] == c){
            continue;
        }
        a[x][y] = c;
        colors = max(c + 1, colors);
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            del[a[i][j]].emplace_back(i * m + j, q);
        }
    }
    for(int i = 0;i < colors;i++){
        reverse(del[i].begin(), del[i].end());
    }
    for(int i = 0;i < colors;i++){
        solve(add[i], 1, i);
    }
    int cur = 1;
    //for(int i = 0;i < q;i++){
    //    cur += diff[i];
    //    printf("%d\n", cur);
    //}
    for(int i = 0;i < colors;i++){
        solve(del[i], -1, i);
    }
    cur = 1;
    for(int i = 0;i < q;i++){
        cur += diff[i];
        printf("%d\n", cur);
    }
    return 0;
}