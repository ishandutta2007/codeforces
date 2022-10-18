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
#define z 1000000000
using namespace std;
int a, b, MOD;
int main(){
    scanf("%d %d %d", &a, &b, &MOD);
    for(int x = 0; x <= MOD && x <= a; x++){
        int cur = ((long long)x * z) % MOD;
        if((MOD - cur) % MOD > b){
            printf("1 %.09d\n", x);
            return 0;
        }
    }
    printf("2\n");
    return 0;
}