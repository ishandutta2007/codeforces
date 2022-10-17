#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int x, y; cin >> x >> y;
        if(y & 1) --y;
        if(y / 2 < x) cout << "-1 -1\n";
        else cout << y / 2 << ' ' << y << '\n';
    }
}