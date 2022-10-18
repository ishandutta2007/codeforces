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
int k, a[15];
bool rev(int i, int j){
    return i > j;
}
int main(){
    scanf("%d", &k);
    for(int i = 0; i < 12; i++)
        scanf("%d", &a[i]);
    sort(a, a + 12, rev);
    for(int i = 0; i < 12; i++){
        if(k <= 0){
            printf("%d\n", i);
            return 0;
        }
        k -= a[i];
    }
    if(k <= 0)printf("%d\n", 12);
    else printf("-1\n");
    return 0;
}