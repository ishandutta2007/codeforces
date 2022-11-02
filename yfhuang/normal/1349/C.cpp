#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pi;

const int INF = 0x3f3f3f3f;

const int maxn = 1005;

int fa[maxn * maxn];
int sz[maxn * maxn];
int dis[maxn][maxn];

int n, m, t;

int id(int r, int c){
    return r * m + c; 
}

bool in(int x, int y){
    return x >= 0 and x < n and y >= 0 and y < m;
}

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

string s[maxn];

int Find(int x){
    return fa[x] == x ? x : fa[x] = Find(fa[x]);
}

void bfs(){
    memset(dis, INF, sizeof(dis));
    queue<pi> q;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            int u = id(i, j);
            int fx = Find(u);
            if(sz[fx] != 1){
                dis[i][j] = 0;
                q.push(mp(i, j));
            }
        }
    }
    while(!q.empty()){
        pi p = q.front(); q.pop();
        int x = p.fi;
        int y = p.se;
        for(int k = 0;k < 4;k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(in(nx, ny)){
                if(dis[nx][ny] > dis[x][y] + 1){
                    dis[nx][ny] = dis[x][y] + 1;
                    q.push(mp(nx, ny));
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> t;
    for(int i = 0;i < n;i++){
        cin >> s[i];
    } 
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            int u = id(i, j);
            fa[u] = u;
            sz[u] = 1;
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            for(int k = 0;k < 2;k++){
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(in(nx, ny) and s[nx][ny] == s[i][j]){
                    int u = id(nx, ny);
                    int v = id(i, j);
                    int fx = Find(u);
                    int fy = Find(v);
                    fa[fx] = fy;
                    sz[fy] += sz[fx];
                }
            }
        }
    }
    bfs();
    for(int i = 1;i <= t;i++){
        int x, y;
        long long p;
        cin >> x >> y >> p;
        x--, y--;
        if(dis[x][y] == INF){
            cout << s[x][y] << endl;
        }else{
            if(p <= dis[x][y]){
                cout << s[x][y] << endl;
            }else{
                long long c = p - dis[x][y];
                char ans = s[x][y];
                if(c & 1){
                    if(ans == '0')
                        ans = '1';
                    else
                        ans = '0';
                }
                cout << ans << endl;
            }
        }
    }
    return 0;
}