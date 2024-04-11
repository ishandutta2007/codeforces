#include <iostream>
#include <chrono>
#include <random>

using namespace std;

int gcd(int x, int y){return (y == 0 ? x : gcd(y, x % y));}

int main()
{
    int n; cin >> n;
    int c;

    int s = 0; int t = (int)1e9; int cnt = 0;
    while(s + 1 < t)
    {
        int mid = (s + t) / 2;
        cout << "> " << mid << endl; ++cnt;
        cin >> c; if(c == -1) return 0;
        if(c) s = mid;
        else t = mid;
    }

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dist(1, n);
    int d = 0;
    for(int i = 0; i < 60 - cnt; ++i)
    {
        cout << "? " << dist(rng) << endl;
        cin >> c; if(c == -1) return 0;
        d = gcd(t - c, d);
    }

    int x = t - (n - 1) * d;
    cout << "! " << x << ' ' << d << endl;
    return 0;
}