#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;
    bool m[n][n];
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            char a; cin >> a;
            if(a == 'X') m[i][j] = true;
            else m[i][j] = false;
        }
    }

    int ans = 0;
    for(int i = 1; i < n-1; ++i)
    {
        for(int j = 1; j < n-1; ++j)
        {
            if(m[i][j] && m[i-1][j-1] && m[i-1][j+1] && m[i+1][j-1] && m[i+1][j+1]) ++ans;
        }
    }

    cout << ans;
    return 0;
}