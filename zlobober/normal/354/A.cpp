#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long llong;

const int N = 100500;
int A[N];
llong S[N];

int main()
{
    int n, l, r, ql, qr;
    scanf("%d %d %d %d %d", &n, &l, &r, &ql, &qr);
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]), S[i + 1] = S[i] + A[i];
    llong ans = 1e18;
    for (int i = 0; i <= n; i++)
    {
        llong v = S[i] * l + (S[n] - S[i]) * r + (max(0, abs(i - (n - i)) - 1)) * ((i > (n - i)) ? ql : qr);
        ans = min(ans, v);
    }
    cout << ans << endl;
}