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
int n, k, a[205];
int main(){
    scanf("%d %d", &n, &k);
    for(int i = 0; i < (2 * n + 1); i++)scanf("%d", &a[i]);

    for(int i = 1; i < (2 * n + 1); i += 2){
        if(((a[i] - 1) > a[i - 1]) && ((a[i] - 1) > a[i + 1]))
            a[i]--, k--;
        if(k == 0)break;
    }
    for(int i = 0; i < (2 * n + 1); i++){
        if(i > 0)printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
    return 0;
}