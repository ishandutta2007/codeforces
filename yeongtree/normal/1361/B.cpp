#include <iostream>
#include <algorithm>

using namespace std;

const int Q = (int)1e9 + 7;
const int MAX = 2e6;

bool ex;
int __pow(long long a, int p)
{
    long long ans = 1;
    while(p)
    {
        if(p & 1)
        {
            ans *= a;
            if(ans > MAX) ex = true;
            ans %= Q;
        }

        a *= a;
        if(a > MAX) ex = true;
        a %= Q;

        p >>= 1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n, p; cin >> n >> p;
        int arr[n]; for(auto &i : arr) cin >> i;
        if(p == 1)
        {
            cout << (n & 1) << '\n';
        }
        else
        {
            ex = false;
            sort(arr, arr + n, greater<int>());
            int pr = arr[0];
            long long ans = 0;
            for(auto i : arr)
            {
                if(ans)
                {
                    ans *= __pow(p, pr - i);
                    if(ans > MAX) ex = true;
                    ans %= Q;
                }
                pr = i;

                if(ex || ans) ans = (ans + Q - 1) % Q;
                else ++ans;
            }
            ans *= __pow(p, pr);
            ans %= Q;
            cout << ans << '\n';
        }
    }
}