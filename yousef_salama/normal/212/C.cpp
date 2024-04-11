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

char s[105], sa[105];
int N;
long long dp[105][2];

long long solve(int i, char p){
    if(dp[i][p - 'A'] != -1)return dp[i][p - 'A'];

    if(i == N){
        if(p == 'B')return 1;
        else{
            if(s[i - 1] == 'A')return 1;
            else return 0;
        }
    }
    
    long long ret = 0;
    
    if(p == 'B'){
        if(s[i] == 'B')ret += solve(i + 1, 'B');
        ret += solve(i + 1, 'A');
    }else{
        if(s[i - 1] == 'A')ret += solve(i + 1, 'A');
        else{
            if(s[i] == 'A')ret += solve(i + 1, 'B');
        }
    }
    
    return dp[i][p - 'A'] = ret;
}

int main(){
    scanf("%s", s);
    N = strlen(s);
    
    long long res = 0;
    memset(dp, -1, sizeof dp);
    res += solve(1, 'A');
    
    for(int i = 1; i < N; i++)
        sa[i - 1] = s[i];
    sa[N - 1] = s[0];
    reverse(sa, sa + N);
    for(int i = 0; i < N; i++){
        if(sa[i] == 'A')s[i] = 'B';
        else s[i] = 'A';
    }
    
    memset(dp, -1, sizeof dp);
    res += solve(1, 'A');
    
    printf("%I64d\n", res);
    
    return 0;
}