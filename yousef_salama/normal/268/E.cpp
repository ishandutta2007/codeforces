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
using namespace std;

const int MAXN = 50005;

int n, x, y;
pair <int, int> v[MAXN];

bool cmp(pair <int, int> a, pair <int, int> b){
    return (long long)a.first * b.second < (long long)a.second * b.first;
}
int main(){
    scanf("%d", &n);
    
    double total = 0;
    for(int i = 0; i < n; i++){
        scanf("%d %d", &x, &y);
        total += x;
        
        v[i].first = x * y;
        v[i].second = 100 - y;
    }
    sort(v, v + n, cmp);
    
    double sum_inverse = 0;
    for(int i = 0; i < n; i++){
        total += sum_inverse * v[i].first / 100.0;
        sum_inverse += v[i].second / 100.0;
    }
    printf("%.9f\n", total);
    
    return 0;
}