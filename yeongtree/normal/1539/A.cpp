#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int a, b, c; cin >> a >> b >> c;
        int d = c / b;
        if(a < d) cout << 1ll * a * (a - 1) / 2 << '\n';
        else cout << 1ll * (a - d) * d + 1ll * d * (d - 1) / 2 << '\n';
    }
}