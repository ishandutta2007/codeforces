#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, T; cin >> n >> T;
    bool arr[2][101010] = {};
    bool chc[101010]; for(auto &i : chc) i = true;
    int cnt = 0;

    while(T--)
    {
        int x, y; cin >> x >> y; --x; --y;
        arr[x][y] = !arr[x][y];
        if(y > 0)
        {
            if(chc[y]) --cnt;
            chc[y] = (!arr[0][y - 1] && !arr[0][y]) || (!arr[1][y - 1] && !arr[1][y]);
            if(chc[y]) ++cnt;
        }
        if(y < n - 1)
        {
            if(chc[y + 1]) --cnt;
            chc[y + 1] = (!arr[0][y] && !arr[0][y + 1]) || (!arr[1][y] && !arr[1][y + 1]);
            if(chc[y + 1]) ++cnt;
        }

        cout << (cnt ? "No" : "Yes") << '\n';
    }

    return 0;
}