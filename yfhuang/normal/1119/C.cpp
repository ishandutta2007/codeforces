#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;


int n, m;
const int maxn = 505;
int a[maxn][maxn];
int b[maxn][maxn];
int c[maxn][maxn];
int row[maxn], col[maxn];
int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            scanf("%d", &a[i][j]);
        }
    }
    for(int j = 1;j <= n;j++){
        for(int i = 1;i <= m;i++){
            scanf("%d", &b[j][i]);
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            c[i][j] = a[i][j] ^ b[i][j];
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            row[i] += c[i][j];
        }
    }
    for(int j = 1;j <= m;j++){
        for(int i = 1;i <= n;i++){
            col[j] += c[i][j];
        }
    }
    bool flag = true;
    for(int i = 1;i <= n;i++){
        if(row[i] & 1)
            flag = false;
    }
    for(int i = 1;i <= m;i++){
        if(col[i] & 1)
            flag = false;
    }
    if(flag)
        puts("Yes");
    else
        puts("No");
    return 0;

}