#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    bool arr[n][m]{}; bool tmp;
    for(int k = 0; k < 2; ++k)
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
    {
        cin >> tmp;
        arr[i][j] ^= tmp;
    }

    for(int i = 0; i < n; ++i)
    {
        bool chc = false;
        for(int j = 0; j < m; ++j)
            chc ^= arr[i][j];

        if(chc){cout << "No"; return 0;}
    }

    for(int j = 0; j < m; ++j)
    {
        bool chc = false;
        for(int i = 0; i < n; ++i)
            chc ^= arr[i][j];

        if(chc){cout << "No"; return 0;}
    }

    cout << "Yes"; return 0;
}