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
#define MAXN 1000005
#define MOD 1000000007
using namespace std;
int n, k, sw[MAXN], sb[MAXN], sx[MAXN], a[MAXN], b[MAXN];
char s[MAXN];
int sum(int *a, int left, int right){
    return a[right + 1] - a[left];
}
int main(){
    scanf("%d %d %s", &n, &k, s);
    
    sw[0] = 0;
    for(int i = 1; i <= n; i++)
        sw[i] = sw[i - 1] + (s[i - 1] == 'W');
    sb[0] = 0;
    for(int i = 1; i <= n; i++)
        sb[i] = sb[i - 1] + (s[i - 1] == 'B');
    sx[0] = 0;
    for(int i = 1; i <= n; i++)
        sx[i] = sx[i - 1] + (s[i - 1] == 'X');
    
    a[0] = 1;
    for(int i = 1; i <= n; i++){
        if(s[i - 1] != 'B')a[i] = (a[i] + a[i - 1]) % MOD;
        if(s[i - 1] != 'W'){
            a[i] = (a[i] + a[i - 1]) % MOD;
            if(i < k)continue;
            
            if(i == k){
                if(sum(sw, 0, i - 1) == 0)
                    a[i] = (a[i] - 1 + MOD) % MOD;
            }else{
                if(sum(sw, i - k, i - 1) == 0 && s[i - k - 1] != 'B')
                    a[i] = (a[i] - a[i - k - 1] + MOD) % MOD;
            }
        }
    }
    b[n] = 1;
    for(int i = n - 1; i >= 0; i--){
        if(s[i] != 'W')b[i] = (b[i] + b[i + 1]) % MOD;
        if(s[i] != 'B'){
            b[i] = (b[i] + b[i + 1]) % MOD;
            if(n - i < k)continue;
            
            if(n - i == k){
                if(sum(sb, i, n - 1) == 0)
                    b[i] = (b[i] - 1 + MOD) % MOD;
            }else{
                if(sum(sb, i, i + k - 1) == 0 && s[i + k] != 'W')
                    b[i] = (b[i] - b[i + k + 1] + MOD) % MOD;
            }
        }
    }
    long long ans = 0, r = 0;
    for(int i = n - 1; i >= 0; i--){
        if(i + 1 >= k){
            long long x = 0;
            if(i + 1 == k){
                if(sum(sw, 0, i) == 0)x = 1;
            }else{
                if(sum(sw, i - k + 1, i) == 0 && s[i - k] != 'B')
                    x = a[(i + 1) - k - 1];
            }
            ans = (ans + r * x) % MOD;
        }
        
        //update r
        if(s[i] == 'X')r = (r * 2) % MOD;
        if(n - i >= k){
            long long x = 0;
            if(n - i == k){
                if(sum(sb, i, n - 1) == 0)x = 1;
            }else{
                if(sum(sb, i, i + k - 1) == 0 && s[i + k] != 'W')
                    x = b[i + k + 1];
            }
            r = (r + x) % MOD;
        }
    }
    printf("%I64d\n", ans);
}