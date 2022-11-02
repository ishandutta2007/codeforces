#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int n, m, h;

const int maxn = 105;
int a[maxn],b[maxn], c[maxn][maxn];

int ans[maxn][maxn];

int main(){
    cin >> n >> m >> h;
    for(int i = 1;i <= m;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++){
        cin >> b[i];
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin >> c[i][j];
        }
    }
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= n;j++){
            if(c[j][i] == 1){
                c[j][i] = min(a[i], b[j]);
            }
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            printf("%d%c", c[i][j], j == m ? '\n' : ' ');
        }
    }
    return 0;
}