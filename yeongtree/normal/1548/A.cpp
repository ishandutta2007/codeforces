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

    int n, m; cin >> n >> m;

    int cnt = n;
    int A[n]{};

    for(int i = 0; i < m; ++i)
    {
        int x, y; cin >> x >> y; --x; --y;
        if(x > y) swap(x, y);
        if(!A[x]++) --cnt;
    }

    int T; cin >> T;
    while(T--)
    {
        int c; cin >> c;
        if(c == 1)
        {
            int x, y; cin >> x >> y; --x; --y;
            if(x > y) swap(x, y);
            if(!A[x]++) --cnt;
        }
        else if(c == 2)
        {
            int x, y; cin >> x >> y; --x; --y;
            if(x > y) swap(x, y);
            if(!--A[x]) ++cnt;
        }
        else cout << cnt << '\n';
    }
}