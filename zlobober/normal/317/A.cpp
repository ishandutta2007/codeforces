#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long llong;

int main()
{
    llong x, y, m;
    cin >> x >> y >> m;
    if (x > y)
        swap(x, y);
    llong ans = 0;
    if (y >= m)
        ans = 0;
    else
    {
        if (y <= 0)
            ans = -1;
        else
        {
            ans = max(0LL, (-x + (y - 1)) / y);
            x += ans * y;
            if (x > y)
                swap(x, y);
            while (y < m)
            {
                x = x + y;
                swap(x, y);
                ans++;
            }
        }
    }
    cout << ans << endl;
}