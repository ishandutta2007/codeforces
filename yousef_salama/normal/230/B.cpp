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
int n;
bool p[1000005];
long long x[100005], v[1000005];
int main(){
    p[0] = p[1] = true;
    for(long long i = 2; i <= 1000000; i++){
        if(!p[i]){
            for(long long j = i * i; j <= 1000000; j += i)
                p[j] = true;
        }
    }
    for(long long f = 1; f <= 1000000; f++)
        v[f] = f * f;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        cin >> x[i];
        
        int sq = lower_bound(v, v + 1000000, x[i]) - v;
        if(v[sq] == x[i] && !p[sq])printf("YES\n");
        else printf("NO\n");
    }
}