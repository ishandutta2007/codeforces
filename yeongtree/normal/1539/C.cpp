#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#define pii pair<int, int>
#define ff first
#define ss second

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; long long k, x; cin >> n >> k >> x;
    long long A[n]; for(int i = 0; i < n; ++i) cin >> A[i];
    sort(A, A + n);

    long long B[n - 1];
    for(int i = 0; i < n - 1; ++i) B[i] = max(0ll, (A[i + 1] - A[i] - 1) / x);
    sort(B, B + n - 1);

    for(int i = 0; i < n - 1; ++i)
    {
        if(k < B[i])
        {
            cout << n - i << '\n';
            return 0;
        }
        k -= B[i];
    }
    cout << 1;
}