#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
    int n; cin >> n;
    int a[n + 1], b[n + 1]; a[0] = b[0] = 0; for(int i = 1; i <= n; ++i) a[i] = b[i] = -1;
    for(int i = 0; i < 2 * n; ++i)
    {
        int x; cin >> x;
        if(a[x] == -1) a[x] = i;
        else b[x] = i;
    }

    long long ans = 0;
    for(int i = 0; i < n; ++i)
    {
        ans += min(abs(a[i+1] - a[i]) + abs(b[i+1] - b[i]) , abs(a[i+1] - b[i]) + abs(b[i+1] - a[i]));
    }

    cout << ans;
    return 0;
}