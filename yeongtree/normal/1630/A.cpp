#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#define pii pair<int, int>
#define piii pair<int, pii>
#define pll pair<long long, long long>
#define plll pair<long long, pll>
#define tiii tuple<int, int, int>
#define tiiii tuple<int, int, int, int>
#define ff first
#define ss second
#define ee ss.ff
#define rr ss.ss
#define DEBUG
const int INF = (int)1e9 + 7;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n, k; cin >> n >> k;
        if(n == 4 && k == 3) cout << "-1\n";
        else if(k == n - 1)
        {
            cout << 1 << ' ' << 3 << '\n';
            cout << 0 << ' ' << n - 4 << '\n';
            cout << n - 2 << ' ' << n - 1 << '\n';
            for(int i = 2; i < n / 2; ++i) if(i != 3) cout << i << ' ' << n - i - 1 << '\n';
        }
        else
        {
            cout << k << ' ' << n - 1 << '\n';
            if(k) cout << 0 << ' ' << n - k - 1 << '\n';
            for(int i = 1; i < n / 2; ++i) if(i != k && i != n - k - 1) cout << i << ' ' << n - i - 1 << '\n';
        }
    }
}