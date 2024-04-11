#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    int a[n], b[m]; for(int &i : a) cin >> i; for(int &i : b) cin >> i;

    int x = 0, y = 0, z = 0, w = 0;
    for(int &i : a)
    {
        if(i & 1) ++x;
        else ++y;
    }
    for(int &i : b)
    {
        if(i & 1) ++z;
        else ++w;
    }

    cout << min(x, w) + min(y, z);
    return 0;
}