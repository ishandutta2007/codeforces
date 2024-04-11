#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <string>
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
        int n, m; cin >> n >> m;
        string s, t; cin >> s >> t;
        bool flag = true;
        for(int i = 1; i < m; ++i) if(s[i + n - m] != t[i]) flag = false;
        bool flag2 = false;
        for(int i = 0; i <= n - m; ++i) if(s[i] == t[0]) flag2 = true;
        cout << ((flag && flag2) ? "YES" : "NO") << '\n';
    }
}