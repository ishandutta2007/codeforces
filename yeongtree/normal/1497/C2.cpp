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
        n -= k - 3;
        for(int i = 3; i < k; ++i) cout << "1 ";

        bool flag = true;
        for(int i = 3; i * i <= n; i += 2) if(n % i == 0)
        {
            int m = n / i;
            cout << m << ' ' << m * (i / 2) << ' ' << m * (i / 2) << '\n';
            flag = false;
            break;
        }

        if(flag)
        {
            int m = 1;
            while(~n & 1) m <<= 1, n >>= 1;
            if(n == 1)
            {
                cout << m / 2 << ' ' << m / 4 << ' ' << m / 4 << '\n';
            }
            else
            {
                cout << m * (n / 2) << ' ' << m * (n / 2) << ' ' << m << '\n';
            }
        }
    }
}