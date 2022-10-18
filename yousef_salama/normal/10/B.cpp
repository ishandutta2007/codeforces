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
bool empty[101][101][101];
int sum[101][101];
int N, K, M;
int main(){
    scanf("%d %d", &N, &K);
    for(int i = 0; i < K; i++)
    for(int j = 0; j < K; j++)
    for(int k = 0; k < K; k++)
        empty[i][j][k] = 1;
    for(int i = 0; i < K; i++)
    for(int p1 = 0; p1 < K; p1++)
        sum[i][p1] = (p1 > 0?sum[i][p1 - 1]:0) + (abs((i + 1) - ((K + 1) / 2)) +
                        abs((p1 + 1) - ((K + 1) / 2)));
    while(N--){
        scanf("%d", &M);
        int a1 = -1, a2, a3;
        for(int i = 0; i < K; i++)
        for(int p1 = 0; p1 + M - 1 < K; p1++){
            int p2 = p1 + M - 1;
            if(empty[i][p1][p2]){
                if(a1 == -1 ||
                        sum[i][p2] - (p1 > 0?sum[i][p1 - 1]:0) < sum[a1][a3] - (a2 > 0?sum[a1][a2 - 1]:0)
                        || ((sum[i][p2] - (p1 > 0?sum[i][p1 - 1]:0) ==
                        sum[a1][a3] - (a2 > 0?sum[a1][a2 - 1]:0)) && i < a1)){
                    a1 = i;
                    a2 = p1;
                    a3 = p2;
                }
            }
        }
        if(a1 == -1)
            printf("-1\n");
        else{
            printf("%d %d %d\n", a1 + 1, a2 + 1, a3 + 1);
            for(int p1 = 0; p1 < K; p1++)
            for(int p2 = p1; p2 < K; p2++)
                if(!(p2 < a2 || p1 > a3))empty[a1][p1][p2] = false;
        }
    }
    return 0;
}