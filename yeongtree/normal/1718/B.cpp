#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    long long F[60];
    F[0] = F[1] = 1;
    for(int i = 2; i < 60; ++i) F[i] = F[i - 1] + F[i - 2];
    long long G[60];
    G[0] = F[0];
    for(int i = 1; i < 60; ++i) G[i] = G[i - 1] + F[i];

    while(T--)
    {
        int n; cin >> n;
        long long S = 0;
        long long A[n]; for(auto &i : A) cin >> i, S += i;
        int t = 0;
        for(; t < 60; ++t) if(G[t] == S) break;
        if(t == 60) cout << "NO\n";
        else
        {
            ++t;
            int chc[t]{};
            for(int i = 0; i < n; ++i)
            {
                for(int j = t - 1; j >= 0; --j)
                {
                    if(A[i] >= F[j])
                    {
                        if(j % 2 == 1 && (chc[j] == 2 || (chc[j] == 1 && A[i] == F[j])))
                        {
                            for(int k = 0; k < j; k += 2) chc[k] = 1;
                        }
                        else if(A[i] == F[j]) chc[j] = 2;
                        else chc[j] = 1;
                        A[i] -= F[j];
                        --j;
                    }
                }
            }
            int cnt = 0;
            for(int i = 0; i < t; ++i) if(chc[i]) ++cnt;
            cout << (cnt == t ? "YES" : "NO") << '\n';
        }
    }
}