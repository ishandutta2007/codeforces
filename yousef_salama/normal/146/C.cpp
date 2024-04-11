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
char a[100005], b[100005];
int ab = 0, ba = 0, N;
int main(){
    scanf("%s %s", &a, &b);
    N = strlen(a);
    for(int i = 0; i < N; i++){
        ab += a[i] == '4' && b[i] == '7';
        ba += a[i] == '7' && b[i] == '4';
    }
    printf("%d\n", max(ab, ba));
    return 0;
}