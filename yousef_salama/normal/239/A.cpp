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
int y, k, n;
int main(){
    scanf("%d %d %d", &y, &k, &n);
    
    bool found = false;
    for(int sum = 0; sum <= n; sum += k){
        int x = sum - y;
        if(x >= 1){
            if(found)printf(" %d", x);
            else{
                printf("%d", x);
                found = true;
            }
        }
    }
    if(!found)printf("-1");
    printf("\n");
    return 0;
}