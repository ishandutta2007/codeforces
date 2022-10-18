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

//int masks[31];
//map <int, int> dp;
//int solve(int mask){
//    if(mask == 0)return 0;
//    if(dp.count(mask))return dp[mask];
//
//    vector <int> v;
//    v.push_back(-1);
//    v.push_back(1 << 30);
//    
//    for(int i = 1; i < 30; i++)if(mask & (1 << (i - 1))){
//        v.push_back(solve(mask & ~masks[i]));
//    }
//    
//    sort(v.begin(), v.end());
//    for(int i = 1; i < v.size(); i++){
//        if(v[i] - v[i - 1] > 1)return dp[mask] = v[i - 1] + 1;
//    }
//}
int n, grundy[] = {0, 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4,
        7, 4, 2, 1, 10, 9, 3, 6, 11, 12, 12};
int main(){
//    freopen("a.out", "w", stdout);
//    for(int i = 1; i < 30; i++){
//        masks[i] = 0;
//        for(int j = i; j < 30; j += i)
//            masks[i] |= 1 << (j - 1);
//    }
//    for(int i = 0; i < 31; i++){
//        printf("%d ", solve((1 << i) - 1));
//    }
//    printf("\n");
    
    scanf("%d", &n);
    
    int res = 0, cnt = 0;
    for(int i = 2; i * i <= n; i++){
        int a = 0, x = i;
        for(int j = 2; j * j <= x; j++){
            int c = 0;
            while(x % j == 0){
                x /= j;
                c++;
            }
            a = __gcd(a, c);
        }
        if(x > 1)a = __gcd(a, 1);
        
        
        if(a == 1){
            long long y = i;
            int s = 0;
            while(y <= n){
                y *= i;
                s++;
            }
            
            cnt += s;
            res ^= grundy[s];
        }
    }
    
    res ^= (n - cnt) & 1;
    
    if(res == 0)printf("Petya\n");
    else printf("Vasya\n");
    
    return 0;
}