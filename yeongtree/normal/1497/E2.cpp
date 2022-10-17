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

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n, k; cin >> n >> k;
        int A[n];
        for(auto &i : A)
        {
            cin >> i;
            for(int j = 2; j * j <= i; ++j)
            {
                while(i % (j * j) == 0) i /= j * j;
            }
        }

        pii B[n];
        for(int i = 0; i < n; ++i) B[i] = {A[i], i};
        sort(B, B + n);

        vector<pii> ran;
        for(int i = 1; i < n; ++i) if(B[i - 1].ff == B[i].ff) ran.push_back({B[i - 1].ss, B[i].ss});
        sort(ran.begin(), ran.end(), [](pii x, pii y){ return x.ss < y.ss; });

        vector<pii> D(k + 1); for(auto &i : D) i = {1, 0};
        for(auto x : ran)
        {
            vector<pii> E(k + 1);
            for(int i = 0; i <= k; ++i)
            {
                if(-D[i].ss <= x.ff) E[i] = {D[i].ff + 1, -x.ss};
                else E[i] = D[i];
            }
            for(int i = 0; i < k; ++i) E[i + 1] = min(E[i + 1], D[i]);
            D = E;
        }

        cout << D[k].ff << '\n';
    }
}