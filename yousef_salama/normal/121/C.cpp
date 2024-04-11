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
int n, k, num, lucky[2005], perm[25];
bool v[25];
long long fact[25];
void gen(long long cur){
    if(cur > 1000000000)return;
    lucky[num++] = cur;
    gen(cur * 10 + 4);
    gen(cur * 10 + 7);
}
int main(){
    scanf("%d %d", &n, &k);
    k--;

    fact[0] = 1;
    for(int i = 1; i <= 20; i++)
        fact[i] = fact[i - 1] * i;
    if(k >= fact[min(n, 20)]){
        printf("-1\n");
        return 0;
    }
    gen(4), gen(7);
    
    int m = min(n, 20);
    for(int i = n - m; i < n; i++){
        int j;
        for(j = n - m; j < n; j++)
            if(!v[j - (n - m)]){
                if(k >= fact[m - (i - (n - m)) - 1])k -= fact[m - (i - (n - m)) - 1];
                else break;
            }
        perm[i - (n - m)] = j + 1;
        v[j - (n - m)] = true;
    }
    int ans = 0;
    for(int i = 0; i < num; i++)
        if(lucky[i] <= (n - m))
            ans++;
    sort(lucky, lucky + num);
    for(int i = 1; i <= m; i++)
        if(binary_search(lucky, lucky + num, i + (n - m)) && binary_search(lucky, lucky + num, perm[i - 1]))
            ans++;
    printf("%d\n", ans);
    return 0;
}