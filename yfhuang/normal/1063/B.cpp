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

const int maxn = 2005;
char s[maxn][maxn];

int n, m;
int sx, sy;
int L, R;
int dis[maxn][maxn];
bool vis[maxn][maxn];
typedef pair<int, int> pii;

priority_queue<pii, vector<pii>, greater<pii> > pq;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool in(int x, int y){
    return 0 <= x and x < n and 0 <= y and y < m;
}

void solve(){
    memset(dis, 0x3f, sizeof(dis));
    dis[sx][sy] = 0;
    pq.push(make_pair(0, sx * m + sy));   
    while(!pq.empty()){
        pii p = pq.top(); pq.pop();
        int d = p.first;
        int x = p.second / m;
        int y = p.second % m; 
        if(vis[x][y]){
            continue;
        }
        vis[x][y] = true;
        for(int i = 0;i < 2;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(!in(nx, ny) or s[nx][ny] == '*')
                continue;
            if(dis[nx][ny] > dis[x][y]){
                dis[nx][ny] = dis[x][y];
                pq.push(make_pair(dis[nx][ny], nx * m + ny));
            }
        }
        for(int i = 2;i < 4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(!in(nx, ny) or s[nx][ny] == '*')
                continue;
            int cnt = 0;
            if((ny - y) * (sy - y) > 0){
                cnt = 1;
            }
            if(dis[nx][ny] > dis[x][y] + cnt){
                dis[nx][ny] = dis[x][y] + cnt;
                pq.push(make_pair(dis[nx][ny], nx * m + ny));
            }
        }
    }
}

int main(){
    cin >> n >> m;
    cin >> sx >> sy;
    sx--, sy--;
    cin >> L >> R;
    for(int i = 0;i < n;i++){
        scanf("%s", s[i]); 
    }
    int ans = 0;
    solve();
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(dis[i][j] == 0x3f3f3f3f)
               continue;
            if(j <= sy){
                int L1 = sy - j + dis[i][j];
                int R1 = dis[i][j];
                if(L1 <= L and R1 <= R){
                    s[i][j] = '+';
                    ans++;
                }
            }else{
                int L1 = dis[i][j];
                int R1 = dis[i][j] + j - sy;
                if(L1 <= L and R1 <= R){
                    s[i][j] = '+';
                    ans++;
                }
            } 
        }
        //printf("%s\n", s[i]);
        //for(int j = 0;j < m;j++){
        //    printf("%d ", dis[i][j]);
        //}
        //cout << endl;
    }
    cout << ans << endl;
    return 0;
}