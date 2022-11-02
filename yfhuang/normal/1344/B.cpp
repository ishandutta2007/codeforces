#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;

string s[maxn];
int n, m;

bool in(int x, int y){
    return x >= 0 and x < n and y >= 0 and y < m;
}

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

bool vis[maxn][maxn];

void bfs(int sx, int sy){
    queue<pair<int, int> > q;
    q.push({sx, sy});
    vis[sx][sy] = true;
    while(!q.empty()){
        pair<int, int> p = q.front();q.pop();
        int x = p.first;
        int y = p.second;
        for(int i = 0;i < 4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(in(nx, ny) and s[nx][ny] == '#'){
                if(!vis[nx][ny]){
                    q.push(make_pair(nx, ny));
                    vis[nx][ny] = true;
                }
            }
        }
    }
}

int row[maxn], col[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> s[i];
    } 
    int zeror = 0, zeroc = 0;
    bool flag = true;
    for(int i = 0;i < n;i++){
        row[i] = 0;
        int l = -1, r = -1;
        for(int j = 0;j < m;j++){
            if(s[i][j] == '#'){
                r = j;
                row[i]++;
            }
        }
        for(int j = m - 1;j >= 0;j--){
            if(s[i][j] == '#'){
                l = j;
            }
        }
        if(l != -1){
            for(int j = l;j <= r;j++){
                if(s[i][j] != '#'){
                    flag = false;
                } 
            }
        }
        if(row[i] == 0){
            zeror++;
        }
    }
    for(int j = 0;j < m;j++){
        col[j] = 0;
        int l = -1, r = -1;
        for(int i = 0;i < n;i++){
            if(s[i][j] == '#'){
                r = i;
                col[j]++;
            }
        }
        for(int i = n - 1;i >= 0;i--){
            if(s[i][j] == '#'){
                l = i;
            }
        }
        if(l != -1){
            for(int i = l;i <= r;i++){
                if(s[i][j] != '#'){
                    flag = false;
                }
            }
        }
        if(col[j] == 0){
            zeroc++;
        }
    }
    if(zeroc == 0 and zeror > 0)
        flag = false;
    if(zeroc > 0 and zeror == 0)
        flag = false;
    if(flag){
        int cnt = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(s[i][j] == '#' and vis[i][j] == false){
                    bfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;
}