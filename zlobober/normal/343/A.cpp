#include <cstdio>
#include <iostream>
using namespace std;

typedef long long llong;

int main()
{
    llong a, b;
    cin >> a >> b;
    llong ans = 0;
    if (a < b)
        swap(a, b);
    while (a % b != 0)
    {
        ans += a / b;
        a %= b;
        swap(a, b);
    }
    ans += a / b;
    cout << ans << endl;
    return 0;
}