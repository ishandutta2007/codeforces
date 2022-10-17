#include <iostream>
#include <utility>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define ff first
#define ss second

using namespace std;

int gcd(int x, int y) {return (y ? gcd(y, x % y) : x);}
pii egcd(int x, int y)
{
    if(y == 0) return pii{1, 0};
    int t = x / y;
    pii ret = egcd(y, x - y * t);
    return pii{ret.ss, ret.ff - ret.ss * t};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k; int a, b; cin >> n >> k >> a >> b;

    int g = gcd(a, b);
    if(k % (long long)g) { cout << -1; return 0; }
    k /= g; a /= g; b /= g;

    int t = egcd(a, b).ss; if(t < 0) t += a;
    long long y = k % a * t % a;
    long long x = (k - y * b) / a;
    long long z = n - x - y;

    if(x < 0 || z < 0) { cout << -1; return 0; }

    cout << x << ' ' << y << ' ' << z;
    return 0;
}