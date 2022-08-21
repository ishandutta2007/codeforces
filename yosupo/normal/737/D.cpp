#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }


const int MN = 4040;
int n;
int a[MN];
int aS[MN], bS[MN];

int dp1[2][MN][MN], dp2[2][MN][MN];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
/*    n = 4000;
    for (int i = 0; i < n; i++) {
        a[i] = 2;
    }*/
    aS[0] = 0;
    for (int i = 0; i < n; i++) {
        aS[i+1] = a[i] + aS[i];
    }
    bS[n] = 0;
    for (int i = n-1; i >= 0; i--) {
        bS[i] = a[i] + bS[i+1];
    }

    for (int k = 90; k >= 1; k--) {
        for (int d = 0; d < k; d++) {
            int L = max(0, (n-d-100)/2);
            int R = min(n-d, (n-d+100)/2);
            for (int l = L; l <= R; l++) {
                int r = l+d;
                dp1[0][l][r] = dp1[1][l][r] = aS[l]-bS[r];
            }
        }
        {
            int d = k;
            for (int l = 0; l+d <= n; l++) {
                int r = l+d;
                dp1[0][l][r] = dp1[1][l+k][r];
                dp1[1][l][r] = dp1[0][l][r-k];
            }
        }
        for (int d = k+1; d <= n; d++) {
            int L = max(0, (n-d-100)/2);
            int R = min(n-d, (n-d+100)/2);
            for (int l = L; l <= R; l++) {
                int r = l+d;
                dp1[0][l][r] = dp1[1][l+k][r];
                dp1[1][l][r] = dp1[0][l][r-k];
                if (k+1 <= d) {
                    dp1[0][l][r] = max(dp1[0][l][r], dp2[1][l+(k+1)][r]);
                    dp1[1][l][r] = min(dp1[1][l][r], dp2[0][l][r-(k+1)]);
                }
            }
        }
        for (int d = 0; d <= n; d++) {
            int L = max(0, (n-d-100)/2);
            int R = min(n-d, (n-d+100)/2);
            for (int l = L; l <= R; l++) {
                int r = l+d;
                dp2[0][l][r] = dp1[0][l][r];
                dp2[1][l][r] = dp1[1][l][r];
            }
        }
    }

    cout << dp2[0][0][n] << endl;
    return 0;
}