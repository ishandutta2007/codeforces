#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long llong;
const int N = 300500;
int A[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    sort(A, A + n);
    reverse(A, A + n);
    llong ans = 0;
    for (int i = 0; i < n; i++)
        ans += min(n + 1 - i, n) * 1LL * A[i];
    cout << ans << endl;
}