#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, c; cin >> r >> c;
    if(r == 1 && c == 1) {cout << 0; return 0;}
    if(r == 1) { for(int i = 0; i < c; ++i) cout << i + 2 << ' '; return 0; }
    if(c == 1) { for(int i = 0; i < r; ++i) cout << i + 2 << '\n'; return 0; }
    int ans[r][c];
    for(int i = 0; i < r; ++i)
        for(int j = 0; j < c; ++j)
            ans[i][j] = (i + 1) * (j + r + 1);
    for(auto &i : ans)
    {
        for(auto j : i) cout << j << ' ';
        cout << '\n';
    }
}