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
using namespace std;
int a, b, n;
int main(){
    scanf("%d %d %d", &a, &b, &n);
        
    for(int d = 0; d <= 9; d++){
        if((a * 10 + d) % b == 0){
            printf("%d%d", a, d);
            for(int i = 0; i < n - 1; i++)
                printf("0");
            printf("\n");
        
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}