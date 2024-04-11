#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    long long pow[40];
    pow[0] = 1; for(int i = 1; i < 40; ++i) pow[i] = 3 * pow[i - 1];

    int T; cin >> T;
    while(T--)
    {
        long long n; cin >> n;
        int exp[40];
        for(int i = 39; i >= 0; --i)
        {
            exp[i] = n / pow[i];
            n %= pow[i];
        }

        int pos = -1;
        for(int i = 0; i < 40; ++i)
            if(exp[i] == 2) pos = i;

        if(pos >= 0)
            for(int i = pos + 1; i < 40; ++i)
        {
            if(exp[i] == 0)
            {
                exp[i] = 1;
                for(int j = 0; j < i; ++j) exp[j] = 0;
                break;
            }
        }

        long long ans = 0;
        for(int i = 0; i < 40; ++i) ans += pow[i] * exp[i];
        cout << ans << '\n';
    }

    return 0;
}