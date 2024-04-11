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

int n, m, orders[1005], n_orders, ans[1005];
pair <int, int> a[45];
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d", &a[i].first);
        a[i].second = i;
    }
    int sum = 0;
    for(int i = 0; i < m; i++)
        sum += a[i].first;
    if(sum < n){
        printf("-1\n");
        return 0;
    }
    
    while(sum > n){
        sort(a, a + m);
        a[m - 1].first--;
        
        sum--;
    }
    
    for(int i = 0; i < m; i++)
        if(a[i].first * 2 > n){
            printf("-1\n");
            return 0;
        }
    
    n_orders = 0;
    for(int i = 0; i < n; i++)
        if(i % 2 == 0)orders[n_orders++] = i;
    for(int i = 0; i < n; i++)
        if(i % 2 == 1)orders[n_orders++] = i;
    
    sort(a, a + m);
    for(int i = m - 1, k = 0; i >= 0; i--){
        while(a[i].first > 0){
            ans[orders[k++]] = a[i].second;
            a[i].first--;
        }
    }
    
    for(int i = 0; i < n; i++){
        if(i > 0)printf(" ");
        printf("%d", ans[i] + 1);
    }
    printf("\n");
    return 0;
}