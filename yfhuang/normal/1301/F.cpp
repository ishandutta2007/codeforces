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

int n, m, k;
int q;

const int maxk = 45;
const int maxn = 1005;

int d[maxk][maxn][maxn];
vector<pair<int, int> > cells[maxk];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int a[maxn][maxn];
bool done[maxk];
void bfs(int col){
    memset(d[col], -1, sizeof(d[col]));
    queue<pair<int, int> > q;
    for(auto it : cells[col]){
        d[col][it.first][it.second] = 0;
        q.push(it);
    }
    memset(done, false, sizeof(done));
    done[col] = true;
    while(!q.empty()){
        pair<int, int> p = q.front();q.pop();
        int r = p.first;
        int c = p.second;
        if(!done[a[r][c]]){
            done[a[r][c]] = true;
            for(auto it : cells[a[r][c]]){
                int nr = it.first;
                int nc = it.second;
                if(d[col][nr][nc] == -1){
                    d[col][nr][nc] = d[col][r][c] + 1;
                    q.push(make_pair(nr, nc));
                }
            }
        }
        for(int i = 0;i < 4;i++){
            int nr = r + dx[i];
            int nc = c + dy[i];
            if(nr >= 1 and nr <= n and nc >= 1 and nc <= m and d[col][nr][nc] == -1){
                d[col][nr][nc] = d[col][r][c] + 1;
                q.push(make_pair(nr, nc));
            }
        }
    }
}

int main(){
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            scanf("%d", &a[i][j]);
            cells[a[i][j]].push_back(make_pair(i, j));
        }
    }
    for(int i = 1;i <= k;i++){
        bfs(i);
    }
    int q;
    cin >> q;
    for(int i = 1;i <= q;i++){
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        int ans = abs(x1 - x2) + abs(y1 - y2);
        for(int j = 1;j <= k;j++){
            ans = min(ans, d[j][x1][y1] + d[j][x2][y2] + 1);
        }
        cout << ans << endl;
    }
    return 0;
}