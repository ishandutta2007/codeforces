#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int dx[5] = {0, 1, 1, 1, 2};
    const int dy[5] = {0, -1, 0, 1, 0};

    int n; cin >> n;
    bool brd[n][n]; for(auto &i : brd) for(auto &j : i){char a; cin >> a; j = (a == '.');}
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(brd[i][j])
            {
                for(int k = 0; k < 5; ++k)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < n && brd[nx][ny])
                        brd[nx][ny] = false;
                    else goto FAIL;
                }
            }
        }
    }

    cout << "YES";
    return 0;

FAIL:
    cout << "NO";
    return 0;
}