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
int n, m, k, xi, a[100005], b[100005], c[100005];
int main(){
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < m; i++)
        scanf("%d %d %d", &a[i], &b[i], &c[i]);
    long long sum = 0;
    while(k--){
        scanf("%d", &xi);
        
        long long x = 0;
        for(int i = 0; i < m; i++){
            if(a[i] <= xi && xi <= b[i])
                x += xi - a[i] + c[i];
        }
        sum += x;
    }
    printf("%I64d\n", sum);
    return 0;
}