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

const int MAXN = 300005;

int n, a[MAXN], L[MAXN], R[MAXN];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)scanf("%d", &a[i]);
    
    for(int i = 0; i < n; i++){
        L[i] = i - 1;
        while(L[i] >= 0 && (a[L[i]] % a[i] == 0))L[i] = L[L[i]];
    }
    for(int i = n - 1; i >= 0; i--){
        R[i] = i + 1;
        while(R[i] < n && (a[R[i]] % a[i] == 0))R[i] = R[R[i]];
    }
    
    int res = -1;
    for(int i = 0; i < n; i++)
        res = max(res, R[i] - L[i] - 2);
    
    vector <int> v;
    for(int i = 0; i < n; i++)
        if(R[i] - L[i] - 2 == res)v.push_back(L[i] + 2);

    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());

    printf("%d %d\n", v.size(), res);
    for(int i = 0; i < v.size(); i++){
        if(i > 0)printf(" ");
        printf("%d", v[i]);
    }
    printf("\n");
    
    return 0;
}