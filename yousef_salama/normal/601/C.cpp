//In the name of Allah

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <limits.h>
#include <limits>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <assert.h>
using namespace std;

int n, m, x[105];
double sum[2][100005], dp[2][100005];
int main(){
    scanf("%d %d", &n, &m);
    
    int s_x = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &x[i]);
        s_x += x[i];
    }
    
    if(m == 1){
        printf("%.16f\n", 1.0);
        return 0;
    }
    
    for(int i = 0; i <= n; i++){
        for(int s = 0; s <= s_x; s++){
            if(i == 0){
                if(s == 0)dp[i & 1][s] = 1.0;
                else dp[i & 1][s] = 0.0;
            }else{
                if(s < i){
                    dp[i & 1][s] = 0.0;
                }else{    
                    dp[i & 1][s] = sum[(i - 1) & 1][s - 1];
                    if(s - m - 1 >= 0)dp[i & 1][s] -= sum[(i - 1) & 1][s - m - 1];
                    if(s - x[i - 1] >= 0)dp[i & 1][s] -= dp[(i - 1) & 1][s - x[i - 1]];
                    
                    dp[i & 1][s] *= 1.0 / (m - 1);
                }
            }
            
            sum[i & 1][s] = dp[i & 1][s];
            if(s > 0)sum[i & 1][s] += sum[i & 1][s - 1];
            
            //cout << dp[i & 1][s] << ' ';
        }
        //cout << endl;
    }
    
    double res = 0.0;
    for(int s = 0; s < s_x; s++)res += dp[n & 1][s];
    
    printf("%.16f\n", res * (m - 1) + 1);
    
    return 0;
}