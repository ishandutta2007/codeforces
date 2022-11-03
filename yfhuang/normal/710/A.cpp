#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 10;
bool vis[maxn][maxn];
int main(){
    char s[4];
    scanf("%s",s);
    int x = s[0] - 'a' + 1;
    int y = s[1] - '0';
    memset(vis,0,sizeof(vis));
    for(int i = 1;i <= 8;i++){
        for(int j = 1;j <= 8;j++){
            vis[i][j] = 1;
        }
    }
    int ans = 0;
    for(int i = -1;i <= 1;i++){
        for(int j = -1;j <= 1;j++){
            int nx = x + i;
            int ny = y + j;
            ans += vis[nx][ny];
        }
    }
    cout << ans - 1 << endl;
}