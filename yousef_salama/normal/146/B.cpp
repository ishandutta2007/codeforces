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
int a, b, i;
int mask(int k){
    int temp = 0, shift = 1;
    while(k > 0){
        int cur = k % 10;
        if(cur == 4 || cur == 7){
            temp += shift * cur;
            shift *= 10;
        }
        k /= 10;
    }
    return temp;
}
int main(){
    scanf("%d %d", &a, &b);
    for(i = a + 1; ; i++)
        if(mask(i) == b)break;
    printf("%d\n", i);
    return 0;
}