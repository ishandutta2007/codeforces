#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int x, y, z; cin >> x >> y >> z;
        int k = min(min(x, y), z);
        int ans = k; x -= k; y -= k; z -= k;
        ans += min(min(x, y), (x + y) / 3);
        cout << ans << '\n';
    }

    return 0;
}