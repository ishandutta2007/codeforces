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

int n, m, qi, wi;
vector < pair <int, int> > v;

int calc(int x){
    if(x % 2 == 1 || x == 2)return x * (x - 1) / 2 + 1;
    else return x * (x - 1) / 2 + 1 + (x / 2 - 1);
}

int main(){
    scanf("%d %d", &n, &m);
    
    for(int i = 0; i < m; i++){
        scanf("%d %d", &qi, &wi);
        v.push_back(make_pair(wi, qi));
    }
    sort(v.rbegin(), v.rend());
    
    int x = 0;
    while(calc(x + 1) <= n)x++;
    
    long long cost = 0;
    for(int i = 0; (i < x) && (i < v.size()); i++)cost += v[i].first;
    
    printf("%I64d\n", cost);
    
    return 0;
}