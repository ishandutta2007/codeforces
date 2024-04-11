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
        int a, b, c, d; cin >> a >> b >> c >> d;
        int e = (c > d ? c - d : d - c);
        cout << min(a - 1, e + b) << '\n';
    }
}