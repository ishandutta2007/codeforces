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
int N, a, b, c, ans = 0;
int main(){
    scanf("%d %d %d %d", &N, &a, &b, &c);
    N <<= 1;
    for(int i = 0; i <= a; i++)
    for(int j = 0; j <= b; j++)
        if(N >= (i + 2 * j) && (N - (i + 2 * j)) % 4 == 0 && (N - (i + 2 * j)) / 4 <= c)
            ans++;
    printf("%d\n", ans);
    return 0;
}