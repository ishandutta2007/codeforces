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

const int MAXS = 6000000;

int L, R, p, primes[30], nprimes;
int all[MAXS], c_all, dp[MAXS];
bool possible[MAXS];

void find_all(int x, int i){
    all[c_all++] = x;
    
    while(i < nprimes){
        if((long long)x * primes[i] > R)break;
        find_all(x * primes[i], i);
        
        i++;
    }
}

int main(){
    nprimes = 0;
    for(int i = 2; i <= 100; i++){
        bool ok = true;
        for(int j = 2; j < i; j++)if(i % j == 0)
            ok = false;
        
        if(ok)primes[nprimes++] = i;
    }
    
    scanf("%d %d %d", &L, &R, &p);

    c_all = 0;
    find_all(1, 0);
    
    sort(all, all + c_all);
    
    memset(dp, 63, sizeof dp);
    memset(possible, false, sizeof possible);
    
    dp[0] = 0;
    possible[0] = true;

    for(int k = 2; k <= p; k++){
        int j = 0;
        for(int i = 0; i < c_all; i++){
            if(all[i] % k != 0)continue;
            
            while(all[j] * k < all[i])j++;
            dp[i] = min(dp[i], dp[j] + 1);
            
            if(dp[i] + k <= p)possible[i] = true;
        }
    }
    
    int res = 0;
    for(int i = 0; i < c_all; i++)if(all[i] >= L && possible[i])
        res++;
    printf("%d\n", res);
    
    return 0;
}