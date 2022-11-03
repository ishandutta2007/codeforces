#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>

using namespace std;

const int N = 65;

char g[N][N];

bool dp[N][N][N * N];
int pre[N][N][N * N];
int n,a[N];
int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d",a + i);
    }
    sort(a + 1,a + 1 + n);
    dp[0][0][0] = 1;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j < N;j++){
            for(int k = a[i];k < N * N;k++){
                if(k < j * (j - 1) / 2) continue;
                if(dp[i - 1][j - 1][k - a[i]]) dp[i][j][k] = 1,pre[i][j][k] = i - 1;
                if(dp[i][j - 1][k - a[i]]) dp[i][j][k] = 1,pre[i][j][k] = i;
            }
        }
    }
    int i;

    for(i = n;i < N;i++){
        if(dp[n][i][i * (i - 1) / 2]) break;
    }
    if(i == N){
        cout << "=" << endl;
        return 0;
    }else{
        cout << i << endl;
    }

    int x = n,y = i,z = i * (i - 1) / 2;
    pair<int,int> c[N];int tot = 0;
    while(x || y || z){
        c[tot] = make_pair(a[x],++tot);
        int tmp = a[x];
        x = pre[x][y][z]; y--; z -= tmp;
    }
    for(int i = 1;i <= tot;i++){
        sort(c + i,c + 1 + tot);
        int k = c[i].first;
        g[c[i].second][c[i].second] = '0';
        //cout << c[i].second << "!" << endl;
        for(int j = i + 1;j <= i + k;j++){
            c[i].first--;
            int u = c[i].second;
            int v = c[j].second;
            g[u][v] = '1';
            g[v][u] = '0';
            //cout << u << " " << v << endl;
        }
        for(int j = i + k + 1;j <= tot;j++){
            int u = c[i].second;
            int v = c[j].second;
            c[j].first--;
            g[v][u] = '1';
            g[u][v] = '0';
           // cout << v << " " << u << endl;
        }
    }

    for(int i = 1;i <= tot;i++){
        for(int j = 1;j <= tot;j++){
            putchar(g[i][j]);
        }
        putchar('\n');
    }
    return 0;
}