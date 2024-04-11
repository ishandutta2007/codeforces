#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 50;

int n;
pair<int, int> a[N];

bool check(int x, int y, int ox, int oy, int len)
{
    if ((x == ox || x == ox + len) && y >= oy && y <= oy + len)
        return true;
    else if ((y == oy || y == oy + len) && x >= ox && x <= ox + len)
        return true;
    else
        return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n; n = 4 * n + 1;
    for (int i = 1; i <= n; i++)
        cin >> a[i].fi >> a[i].se;
    for (int x = 0; x <= 50; x++)
        for (int y = 0; y <= 50; y++)
            for (int len = 1; len <= 50; len++)
            {
                int cnt = 0;
                for (int i = 1; i <= n; i++)
                    if (check(a[i].fi, a[i].se, x, y, len))
                        cnt++;
                if (cnt == n - 1)
                    for (int i = 1; i <= n; i++)
                        if (!check(a[i].fi, a[i].se, x, y, len))
                                return cout << a[i].fi << " " << a[i].se, 0;
            }
}