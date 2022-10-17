#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        for(int i = 0; i < n; ++i)
        {
            int x; cin >> x; if(x < 0) x = -x;
            if(i & 1) cout << -x << ' ';
            else cout << x << ' ';
        }
        cout << '\n';
    }
}