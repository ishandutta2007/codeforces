#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int x, y, z; cin >> x >> y >> z;
        int ans = 0;
        while(x <= z && y <= z)
        {
            if(x < y) x += y;
            else y += x;
            ++ans;
        }
        cout << ans << '\n';
    }
}