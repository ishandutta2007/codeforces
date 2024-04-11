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
        int n, m; cin >> n >> m;
        int A[m]; for(auto &i : A) cin >> i;
        sort(A, A + m);
        vector<int> V;
        for(int i = 0; i < m - 1; ++i) V.push_back(A[i + 1] - A[i] - 1);
        V.push_back(n - A[m - 1] + A[0] - 1);
        sort(V.rbegin(), V.rend());
        int ans = 0;
        for(int i = 0; i < m; ++i)
        {
            if(V[i] < 4 * i + 1) break;
            ans += max(1, V[i] - 4 * i - 1);
        }
        cout << n - ans << '\n';
    }
}