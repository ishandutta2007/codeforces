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
int d, sumT, minT[35], maxT[35], minS = 0, maxS = 0, ans[35];
int main(){
    scanf("%d %d", &d, &sumT);
    for(int i = 0; i < d; i++){
        scanf("%d %d", &minT[i], &maxT[i]);
        minS += minT[i];
        maxS += maxT[i];
    }
    if(!(minS <= sumT && sumT <= maxS))printf("NO\n");
    else{
        printf("YES\n");
        for(int i = 0; i < d; i++){
            ans[i] = minT[i];
            sumT -= minT[i];
        }
        for(int i = 0; i < d; i++){
            int x = min(maxT[i] - ans[i], sumT);
            ans[i] += x;
            sumT -= x;
        }
        for(int i = 0; i < d; i++){
            if(i != 0)printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}