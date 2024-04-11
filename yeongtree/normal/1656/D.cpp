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
        long long n; cin >> n;
        long long e = 1, o = n;
        while(o % 2 == 0) o >>= 1, e <<= 1;
        if(o == 1) cout << "-1\n";
        else if(e * 2 < o) cout << e * 2 << '\n';
        else cout << o << '\n';
    }
}