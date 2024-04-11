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
#define MAXN 1000005
using namespace std;

int c(char a){
    if(a == 'R')return 0;
    if(a == 'B')return 1;
    if(a == 'G')return 2;
}

char s1[MAXN], s2[MAXN];
int N, M, d1[3][3], d2[3][3], a1[MAXN], a2[MAXN];
int main(){
    scanf("%s %s", s1, s2);
    N = strlen(s1), M = strlen(s2);
    
    for(int i = 0; i < N; i++)a1[i] = c(s1[i]);
    for(int i = 0; i < M; i++)a2[i] = c(s2[i]);
    
    for(int i = 0; i < (N - 1); i++)
        d1[a1[i]][a1[i + 1]]++;
    for(int i = 0; i < (M - 1); i++)
        d2[a2[i]][a2[i + 1]]++;
    
    long long ans = (long long)N * M;
    for(int c1 = 0; c1 <= 2; c1++)
    for(int c2 = 0; c2 <= 2; c2++)
        if(c1 != c2)ans -= (long long)d1[c1][c2] * d2[c2][c1];

    int p2 = 0;
    for(int p1 = 0; p1 < (N - 1); p1++){
        if(p1 > 0)d1[a1[p1 - 1]][a1[p1]]--;
        
        if(p2 < M && a1[p1] == a2[p2]){
            ans -= N - p1 - 1;
            if(p2 > 0 && a2[p2 - 1] != a2[p2])
                ans += d1[a2[p2]][a2[p2 - 1]];
            
            p2++;
        }
    }
    
    int p1 = 0;
    for(int p2 = 0; p2 < (M - 1); p2++){
        if(p2 > 0)d2[a2[p2 - 1]][a2[p2]]--;
        
        if(p1 < N && a1[p1] == a2[p2]){
            ans -= M - p2 - 1;
            if(p1 > 0 && a1[p1 - 1] != a1[p1])
                ans += d2[a1[p1]][a1[p1 - 1]];
            
            p1++;
        }
    }
    
    printf("%I64d\n", ans);
    return 0;
}