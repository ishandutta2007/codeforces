#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 1005;

char s[maxn][maxn];
int n,m,p;
int speed[15];
queue<pair<int, int> > q[15];
int ans[15];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int d[maxn][maxn];
bool in(int x,int y){
    return x > 0 && x <= n && y > 0 && y <= m;
}
int main(){
    while(cin >> n >> m >> p){
        memset(d, 0x3f, sizeof(d));
        for(int i = 1;i <= p;i++){
            cin >> speed[i];
        }
        for(int i = 1;i <= n;i++){
            scanf("%s", s[i] + 1);
        }
        int tmp = 0;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                if(s[i][j] >= '1' && s[i][j] <= '9'){
                    d[i][j] = 0;
                    q[s[i][j] - '0'].push(make_pair(i, j));
                } 
            }
        }
        int cur = 0;
        int round = 0;
        while(true){
            if(tmp == p)
                break;
            if(cur == 0)
                round++;
            int player = cur + 1;
            while(!q[player].empty()){
                pair<int, int> p = q[player].front();
                int x = p.first;
                int y = p.second;
                if(d[x][y] == round * speed[player])
                    break;
                q[player].pop();
                for(int i = 0;i < 4;i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(in(nx, ny) && s[nx][ny] == '.'){
                        s[nx][ny] = '0' + player;
                        d[nx][ny] = d[x][y] + 1;
                        q[player].push(make_pair(nx, ny));
                    }
                }
                if(q[player].empty())
                    tmp++;
            }
            cur = (cur + 1) % p;
        }
        memset(ans, 0, sizeof(ans));
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                if(s[i][j] != '#')
                    ans[s[i][j] - '0']++;
            }
        }
        for(int i = 1;i <= p;i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}