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

const int MAXN = 1000005;
int A, B, n, l, t, m;
long long s[MAXN], x[MAXN];
int main(){
    scanf("%d %d %d", &A, &B, &n);
    
    s[0] = A;
    x[0] = A;
    for(long long i = 1; i < MAXN; i++){
        s[i] = s[i - 1] + A + i * B;
        x[i] = A + i * B;
    }
    /*
    t = 5, m = 3;
    bool ok1 = true;
    if(x[3] > t)ok1 = false;
    if(s[3] - (0 > 0 ? s[0] : 0) > (long long)m * t)ok1 = false;
    
    cout << ok1 << endl;
    */
    while(n--){
        scanf("%d %d %d", &l, &t, &m);
        l--;
        
        int L = l, r = MAXN - 1;
        while(l < r){
            int mid = (l + r + 1) / 2;
            
            bool ok = true;
            if(x[mid] > t)ok = false;
            if(s[mid] - (L > 0 ? s[L - 1] : 0) > (long long)m * t)ok = false;
            
            
            if(ok)l = mid;
            else r = mid - 1;
        }
        
        if(r == l){
            if(x[l] > t)printf("-1\n");
            else printf("%d\n", r + 1);
        }else printf("-1\n");
    }
    return 0;
}