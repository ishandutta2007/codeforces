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
#include <deque>
using namespace std;

int n, m, d, a[305], b[305], t[305];
long long dp_prev[150005], dp_now[150005];
int main(){
    scanf("%d %d %d", &n, &m, &d);
    for(int i = 1; i <= m; i++){
        scanf("%d %d %d", &a[i], &b[i], &t[i]);
        a[i]--;
    }
    a[0] = 0, b[0] = 0, t[0] = 0;
    
    for(int i = 0; i < n; i++)
        dp_prev[i] = 0;
    
    for(int j = m; j > 0; j--){
        for(int i = 0; i < n; i++)
            dp_prev[i] += b[j] - abs(a[j] - i);
        
        long long di = (long long)d * (t[j] - t[j - 1]);
        deque < pair <long long, int> > q;
        
        int p = 0;
        for(int i = 0; i < n; i++){
            while(p < n && abs(i - p) <= di){
                while(!q.empty() && q.back().first <= dp_prev[p])
                    q.pop_back();
                q.push_back(make_pair(dp_prev[p], p));
                p++;
            }
            
            while(!q.empty() && abs(i - q.front().second) > di)
                q.pop_front();

            dp_now[i] = q.front().first;
        }
        
        for(int i = 0; i < n; i++)dp_prev[i] = dp_now[i];
    }
    
    long long res = -(1LL << 60);
    for(int i = 0; i < n; i++)res = max(res, dp_prev[i]);
    
    printf("%I64d\n", res);
    
    return 0;
}