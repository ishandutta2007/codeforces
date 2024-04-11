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
#include <string.h>
using namespace std;
int N, M, cnt[105], a, b;
int main(){
    scanf("%d %d", &N, &M);
    while(M--){
        scanf("%d %d", &a, &b);
        for(int i = a - 1; i <= b - 1; i++)
            cnt[i]++;
    }
    for(int i = 0; i < N; i++)
        if(cnt[i] != 1){
            printf("%d %d\n", i + 1, cnt[i]);
            return 0;
        }
    printf("OK\n");
    return 0;
}