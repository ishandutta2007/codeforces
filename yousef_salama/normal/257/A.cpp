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
int n, m, k;
int main(){
    scanf("%d %d %d", &n, &m, &k);
    
    vector <int> v(n);
    for(int i = 0; i < n; i++)scanf("%d", &v[i]);
    
    sort(v.rbegin(), v.rend());
    
    if(k >= m)printf("0\n");
    else{
        int cur = k, i = 0;
        for(; (i < n) && (cur < m); i++)
            cur += v[i] - 1;
        
        if(cur >= m)printf("%d\n", i);
        else printf("-1\n");
    }
    return 0;
}