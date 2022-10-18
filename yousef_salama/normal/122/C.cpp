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
int l, r, m;
long long lucky[5000];
void gen(int i, long long x){
    lucky[m++] = x;
    if(i < 10){
        gen(i + 1, x * 10 + 4);
        gen(i + 1, x * 10 + 7);
    }
}
int main(){
    scanf("%d %d", &l, &r);
    gen(1, 4), gen(1, 7);
    sort(lucky, lucky + m);

    int i = 0;
    while(lucky[i] < l)i++;
    
    long long ans = 0;
    while(lucky[i] <= r){
        if(i > 0 && lucky[i - 1] >= l)ans += (lucky[i] - lucky[i - 1]) * lucky[i];
        else ans += (lucky[i] - l + 1) * lucky[i];

        i++;
    }
    if(i > 0 && lucky[i - 1] >= l)ans += (r - lucky[i - 1]) * lucky[i];
    else ans += (r - l + 1) * lucky[i];
    
    printf("%I64d\n", ans);
    return 0;
}