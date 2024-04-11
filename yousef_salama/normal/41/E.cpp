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
int N;
int main(){
    scanf("%d", &N);
    printf("%d\n", (N / 2) * ((N + 1) / 2));
    for(int i = 1; i <= N / 2; i++)
    for(int j = N / 2 + 1; j <= N; j++)
        printf("%d %d\n", i, j);
    return 0;
}