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
int n, a[100005], c[100005];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)scanf("%d", &a[i]);
    
    int mn = *min_element(a, a + n);
    for(int i = 0; i < n; i++)a[i] -= mn;
    
    int mx = *max_element(a, a + n);
    if(mx > n){
        printf("NO\n");
        return 0;
    }
    
    for(int i = 0; i < n; i++)c[a[i]]++;
    
    int need_cover = c[0];
    for(int i = 1; i < mx; i++){
        if(c[i] > need_cover){
            need_cover = c[i] - need_cover;
        }else{
            printf("NO\n");
            return 0;
        }
    }
    
    if(need_cover == c[mx])printf("YES\n");
    else printf("NO\n");
    return 0;
}