#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

const int maxn = 25;
bool vis[maxn][maxn];

int h, w;
bool in(int x, int y){
    return x >= 0 and x < h and y >= 0 and y < w;
}

bool onedge(int x, int y){
    return x == 0 or x == h - 1 or y == 0 or y == w - 1;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        memset(vis, 0, sizeof(vis));
        cin >> h >> w;
        for(int i = 0;i < h;i++){
            for(int j = 0;j < w;j++){
                if(onedge(i, j)){
                    bool flag = false;
                    for(int dx = -1;dx <= 1;dx++){
                        for(int dy = -1;dy <= 1;dy++){
                            if(dx == 0 and dy == 0)
                                continue;
                            int nx = i + dx, ny = j + dy;
                            if(onedge(nx, ny) and in(nx, ny)){
                                flag |= vis[nx][ny];
                            }
                        }
                    }
                    vis[i][j] = !flag;
                }
            }
        }
        for(int i = 0;i < h;i++){
            for(int j = 0;j < w;j++){
                if(vis[i][j]){
                    cout << '1';
                }else{
                    cout << '0';
                }
            }
            cout << endl;
        }
    }
    return 0;
}