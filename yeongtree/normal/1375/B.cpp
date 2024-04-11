#include <iostream>

using namespace std;

int arr[1000][1000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n, m; cin >> n >> m;
        for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) cin >> arr[i][j];
        bool flag = false;
        for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j)
        {
            bool a = i == 0 || i == n - 1;
            bool b = j == 0 || j == m - 1;
            if(a && b)
            {
                if(arr[i][j] > 2)
                {
                    flag = true;
                    break;
                }
            }
            else if(a || b)
            {
                if(arr[i][j] > 3)
                {
                    flag = true;
                    break;
                }
            }
            else
            {
                if(arr[i][j] > 4)
                {
                    flag = true;
                    break;
                }
            }
        }
        if(flag)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for(int i = 0; i < n; ++i) {for(int j = 0; j < m; ++j)
        {
            bool a = i == 0 || i == n - 1;
            bool b = j == 0 || j == m - 1;
            if(a && b)
            {
                cout << 2 << ' ';
            }
            else if(a || b)
            {
                cout << 3 << ' ';
            }
            else
            {
                cout << 4 << ' ';
            }
        }
        cout << '\n';
        }
    }
}