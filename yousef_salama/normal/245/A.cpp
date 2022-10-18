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
using namespace std;
int n, ti, ai, bi;
int main(){
    scanf("%d", &n);
    
    int allA = 0, allB = 0, corrA = 0, corrB = 0;
    while(n--){
        scanf("%d %d %d", &ti, &ai, &bi);
        if(ti == 1){
            allA += 10;
            corrA += ai;
        }else{
            allB += 10;
            corrB += ai;
        }
    }
    if(corrA * 2 >= allA)printf("LIVE\n");
    else printf("DEAD\n");
    
    if(corrB * 2 >= allB)printf("LIVE\n");
    else printf("DEAD\n");
    return 0;
}