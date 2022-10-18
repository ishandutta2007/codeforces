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
int N, x, y, d[100005];
int main(){
    scanf("%d", &N);
    memset(d, -1, sizeof d);
    for(int i = 0; i < N; i++){
        scanf("%d %d", &x, &y);
        int ans = 0;
        for(int k = 1; k * k <= x; k++)
            if(x % k == 0){
                if(i - y > d[k])ans++;
                if(i - y > d[x / k] && x / k != k)ans++;
                d[k] = d[x / k] = i;
            }
        printf("%d\n", ans);
    }
    return 0;
}