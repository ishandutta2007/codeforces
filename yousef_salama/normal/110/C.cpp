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
#define oo 1 << 25
using namespace std;
int main(){
//    freopen("a.in", "r", stdin);
    int N;
    scanf("%d", &N);
    for(int a = N / 7; a >= 0; a--)
        if((N - (a * 7)) % 4 == 0){
            int b = (N - (a * 7)) / 4;
            for(int i = 0; i < b; i++)
                printf("%d", 4);
            for(int i = 0; i < a; i++)
                printf("%d", 7);
            printf("\n");
            return 0;
        }
    printf("%d\n", -1);
    return 0;
}