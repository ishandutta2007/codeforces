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
int n, a[2005][2005], r[2005], c[2005], r2[2005], c2[2005];
char s[2005][2005];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", s[i]);
        for(int j = 0; j < n; j++)
            a[i][j] = s[i][j] - '0';
    }
    int ans = 0;
    for(int i = n - 1; i >= 0; i--)
    for(int j = 0; j < i; j++)
        if(a[i][j] ^ r[i] ^ c[j]){
            ans++;
            r[i] ^= 1;
            c[j] ^= 1;
        }
    for(int i = 0; i < n - 1; i++)
    for(int j = n - 1; j > i; j--)
        if(a[i][j] ^ r2[i] ^ c2[j]){
            ans++;
            r2[i] ^= 1;
            c2[j] ^= 1;
        }
    for(int i = 0; i < n; i++)
        if(a[i][i] ^ r[i] ^ r2[i] ^ c[i] ^ c2[i])ans++;
    printf("%d\n", ans);
    return 0;
}