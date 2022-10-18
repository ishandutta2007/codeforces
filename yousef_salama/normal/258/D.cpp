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
#define sz(v) ((int)(v.size()))
#define MAXN 1005
using namespace std;
int n, m, p[MAXN], ai, bi;
double A[MAXN][MAXN];
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%d", &p[i]);
    
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++){
        if(p[i] < p[j])A[i][j] = 1.0;
        else A[i][j] = 0.0;
    }
    
    while(m--){
        scanf("%d %d", &ai, &bi);
        ai--, bi--;
        if(ai > bi)swap(ai, bi);
        
        A[ai][bi] = (A[ai][bi] + A[bi][ai]) / 2;
        A[bi][ai] = A[ai][bi];
        for(int j = 0; j < n; j++)if(j != ai && j != bi){
            A[ai][j] = (A[ai][j] + A[bi][j]) / 2; A[bi][j] = A[ai][j];
            A[j][ai] = (A[j][ai] + A[j][bi]) / 2; A[j][bi] = A[j][ai];
        }
    }
    double res = 0;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < i; j++)
        res += A[i][j];
    printf("%.9f\n", res);
    return 0;
}