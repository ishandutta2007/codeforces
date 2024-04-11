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
        int A[n]; for(auto &i : A) cin >> i;
        pii B[m]; for(auto &i : B) cin >> i.ff >> i.ss, --i.ff;
        vector<int> pr(A, A + n);
        sort(pr.begin(), pr.end());
        pr.resize(unique(pr.begin(), pr.end()) - pr.begin());
        for(auto &i : A) i = lower_bound(pr.begin(), pr.end(), i) - pr.begin();
        int N = (int)pr.size();
        vector<int> ls[N];
        for(int i = 0; i < n; ++i) ls[A[i]].push_back(i);

        int C[n]{};
        for(int i = 0; i < m; ++i) C[B[i].ff] = max(C[B[i].ff], B[i].ss);
        for(int i = 1; i < n; ++i) C[i] = max(C[i], C[i - 1]);

        int D[n]{};
        int E = -1, F = n - 1;
        for(int i = 0; i < n; ++i)
        {
            int x = lower_bound(ls[A[i]].begin(), ls[A[i]].end(), i) - ls[A[i]].begin();
            int y = lower_bound(ls[A[i]].begin(), ls[A[i]].end(), C[i]) - ls[A[i]].begin() - 1;
            if(x >= y) continue;
            E = max(E, ls[A[i]][y - 1]);
            F = min(F, ls[A[i]][x + 1]);
            D[i] = ls[A[i]][y];
        }

        int ans = n;
        for(int i = 0; i <= F; ++i)
        {
            ans = min(ans, E - i + 1);
            E = max(E, D[i]);
        }
        ans = max(ans, 0);
        cout << ans << '\n';
    }
}