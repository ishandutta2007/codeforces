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
int n, d, a[100005];
int main(){
    scanf("%d %d", &n, &d);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    long long ans = 0;
    for(int i = 0; i < n; i++){
        int j = upper_bound(a + (i + 1), a + n, a[i] + d) - a;

        long long t = j - i - 1;
        ans += t * (t - 1) / 2;
    }
    printf("%I64d\n", ans);
    return 0;
}