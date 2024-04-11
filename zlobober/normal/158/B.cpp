#include <iostream>
using namespace std;

const int T = 5;
int A[T];

int main()
{
    int n;
    cin >> n;
    int t;
    for (int i = 0; i < n; i++)
        cin >> t, A[t]++;
    int ans = 0;
    ans += A[4], A[4] = 0;
    A[1] -= min(A[1], A[3]);
    ans += A[3];
    int v = 2 * A[2] + A[1];
    ans += (v + 3) / 4;
    A[2] -= A[2], A[1] -= A[1];
    cout << ans;
    return 0;
}