#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <set>
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
    vector<int> prm;
    bool sv[202020]{};
    for(int i = 2; i < 202020; ++i) if(!sv[i])
    {
        prm.push_back(i);
        for(long long j = 1ll * i * i; j < 202020; j += i) sv[j] = true;
    }

    while(T--)
    {
        int n, q; cin >> n >> q;
        int A[n]; for(auto &i : A) cin >> i;
        vector<int> B;
        for(auto i : prm)
        {
            if(n < i) break;
            if(n % i == 0) B.push_back(n / i);
        }

        int N = B.size();
        vector<vector<long long>> V(N);
        multiset<long long, greater<long long>> S[N];
        for(int i = 0; i < N; ++i)
        {
            V[i].resize(B[i]);
            for(int j = 0; j < n; ++j)
                V[i][j % B[i]] += A[j];
            for(int j = 0; j < B[i]; ++j) S[i].insert(V[i][j]);
        }

        long long ans = 0;
        for(int i = 0; i < N; ++i) ans = max(ans, *S[i].begin() * B[i]);
        cout << ans << '\n';

        while(q--)
        {
            int p, x; cin >> p >> x; --p;
            for(int i = 0; i < N; ++i)
            {
                long long pr = V[i][p % B[i]];
                V[i][p % B[i]] += x - A[p];
                S[i].erase(S[i].find(pr));
                S[i].insert(V[i][p % B[i]]);
            }
            A[p] = x;

            ans = 0;
            for(int i = 0; i < N; ++i) ans = max(ans, *S[i].begin() * B[i]);
            cout << ans << '\n';
        }
    }
}