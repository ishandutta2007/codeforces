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
long long j, ans[2], m0[2], A[100005][2];
int main(){
    cin >> n >> j >> m0[0] >> m0[1];
    for(int i = 0; i < n; i++){
        cin >> A[i][0] >> A[i][1];
        A[i][0] *= 2;
        A[i][1] *= 2;
    }

    if(j & 1)ans[0] = -m0[0], ans[1] = -m0[1];
    else ans[0] = m0[0], ans[1] = m0[1];

    if(((j - 1) / n) & 1){
        int p = (j - 1) % n, sign = 1;
        while(p >= 0){
            ans[0] += A[p][0] * sign;
            ans[1] += A[p][1] * sign;
            sign = sign == 1 ? -1 : 1;

            p--;
        }
        p = n - 1;
        while(p >= 0){
            ans[0] += A[p][0] * sign;
            ans[1] += A[p][1] * sign;
            sign = sign == 1 ? -1 : 1;

            p--;
        }
    }else{
        int p = (j - 1) % n, sign = 1;
        while(p >= 0){
            ans[0] += A[p][0] * sign;
            ans[1] += A[p][1] * sign;
            sign = sign == 1 ? -1 : 1;

            p--;
        }
    }
    cout << ans[0] << ' ' << ans[1] << endl;
    return 0;
}