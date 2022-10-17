#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        long long n; cin >> n; --n;
        int t = n % 3; n /= 3;
        long long l = 1;
        while(n >= l) n -= l, l <<= 2;
        long long m = 1;
        long long ans = 0;
        while(m < l)
        {
            switch(n & 3)
            {
            case 1:
                if(t == 0) ans += m;
                else if(t == 1) ans += m * 2;
                else ans += m * 3;
                break;
            case 2:
                if(t == 0) ans += m * 2;
                else if(t == 1) ans += m * 3;
                else ans += m;
                break;
            case 3:
                if(t == 0) ans += m * 3;
                else if(t == 1) ans += m;
                else ans += m * 2;
                break;
            }
            n >>= 2; m <<= 2;
        }
        if(t == 0) ans += m;
        else if(t == 1) ans += m * 2;
        else ans += m * 3;
        cout << ans << '\n';
    }
}