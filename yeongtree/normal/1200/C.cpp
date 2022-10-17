#include <iostream>

using namespace std;

long long gcd(long long x, long long y) { return (y ? gcd(y, x % y) : x); }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m; int T; cin >> n >> m >> T;
    long long g = gcd(n, m);
    n /= g; m /= g;
    while(T--)
    {
        int a, c; long long b, d; cin >> a >> b >> c >> d; --b; --d;
        if(a == 1) b /= n;
        else b /= m;
        if(c == 1) d /= n;
        else d /= m;
        if(b == d) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}