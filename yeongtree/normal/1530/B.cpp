#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n, m; cin >> n >> m;

        for(int j = 0; j < m; ++j)
        {
            if(j == 0 || j == m - 1 || (j % 2 == 0 && j != m - 2)) cout << 1;
            else cout << 0;
        }
        cout << '\n';

        for(int i = 1; i < n - 1; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if((j == 0 || j == m - 1) && (i == 0 || i == n - 1 || (i % 2 == 0 && i != n - 2))) cout << 1;
                else cout << 0;
            }
            cout << '\n';
        }

        for(int j = 0; j < m; ++j)
        {
            if(j == 0 || j == m - 1 || (j % 2 == 0 && j != m - 2)) cout << 1;
            else cout << 0;
        }
        cout << '\n';

        cout << '\n';
    }
}