#include <iostream>
#include <algorithm>

using namespace std;

struct X{int r, c, x;};

bool safe(X &a, X &b, X &c, X &d)
{
    if(a.c == b.c && b.c != c.c && c.c == d.c)
    {
        int x = (a.r > b.r ? a.r - b.r : b.r - a.r);
        int y = (c.r > d.r ? c.r - d.r : d.r - c.r);
        return !((x & 1) != (y & 1));
    }
    if(a.c == c.c && a.c != b.c && b.c == d.c)
        return safe(a, c, b, d);
    if(a.c == d.c && a.c != b.c && b.c == c.c)
        return safe(a, d, b, c);
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n, m; cin >> n >> m;
        X arr[n * m];
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
        {int k; cin >> k; arr[i * m + j] = X{i, j, k};}
        sort(arr, arr + n * m, [](X &x, X &y){return x.x > y.x;});

        if(n <= 3)
        {
            int ans = 0;
            for(int i = 0; i < n; ++i) ans += arr[i].x;
            cout << ans << '\n';
        }

        else
        {
            if(safe(arr[0], arr[1], arr[2], arr[3])) cout << arr[0].x + arr[1].x + arr[2].x + arr[3].x << '\n';
            else if(safe(arr[0], arr[1], arr[2], arr[4])) cout << arr[0].x + arr[1].x + arr[2].x + arr[4].x << '\n';
            else if(safe(arr[0], arr[1], arr[3], arr[4])) cout << arr[0].x + arr[1].x + arr[3].x + arr[4].x << '\n';
            else if(safe(arr[0], arr[2], arr[3], arr[4])) cout << arr[0].x + arr[2].x + arr[3].x + arr[4].x << '\n';
            else if(safe(arr[1], arr[2], arr[3], arr[4])) cout << arr[1].x + arr[2].x + arr[3].x + arr[4].x << '\n';
            else while(1);
        }
    }

    return 0;
}