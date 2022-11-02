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

int n, m, q;

const int maxn = 505;

char s[maxn][maxn];

string p = "RGYB";

int pre[4][maxn][maxn];

int val[maxn][maxn];

int sum(int x1, int y1, int x2, int y2, int k){
    return pre[k][x2][y2] + pre[k][x1][y1] - pre[k][x1][y2] - pre[k][x2][y1];
}

int dp[maxn][maxn][10][10];
int mm[maxn];

void init(){
    mm[0] = -1;
    for(int i = 1;i < maxn;i++){
        mm[i] = ((i & (i - 1)) == 0) ? mm[i - 1] + 1 : mm[i - 1];
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            dp[i][j][0][0] = val[i][j];
        }
    }
    for(int ii = 0;ii <= mm[n];ii++){
        for(int jj = 0;jj <= mm[m];jj++){
            if(ii+jj)
                for(int i = 1;i + (1 << ii) - 1 <= n;i++){
                    for(int j = 1;j + (1 << jj) - 1 <= m;j++){
                        if(ii) dp[i][j][ii][jj] = max(dp[i][j][ii - 1][jj], dp[i + (1 << (ii - 1))][j][ii - 1][jj]);
                        else dp[i][j][ii][jj] = max(dp[i][j][ii][jj - 1], dp[i][j + (1 << (jj - 1))][ii][jj - 1]);
                    }
                }
        }
    }
}

int rmq(int x1, int y1, int x2, int y2){
    int k1 = mm[x2 - x1 + 1];
    int k2 = mm[y2 - y1 + 1];
    x2 = x2 - (1 << k1) + 1;
    y2 = y2 - (1 << k2) + 1;
    return max(max(dp[x1][y1][k1][k2], dp[x1][y2][k1][k2]), max(dp[x2][y1][k1][k2], dp[x2][y2][k1][k2]));
}

int main(){
    cin >> n >> m >> q;
    for(int i = 1;i <= n;i++){
        scanf("%s", s[i] + 1);
        for(int j = 1;j <= m;j++){
            for(int k = 0;k < 4;k++){
                if(s[i][j] == p[k]){
                    pre[k][i][j]++;
                }
            }
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            for(int k = 0;k < 4;k++){
                pre[k][i][j] += pre[k][i - 1][j] + pre[k][i][j - 1] - pre[k][i - 1][j - 1];
            }
        }
    }
    for(int i = 1;i < n;i++){
        for(int j = 1;j < m;j++){
            if(s[i][j] == 'R' and s[i][j + 1] == 'G' and s[i + 1][j] == 'Y' and s[i + 1][j + 1] == 'B'){
                int l = 1, r = min(n, m);
                r = min(r, min(i, j));
                r = min(r, min(n - i, m - j));
                while(l < r){
                    int mid = (l + r + 1) / 2;
                    bool flag = true;
                    if(sum(i - mid, j - mid, i, j, 0) != mid * mid)
                       flag = false; 
                    if(sum(i - mid, j, i, j + mid, 1) != mid * mid)
                        flag = false;
                    if(sum(i, j - mid, i + mid, j, 2) != mid * mid)
                        flag = false;
                    if(sum(i, j, i + mid, j + mid, 3) != mid * mid)
                        flag = false;
                    if(flag){
                        l = mid;
                    }else{
                        r = mid - 1;
                    }
                }
                val[i][j] = l;
            } 
        }
    }
    init();
    for(int i = 1;i <= q;i++){
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if(x1 == x2 or y1 == y2){
            printf("0\n");
            continue;
        }
        if(rmq(x1, y1, x2 - 1, y2 - 1) == 0){
            printf("0\n");
            continue;
        }
        int l = 1, r = min(y2 - y1 + 1, x2 - x1 + 1) / 2;
        while(l < r){
            int mid = (l + r + 1) / 2;
            int r1 = x1 + mid - 1;
            int c1 = y1 + mid - 1;
            int r2 = x2 - mid;
            int c2 = y2 - mid;
            if(rmq(r1, c1, r2, c2) >= mid){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        printf("%lld\n", 4LL * l * l);
    }
    return 0;
}