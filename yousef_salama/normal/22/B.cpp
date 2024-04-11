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
int N, M, ans = 0;
bool clean[26][26][26][26];
char g[26][26];
int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
        scanf("%s", &g[i]);
    for(int p1 = 0; p1 < N; p1++)
    for(int p2 = 0; p2 < M; p2++)
    for(int p3 = p1; p3 < N; p3++)
    for(int p4 = p2; p4 < M; p4++){
        clean[p1][p2][p3][p4] = (p3 - 1 >= p1?clean[p1][p2][p3 - 1][p4]:true)
                && (p4 - 1 >= p2?clean[p1][p2][p3][p4 - 1]:true) && (g[p3][p4] == '0');
        if(clean[p1][p2][p3][p4])
            ans = max(ans, 2 * ((p3 - p1 + 1) + (p4 - p2 + 1)));
    }
    printf("%d\n", ans);
    return 0;
}