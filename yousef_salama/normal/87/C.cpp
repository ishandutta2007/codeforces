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

int n, first_move[100005], dp[100005], mark[100005];

int main(){
    scanf("%d", &n);
    
    memset(mark, 0, sizeof mark);
    memset(first_move, -1, sizeof first_move);
    for(int x = 1; x <= n; x++){
        if(x <= 2){
            dp[x] = 0;
            continue;
        }
        
        for(int k = 2; (k * (k + 1) / 2) <= x; k++){
            int L = (2 * x - k * k + k) / (2 * k);
            int sum = (2 * L + k - 1) * k / 2;

            if(L >= 1 && sum == x){
                int y = 0;
                for(int i = L; i <= L + k - 1; i++)
                    y ^= dp[i];

                mark[y] = x;
                if(y == 0 && first_move[x] == -1)first_move[x] = k;
            }
        }
        
        int j = 0;
        while(mark[j] == x)j++;
        
        dp[x] = j;
    }
    
    if(dp[n] == 0)printf("-1\n");
    else printf("%d\n", first_move[n]);

    return 0;
}