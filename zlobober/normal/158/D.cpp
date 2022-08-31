#include <iostream>
using namespace std;

const int N = 20500;
int A[N];

int n;

int B[N];

int get(int k)
{
    if (n / k < 3)
        return -1e9;
    for (int i = 0; i < k; i++)
        B[i] = 0;
    for (int i = 0; i < n; i++)
        B[i % k] += A[i];
    int ans = -1e9;
    for (int i = 0; i < k; i++)
        ans = max(ans, B[i]);
    return ans;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    int ans = -1e9;
    for (int k = 1; k * k <= n; k++)
        if (n % k == 0)
            ans = max(ans, max(get(k), get(n / k)));
    cout << ans;
    return 0;
}