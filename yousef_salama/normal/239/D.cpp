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
#define MOD 1000000009
using namespace std;
int n, h, ans[100005];
pair <int, int> a[100005];
int main(){
    scanf("%d %d", &n, &h);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i].first);
        a[i].second = i;
    }
    sort(a, a + n);
    
    int w1 = (a[n - 1].first + a[n - 2].first) - (a[0].first + a[1].first);
    
    int p = a[0].first + a[1].first + h;
    if(n > 2)p = min(p, a[1].first + a[2].first);

    int q = a[n - 1].first + a[0].first + h;
    if(n > 2)q = max(q, a[n - 1].first + a[n - 2].first);
    
    int w2 = q - p;
    if(w1 < w2){
        for(int i = 0; i < n; i++)
            ans[i] = 1;
        
        printf("%d\n", w1);
        
        for(int i = 0; i < n; i++){
            if(i > 0)printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }else{
        ans[a[0].second] = 1;
        for(int i = 1; i < n; i++)
            ans[a[i].second] = 2;

        printf("%d\n", w2);
        
        for(int i = 0; i < n; i++){
            if(i > 0)printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}