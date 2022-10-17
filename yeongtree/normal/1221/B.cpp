#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if((i + j) & 1) cout << 'B';
            else cout << 'W';
        }
        cout << '\n';
    }

    return 0;
}