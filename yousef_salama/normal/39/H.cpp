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
int k;
int main(){
    scanf("%d", &k);
    for(int i = 1; i < k; i++){
        for(int j = 1; j < k; j++){
            if(j != 1)printf(" ");
            int t = i * j, p = 0, s = 1;
            while(t > 0){
                p += (t % k) * s;
                t /= k;
                s *= 10;
            }
            printf("%d", p);
        }
        printf("\n");
    }
    return 0;
}