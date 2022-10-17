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
        if(x == 1 && y > 1) cout << "NO\n";
        else if(x == 2 && y > 3) cout << "NO\n";
        else if(x == 3 && y > 3) cout << "NO\n";
        else cout << "YES\n";
    }
}