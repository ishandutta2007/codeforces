#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n, k; cin >> n >> k;
        int A[n]; for(auto &i : A) cin >> i;
        for(int i = 0; i < n; ++i)
        {
            int t = min(k, A[i]);
            A[i] -= t;
            A[n - 1] += t;
            k -= t;
        }
        for(int i = 0; i < n; ++i) cout << A[i] << ' '; cout  << '\n';
    }
}