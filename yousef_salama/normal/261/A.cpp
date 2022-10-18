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

int n, m, qi, a[100005];
int main(){
    scanf("%d", &m);
    
    int Min = 1 << 30;
    for(int i = 0; i < m; i++){
        scanf("%d", &qi);
        Min = min(Min, qi);
    }
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++)scanf("%d", &a[i]);
    sort(a, a + n);
    
    int res = 0;
    for(int i = n - 1, c = 0; i >= 0; i--){
        if(c == Min){
            c = 0;
            i--;
        }else{
            res += a[i];
            c++;
        }
    }
    printf("%d\n", res);
    
    return 0;
}