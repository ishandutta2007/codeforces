#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int c[n]; for(int &i : c) cin >> i;

    if(c[0] != c[n - 1])
    {
        cout << n - 1;
        return 0;
    }

    int a = 0, b = 0;
    for(int i = 0; i < n; ++i)
    {
        if(c[0] != c[i]) break;
        ++a;
    }
    for(int i = n - 1; i >= 0; --i)
    {
        if(c[n - 1] != c[i]) break;
        ++b;
    }

    cout << n - 1 - (a > b ? b : a);
    return 0;
}