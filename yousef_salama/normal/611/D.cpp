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
#include <unordered_map>
using namespace std;

#define MOD 1000000007

int n, b[5005], non_zero[5005], nxt[5005][5005], dp[5005][5005];
char s[5005];
int main(){
    scanf("%d %s", &n, s);
    
    for(int len = 1; len <= n; len++){
        for(int i = 0; i < n; i++)
            if(i - len >= 0)b[i] = s[i] - s[i - len];
        
        non_zero[n] = -1;
        for(int i = n - 1; i >= 0; i--){
            if(b[i] == 0)non_zero[i] = non_zero[i + 1];
            else non_zero[i] = i;
        }
        
        /*if(len == 1){
            for(int i = 0; i < n; i++)
                cout << b[i] << ' ';
            cout << endl;
            for(int i = 0; i <= n; i++)
                cout << non_zero[i] << ' ';
            cout << endl;
        }*/

        for(int i = 0; i < n; i++){
            if(i + len > n)break;
            
            int j = i + len - 1;
            
            nxt[i][j] = -1;
            if((j + 1) + (len + 1) <= n)
                nxt[i][j] = (j + 1) + (len + 1) - 1;
            
            if(non_zero[j + 1] != -1)
            if(non_zero[j + 1] <= (j + 1) + len - 1)
            if(b[non_zero[j + 1]] > 0)
                nxt[i][j] = (j + 1) + len - 1;
        }
    }   

    for(int i = n - 1; i >= 0; i--)
    for(int j = n - 1; j >= i; j--){
        if(s[i] == '0')dp[i][j] = 0;
        else{
            if(j == (n - 1))dp[i][j] = 1;
            else{
                dp[i][j] = dp[i][j + 1];
                if(nxt[i][j] != -1){
                    dp[i][j] += dp[j + 1][nxt[i][j]];
                    dp[i][j] %= MOD;
                }
            }
        }
    }
    printf("%d\n", dp[0][0]);

    return 0;
}