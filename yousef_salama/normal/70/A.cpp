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
#define MOD 1000003
using namespace std;
int N;
int main(){
    scanf("%d", &N);
    if(N == 0)printf("1\n");
    else{
        int ans = 1;
        for(int i = 0; i < N - 1; i++)
            ans = (ans * 3) % MOD;
        printf("%d\n", ans);
    }
    return 0;
}