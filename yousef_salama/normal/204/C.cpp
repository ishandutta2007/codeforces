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
#define MAXN 200005
using namespace std;
int n;
char a[MAXN], b[MAXN];
long long v[26];
int main(){
    scanf("%d %s %s", &n, a, b);

    long long total = 0;
    for(int k = 1; k <= n; k++){
        long long t = (n - k + 1);
        t = t * t;
        
        total += t;
    }
    
    double ans = 0;
    for(int i = 0; i < n; i++){
        v[b[i] - 'A'] += i + 1;
        
        double cur = v[a[i] - 'A'];
        cur *= n - i;
        cur /= total;
        
        ans += cur;
    }
    
    memset(v, 0, sizeof v);
    for(int i = n - 1; i >= 0; i--){
        double cur = v[a[i] - 'A'];
        cur *= i + 1;
        cur /= total;
        
        ans += cur;
        
        v[b[i] - 'A'] += n - i;
    }
    
    printf("%.9f\n", ans);
    return 0;
}