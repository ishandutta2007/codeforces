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

int n, k[100005], a[100005];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d %d", &k[i], &a[i]);
    
    int ans = 0;
    for(int i = 0; i < n; i++){
        long long x = 4;
        int c = k[i] + 1;
        
        while(x < a[i]){
            c++;
            x *= 4;
        }
        ans = max(ans, c);
    }
    printf("%d\n", ans);
    return 0;
}