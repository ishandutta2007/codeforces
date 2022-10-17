#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int a, b, c, d, k; cin >> a >> b >> c >> d >> k;
        int e = (a - 1) / c + 1;
        int f = (b - 1) / d + 1;
        if(k < e + f) cout << "-1\n";
        else cout << e << ' ' << f << '\n';
    }

    return 0;
}