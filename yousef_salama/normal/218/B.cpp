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
int n, m, a[1005], b[1005];
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++)scanf("%d", &a[i]);
    
    int ans1 = 0, ans2 = 0;
    for(int i = 0; i < m; i++)b[i] = a[i];
    for(int i = 0; i < n; i++){
        int Max = 0;
        for(int j = 0; j < m; j++)
            if(b[j] > b[Max])Max = j;
        
        ans1 += b[Max];
        b[Max]--;
    }
    for(int i = 0; i < m; i++)b[i] = a[i];
    for(int i = 0; i < n; i++){
        int Min = 0;
        for(int j = 0; j < m; j++)
            if(b[j] > 0 && (b[Min] == 0 || b[j] < b[Min]))Min = j;

        ans2 += b[Min];
        b[Min]--;
    }
    printf("%d %d\n", ans1, ans2);
    return 0;
}