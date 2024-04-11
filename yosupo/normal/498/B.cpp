#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <random>
#include <complex>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <cassert>
 
using namespace std;
typedef long long ll;
typedef double ld;
//typedef long double ld;
const int MN = 5500;
int p[MN], l[MN];
ld dp[MN*2];
ld ndp[MN*2];
int main() {
    int n, t;
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", p+i, l+i);
    }
    for (int i = t+1; i < MN*2; i++) {
        dp[i] = -1;
    }
    for (int i = n-1; i >= 0; i--) {
//        for (int j = 0; j <= 2*t; j++) {
//            cout << (double)dp[j] << " ";
//        } cout << endl;
        ld pp = 1.0*p[i]/100; int ll = l[i];
        if (p[i] == 100 || ll == 1) {
            for (int j = 0; j <= t; j++) {
                dp[j] = 1+dp[j+1];
            }
            continue;
        }
        ndp[t] = 0;
        ld sump = 1;
        for (int k = 1; k < ll; k++) {
            sump *= (1-pp);
        }
        for (int j = t-1; j >= 0; j--) {
            ld u = ndp[j+1];
            u -= pp*sump/(1-pp)*(1+dp[j+1+ll-1]);
            u -= sump*(1+dp[j+1+ll]);
            u *= (1-pp);
            u += pp*(1+dp[j+1]);
            u += sump*(1+dp[j+ll]);
            ndp[j] = u;
        }
        memcpy(dp, ndp, sizeof(ld)*t);
    }
//    for (int j = 0; j <= 2*t; j++) {
//        cout << (double)dp[j] << " ";
//    } cout << endl;
    printf("%.20lf\n", (double)dp[0]);
    return 0;
}