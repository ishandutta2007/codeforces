//In the name of Allah

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
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <assert.h>
#include <unordered_map>
using namespace std;

long long a, b;
int main(){
    scanf("%I64d %I64d", &a, &b);
    
    int res = 0;
    for(int d = 1; d <= 64; d++){
        long long c = 0;
        for(int i = 0; i < d; i++)
            c += 1LL << i;
        for(int i = 0; i + 1 < d; i++){
            if((a <= (c - (1LL << i))) && ((c - (1LL << i)) <= b)){
                res++;
            }
        }
    }
    printf("%d\n", res);
    
    return 0;
}