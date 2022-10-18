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
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <assert.h>
using namespace std;

int n, k;
pair <int, int> x[300005];

long long sum = 0, sum_total = 0, sz = 0;
long long ans_ending[300005];

void add(int i){
    sum_total += (long long)x[i].first * sz;
    sum_total -= sum;
    
    sum += x[i].first;
    sz++;
}

void remove(int i){
    sum_total -= sum;
    sum_total += (long long)x[i].first * sz;
    
    sum -= x[i].first;
    sz--;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &x[i].first);
        x[i].second = i;
    }
    sort(x, x + n);
    
    scanf("%d", &k);
    
    int j = 0;
    for(int i = 0; i < n; i++){
        add(i);
        while(sz > k){
            remove(j);
            j++;
        }
        
        if(sz == k)ans_ending[i] = sum_total;
    }
    
    int best = min_element(ans_ending + (k - 1), ans_ending + n) - ans_ending;
    for(int i = best - k + 1; i <= best; i++){
        printf("%d", x[i].second + 1);
        if(i < best)printf(" ");
    }
    printf("\n");
    
    return 0;
}