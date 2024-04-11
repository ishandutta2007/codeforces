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

int D[maxn][maxn], R[maxn][maxn];
int preD[maxn][maxn], preR[maxn][maxn];
int column[maxn][maxn], row[maxn][maxn];

char g[maxn][maxn];
int n, m;
const int mod = 1e9 + 7;
void add(int &a, int b){
    a += b;
    if(a >= mod)
        a -= mod;
}

int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        scanf("%s", g[i] + 1);
    }
    if(n == 1 and m == 1){
        cout << 1 << endl;
        return 0;
    }
    for(int i = 1;i <= n;i++){
        row[i][m + 1] = 0;
        for(int j = m;j >= 1;j--){
            row[i][j] = row[i][j + 1] + (g[i][j] == 'R');
        }
    }
    for(int j = 1;j <= m;j++){
        column[n + 1][j] = 0;
        for(int i = n;i >= 1;i--){
            column[i][j] = column[i + 1][j] + (g[i][j] == 'R');
        }
    }
    if(g[n][m] == 'R'){
        D[n][m] = 0;
        R[n][m] = 0;
    }else{
        D[n][m] = 1;
        R[n][m] = 1;
    }
    for(int i = n;i >= 1;i--){
        for(int j = m;j >= 1;j--){
            if(i == n and j == m){

            }else{
                int k1 = row[i][j] - (g[i][j] == 'R');
                int k2 = column[i][j] - (g[i][j] == 'R');
                if(k1 >= m - j){
                    R[i][j] = 0;
                }else{
                    R[i][j] = (preD[i][j + 1] - preD[i][m - k1 + 1] + mod) % mod;
                }
                if(k2 >= n - i){
                    D[i][j] = 0;
                }else{
                    D[i][j] = (preR[i + 1][j] - preR[n - k2 + 1][j] + mod) % mod;
                }
            }
            //cout << i << " " << j << " " << D[i][j] << " " << R[i][j] << endl;
            preD[i][j] = preD[i][j + 1];
            add(preD[i][j], D[i][j]);
            preR[i][j] = preR[i + 1][j];
            add(preR[i][j], R[i][j]);
        }
    }
    cout << (D[1][1] + R[1][1]) % mod << endl;
    return 0;
}