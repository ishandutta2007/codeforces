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
#include <unordered_set>
using namespace std;

int n;
long long A, cf, cm, m, a[100005], a_[100005];
pair <long long, int> o_a[100005];
long long pref_sum[100005];

int main(){
    scanf("%d %I64d %I64d %I64d %I64d", &n, &A, &cf, &cm, &m);
    
    for(int i = 0; i < n; i++){
        scanf("%I64d", &a[i]);

        o_a[i] = make_pair(a[i], i);
    }
    sort(a, a + n);
    sort(o_a, o_a + n);

    pref_sum[0] = 0;
    for(int i = 1; i <= n; i++)
        pref_sum[i] = pref_sum[i - 1] + a[i - 1];

    long long r = 0, bY = 0;
    int bX = 0;

    for(int X = 0; X <= n; X++){
        long long L = 0, R = A;
        while(L < R){
            long long mid = (L + R + 1) / 2;
            
            int Y = min(n - X, upper_bound(a, a + n, mid) - a);
            long long s = mid * Y - pref_sum[Y]; 
            
            //if(mid == 3)cout << pref_sum[Y] << ' ' << Y << ' ' << s << endl;        

            if(s <= m)L = mid;
            else R = mid - 1;
        }
        if(cf * X + cm * L > r){
            //cout << m << ' ' << X << ' ' << L << endl;

            r = cf * X + cm * L;
            bX = X;
            bY = L;
        }
    
        if(X < n){
            m -= A - a[n - X - 1];
            if(m < 0)break;
            else a[n - X - 1] = A;
        }
    }

    for(int i = 0; i < bX; i++)
        a_[o_a[n - i - 1].second] = A;
    for(int i = bX; i < n; i++)
        a_[o_a[n - i - 1].second] = max(o_a[n - i - 1].first, bY);

    printf("%I64d\n", r);
    for(int i = 0; i < n; i++){
        if(i > 0)printf(" ");
        printf("%I64d", a_[i]);
    }
    printf("\n");


    return 0;
}