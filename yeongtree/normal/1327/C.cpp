#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    string s;
    for(int i = 0; i < n - 1; ++i)
        s += 'D';
    for(int i = 0; i < m - 1; ++i)
        s += 'L';
    for(int i = 0; i < n; ++i)
    {
        if(i & 1)
        {
            for(int j = 0; j < m - 1; ++j)
                s += 'L';
            if(i != n - 1) s += 'U';
        }
        else
        {
            for(int j = 0; j < m - 1; ++j)
                s += 'R';
            if(i != n - 1) s += 'U';
        }
    }

    cout << s.size() << '\n' << s;
}