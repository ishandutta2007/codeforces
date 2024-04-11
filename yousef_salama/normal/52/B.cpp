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
#include <cstring>
#include <sstream>
using namespace std;
int n, m, x[1005], y[1005];
char s[1005][1005];
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%s", s[i]);
        for(int j = 0; j < m; j++)
            if(s[i][j] == '*')x[i]++, y[j]++;
    }
    long long ans = 0;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
        ans += (s[i][j] == '*') * (x[i] - 1) * (y[j] - 1);
    printf("%I64d\n", ans);
    return 0;
}