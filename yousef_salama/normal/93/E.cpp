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

long long n;
int k, a[105], mem[100005][105];

long long calc(long long i, int j){
    if(j == k)return i;
    if(i <= 100000 && mem[i][j] != -1)return mem[i][j];
    
    long long ret = calc(i, j + 1) - calc(i / a[j], j + 1);
    if(i <= 100000)mem[i][j] = ret;
    
    return ret;
}
int main(){
    scanf("%I64d %d", &n, &k);
    for(int i = 0; i < k; i++)
        scanf("%d", &a[i]);
    sort(a, a + k);
    reverse(a, a + k);
    
    memset(mem, -1, sizeof mem);
    printf("%I64d\n", calc(n, 0));
    return 0;
}