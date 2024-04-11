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
using namespace std;
int r1, r2, c1, c2, d1, d2, cnt[10];
int main(){
    scanf("%d %d %d %d %d %d", &r1, &r2, &c1, &c2, &d1, &d2);
    for(int p1 = 1; p1 <= 9; p1++)
    for(int p2 = 1; p2 <= 9; p2++)
    for(int p3 = 1; p3 <= 9; p3++)
    for(int p4 = 1; p4 <= 9; p4++){
        memset(cnt, 0, sizeof cnt);
        cnt[p1]++; cnt[p2]++; cnt[p3]++; cnt[p4]++;
        if(cnt[p1] != 1 || cnt[p2] != 1 || cnt[p3] != 1 || cnt[p4] != 1)continue;
        if(p1 + p2 == r1 && p3 + p4 == r2 && p1 + p3 == c1 && p2 + p4 == c2 && p1 + p4 == d1 && p2 + p3 == d2){
            printf("%d %d\n%d %d\n", p1, p2, p3, p4);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}