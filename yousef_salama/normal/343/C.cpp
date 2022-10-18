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
#define MOD 1000000007
using namespace std;

int n, m;
long long hi[100005], pi[100005], X[100005], Y[100005];

long long cost(int i){
    return 2 * min(X[i], Y[i]) + max(X[i], Y[i]);
}
bool can(long long M){
    if(m == 0)return true;
    
    memset(X, 0, sizeof X);
    memset(Y, 0, sizeof Y);
    
    if(pi[0] < hi[0]){
        X[0] = hi[0] - pi[0];
        if(cost(0) > M)return false;
    }
    if(pi[m - 1] > hi[n - 1]){
        Y[n - 1] = pi[m - 1] - hi[n - 1];
        if(cost(n - 1) > M)return false;
    }
    
    int st = 0, en = 0;
    for(int i = 1; i < n; i++){
        while(st < m && pi[st] < hi[i - 1])st++;
        while(en < m && pi[en] < hi[i])en++;
        
        if(st == en)continue;
        
        int j;
        for(j = st; j < en; j++){
            int prY = Y[i - 1];
            Y[i - 1] = pi[j] - hi[i - 1];
            if(cost(i - 1) > M){
                Y[i - 1] = prY;
                break;
            }
        }
        
        if(j < en)X[i] = hi[i] - pi[j];
        if(cost(i) > M)return false;
    }
    return true;
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)scanf("%I64d", &hi[i]);
    for(int i = 0; i < m; ){
        scanf("%I64d", &pi[i]);
        if(binary_search(hi, hi + n, pi[i]))m--;
        else i++;
    }
    
    long long L = 0, R = 1LL << 60;
    while(L < R){
        long long M = (L + R) >> 1;
        
        if(can(M))R = M;
        else L = M + 1;
    }
    printf("%I64d\n", L);
    
    return 0;
}