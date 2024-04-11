#include <iostream>
#include <set>
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
        int n, q; cin >> n >> q;
        int A[n]; for(auto &i : A) cin >> i;
        int k = 1;
        string ans = "1";
        for(int i = n - 2; i >= 0; --i)
        {
            if(k >= A[i]) ans += '1';
            else
            {
                if(k == q) ans += '0';
                else ans += '1', ++k;
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans << '\n';
    }
}