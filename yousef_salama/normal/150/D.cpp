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
int L, a[155], dp[155][155], pal[155][155][155], des[155][155];
char s[155];
int destroy(int left, int right);
int palindrome(int left, int right, int d);

int destroy(int left, int right){
    if(right < left)return 0;
    
    int &ret = des[left][right];
    if(ret == -1){
        ret = -1 << 29;
        for(int d = 1; d <= (right - left + 1); d++)
            if(a[d - 1] != -1)ret = max(ret, palindrome(left, right, d) + a[d - 1]);
    }
    return ret;
}
int palindrome(int left, int right, int d){
    if(right < left)return 0;
    
    int &ret = pal[left][right][d];
    if(ret == -1){
        if(d == 0){
            ret = destroy(left, right);
        }else if(d == 1){
            ret = -1 << 29;
            for(int i = left; i <= right; i++)
                ret = max(ret, destroy(left, i - 1) + destroy(i + 1, right));
        }else{
            ret = -1 << 29;
            for(int i = left; right - i >= d; i++)
                ret = max(ret, destroy(left, i) + palindrome(i + 1, right, d));
            for(int i = right; i - left >= d; i--)
                ret = max(ret, palindrome(left, i - 1, d) + destroy(i, right));
            if(s[left] == s[right])ret = max(ret, palindrome(left + 1, right - 1, d - 2));
        }
    }
    return ret;
}
int solve(int left, int right){
    if(right < left)return 0;
    
    int &ret = dp[left][right];
    if(ret == -1){
        ret = destroy(left, right);
        for(int i = left; i <= right; i++)
            ret = max(ret, solve(left, i - 1) + solve(i + 1, right));
    }
    ret = max(ret, 0);
    return ret;
}
int main(){
    scanf("%d", &L);
    for(int i = 0; i < L; i++)
        scanf("%d", &a[i]);
    scanf("%s", &s);
    
    memset(dp, -1, sizeof dp);
    memset(pal, -1, sizeof pal);
    memset(des, -1, sizeof des);
    
    printf("%d\n", solve(0, L - 1));
    return 0;
}