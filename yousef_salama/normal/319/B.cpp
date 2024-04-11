//In the name of Allah

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

int n, a[100005], p[100005];

int g(int i, int j){
    if(i > j)return 0;
    if(i == j)return 1;
    return max(g(i, p[j]), g(p[j] + 1, j - 1) + 1);
}
int f(int i, int j){
    if(i >= j)return 0;
    if(p[j] < i)return f(i, j - 1);
    return max(f(i, p[j]), g(p[j] + 1, j - 1) + 1);
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    for(int i = 0; i < n; i++){
        p[i] = i - 1;
        while(p[i] >= 0 && a[p[i]] <= a[i])p[i] = p[p[i]];
    }
    printf("%d\n", f(0, n - 1));
    
    return 0;
}