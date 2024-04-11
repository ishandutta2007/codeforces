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

#define MOD 1000000007

int p, k;
bool vis[1000005];


void dfs(int i){
    vis[i] = true;
    
    int j = ((long long)k * i) % p;
    if(!vis[j])dfs(j);
}

int main(){
    scanf("%d %d", &p, &k);
    if(k == 1){
        long long res = 1;
        for(int i = 0; i < p; i++){
            res *= p;
            res %= MOD;
        }
        printf("%I64d\n", res);
    }else{
        long long res = 1;
        for(int i = 1; i < p; i++)if(!vis[i]){
            dfs(i);

            res *= p;
            res %= MOD;
        }
        printf("%I64d\n", res);
    }
    return 0;
}