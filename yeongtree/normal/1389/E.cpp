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
        int m, d, w; cin >> m >> d >> w;
        w /= __gcd(w, d - 1);
        int x = min(m, d);
        int y = x / w;
        int z = x % w;
        cout << 1ll * y * (y - 1) / 2 * (w - z) + 1ll * (y + 1) * y / 2 * z << '\n';
    }
}