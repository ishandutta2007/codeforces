#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    char arr[n][m]; for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) cin >> arr[i][j];
    int num = 0; for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) if(arr[i][j] == '*') ++num;

    for(int i = 1; i < n - 1; ++i)
    {
        for(int j = 1; j < m - 1; ++j)
        {
            int __num = 1; int x = i, y = j; if(arr[x][y] == '.') continue;
            x = i - 1; y = j; if(arr[x][y] == '.') continue; while(x >= 0 && arr[x][y] == '*') {--x; ++__num;}
            x = i + 1; y = j; if(arr[x][y] == '.') continue; while(x < n && arr[x][y] == '*') {++x; ++__num;}
            x = i; y = j - 1; if(arr[x][y] == '.') continue; while(y >= 0 && arr[x][y] == '*') {--y; ++__num;}
            x = i; y = j + 1; if(arr[x][y] == '.') continue; while(y < m && arr[x][y] == '*') {++y; ++__num;}
            if(num == __num) {cout << "YES"; return 0;}
        }
    }

    cout << "NO";
    return 0;
}