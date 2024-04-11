#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int n,q,c;
const int maxn = 1e5 + 5;
int x[maxn],y[maxn];
int s[maxn];
int b[105][105][15];

int sum[105][105][15];
int cal(int x1,int y1,int x2,int y2,int t){
    x1--;y1--;
    t = t % c;
    return sum[x2][y2][t] + sum[x1][y1][t] - sum[x2][y1][t] - sum[x1][y2][t];
}
int main(){
    while(cin >> n >> q >> c){
        memset(b,0,sizeof(b));
        c++;
        for(int i = 1;i <= n;i++){
            scanf("%d%d%d",&x[i],&y[i],&s[i]);
            for(int j = 0;j < c;j++){
                b[x[i]][y[i]][j] += (s[i] + j) % c;
            }
        }
        for(int i = 1;i <= 100;i++){
            for(int j = 1;j <= 100;j++){
                for(int t = 0;t <= 11;t++)
                sum[i][j][t] = sum[i][j - 1][t] + b[i][j][t];
            }
        }
        for(int i = 1;i <= 100;i++){
            for(int j = 1;j <= 100;j++){
                for(int t = 0;t <= 11;t++){
                    sum[i][j][t] += sum[i - 1][j][t];
                }
            }
        }
        for(int i = 1;i <= q;i++){
            int t,x1,y1,x2,y2;
            scanf("%d%d%d%d%d",&t,&x1,&y1,&x2,&y2);
            printf("%d\n",cal(x1,y1,x2,y2,t));
        }
    }
    return 0;
}