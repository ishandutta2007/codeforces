#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <bitset>
#include <vector>
#include <queue>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <unordered_map>
#include <list>
#include <set>
using namespace std;

const int maxn = 55;

double dp[maxn][maxn * 100];

int N,R;
int F[maxn],S[maxn];
double P[maxn];

int main(){
    cin >> N >> R;
    for(int i = 1;i <= N;i++){
        scanf("%d%d",&F[i],&S[i]);
        int p;
        scanf("%d",&p);
        P[i] = p / 100.0;
    }
    double l = 0,r = 1e18;
    for(int t = 1;t <= 100;t++){
        double mid = (l + r) / 2;
        memset(dp,0,sizeof(dp));
        for(int i = N;i >= 1;i--){
            for(int j = 0;j <= R;j++){
                if(j + F[i] <= R){
                    double tmp = (F[i] + dp[i + 1][j + F[i]]) * P[i];
                    if(j + S[i] <= R){
                        tmp += (S[i] + dp[i + 1][j + S[i]]) * (1 - P[i]);
                    }else{
                        tmp += (S[i] + mid) * (1 - P[i]);
                    }
                    dp[i][j] = min(mid,tmp);
                }else{
                    dp[i][j] = mid;
                }
            }
        }
        if(dp[1][0] < mid){
            r = mid;
        }else{
            l = mid;
        }
    }
    printf("%.15lf\n",(l + r) / 2);
    return 0;
}