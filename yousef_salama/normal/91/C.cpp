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
#include <list>
#include <set>
#include <limits.h>
#include <limits>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <assert.h>
using namespace std;

#define MOD 1000000009

int n, m, ai, bi, p[100005];
int findr(int i){
    if(p[i] == i)return i;
    else return p[i] = findr(p[i]);
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)p[i] = i;

    int res = 1;
    while(m--){
        scanf("%d %d", &ai, &bi);
        ai--, bi--;

        if(findr(ai) == findr(bi)){
            res *= 2;
            res %= MOD;
        }else{
            p[findr(ai)] = findr(bi);
        }
        printf("%d\n", (res + MOD - 1) % MOD);
    }
    return 0;
}