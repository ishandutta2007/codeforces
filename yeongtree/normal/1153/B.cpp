#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, h; cin >> n >> m >> h;
    int y[m], x[n]; for(int &i : y) cin >> i; for(int &i : x) cin >> i;
    bool top[n][m]; for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) cin >> top[i][j];

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(top[i][j]) cout << min(x[i], y[j]);
            else cout << '0';
            cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}