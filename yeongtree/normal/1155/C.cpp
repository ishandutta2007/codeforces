#include <iostream>

using namespace std;

long long gcd(long long x, long long y)
{
    return (y == 0 ? x : gcd(y, x % y));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    long long arr[n], p[m];
    for(long long &i : arr) cin >> i;
    for(long long &i : p) cin >> i;

    long long sub[n - 1];
    for(int i = 0; i < n - 1; ++i) sub[i] = arr[i + 1] - arr[i];

    long long g = sub[0];
    for(int i = 1; i < n - 1; ++i) g = gcd(g, sub[i]);

    for(int i = 0; i < m; ++i)
    {
        if(g % p[i] == 0)
        {
            cout << "YES\n" << arr[0] << ' ' << i + 1;
            return 0;
        }
    }

    cout << "NO";
    return 0;
}