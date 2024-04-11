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
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <string.h>
#include <assert.h>
#include <numeric>
#define MOD 1000000007
using namespace std;

int n;
char x[105];

int main(){
    scanf("%s", x);
    n = strlen(x);
    
    reverse(x, x + n);
    
    int curC = 0;
    long long p = 1;
    for(int i = 0; i < n; i++){
        if(x[i] == '0'){
            curC <<= 1;
            curC %= MOD;
        }else{
            curC <<= 1;
            curC %= MOD;
            
            curC += (p * p) % MOD;
            curC %= MOD;
        }
        
        p <<= 1;
        p %= MOD;
    }
    printf("%d\n", curC);
    return 0;
}