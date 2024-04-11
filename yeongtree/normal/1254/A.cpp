#include <iostream>

using namespace std;

char toC(int x)
{
    if(x < 26) return x + 'a';
    if(x < 52) return x - 26 + 'A';
    return x - 52 + '0';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n, m, k; cin >> n >> m >> k;
        bool arr[n][m]; int cnt = 0;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                char c; cin >> c;
                arr[i][j] = (c == 'R');
                if(arr[i][j]) ++cnt;
            }
        }

        int cnt1 = cnt / k;
        int cnt2 = cnt % k;
        if(cnt2) ++cnt1;
        int x = 0;

        char ans[n][m];

        for(int i = 0; i < n; ++i)
        {
            for(int _j = 0; _j < m; ++_j)
            {
                int j = _j;
                if(i & 1) j = m - j - 1;
                ans[i][j] = toC(x);
                if(arr[i][j]) if(!--cnt1)
                {
                    if(cnt2) --cnt2;
                    if(x < k - 1) ++x;
                    cnt1 = cnt / k;
                    if(cnt2) ++cnt1;
                }
            }
        }

        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                cout << ans[i][j];
            }
            cout << '\n';
        }
    }
}