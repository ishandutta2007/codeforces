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
#define MOD 1000000007
using namespace std;
int N, M, H, cur, A = 0, B = 0;
int main(){
    scanf("%d %d %d", &N, &M, &H);
    for(int i = 0; i < M; i++){
        scanf("%d", &cur);
        if(i == H - 1)A += cur;
        else B += cur;
    }
    if(N > A + B)printf("-1.0\n");
    else{
        double p = 1;
        A--;
        for(int i = 0; i < N - 1; i++, B--)
            p *= B * 1.0 / (B + A);
        printf("%.16f\n", 1.0 - p);
    }
    return 0;
}