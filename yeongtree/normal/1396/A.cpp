#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    long long A[n]; for(auto &i : A) cin >> i;
    cout << "1 1\n" << -A[0] << '\n'; A[0] = 0;
    if(n == 1)
    {
        cout << "1 1\n0\n1 1\n0\n";
        return 0;
    }
    cout << "2 " << n << '\n';
    for(int i = 1; i < n; ++i)
    {
        long long x = A[i] % n * (n - 1);
        cout << x << ' ';
        A[i] += x;
    }
    cout << '\n';
    cout << "1 " << n << '\n';
    for(int i = 0; i< n; ++i)
        cout << -A[i] << ' ';
}