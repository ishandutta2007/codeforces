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
    int pow[11];
    pow[0] = 1; for(int i = 1; i < 11; ++i) pow[i] = pow[i - 1] * 3;
    while(T--)
    {
        int n; cin >> n;
        int A[n]; for(auto &i : A) cin >> i;
        bool flag = false;
        for(int i = 0; i < pow[n] - 1; ++i)
        {
            int a = 0, b = 0;
            for(int j = 0; j < n; ++j)
            {
                if(i / pow[j] % 3 == 0) a += A[j];
                if(i / pow[j] % 3 == 1) b += A[j];
            }
            if(a == b) {flag = true; break;}
        }
        cout << (flag ? "YES\n" : "NO\n");
    }
}