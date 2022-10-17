#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long a, b, c; cin >> a >> b >> c;
    long long ans = 0;
    ans += c * 2;
    long long d = max(a, b) - min(a, b);
    ans += min(a, b) * 2;
    if(d > 0) ++ans;
    cout << ans;
    return 0;
}