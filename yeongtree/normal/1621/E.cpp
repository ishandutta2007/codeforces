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
//#define DEBUG
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
        sort(A, A + n);

        int C[m];
        vector<int> B[m];
        int M[m];
        vector<int> D[m];
        for(int i = 0; i < m; ++i)
        {
            cin >> C[i];
            B[i].resize(C[i]);
            D[i].resize(C[i]);
            long long s = 0;
            for(int j = 0; j < C[i]; ++j) cin >> B[i][j], s += B[i][j];

            M[i] = (s - 1) / C[i] + 1;
            for(int j = 0; j < C[i]; ++j) D[i][j] = (s - B[i][j] - 1) / (C[i] - 1) + 1;
        }

        pii S[m]; for(int i = 0; i < m; ++i) S[i] = {M[i], i};
        sort(S, S + m);

        int V[m];
        for(int i = 0; i < m; ++i) V[i] = (A + n) - lower_bound(A, A + n, S[i].ff);
        bool flag = true;
        for(int i = 0; i < m; ++i) if(V[i] < m - i) flag = false;

        vector<int> ans[m];

        if(flag)
        {
            #ifdef DEBUG
                cout << endl;
                cout << "D" << endl;
                for(auto i : D) for(auto j : i) cout << j << ' '; cout << endl;
                cout << endl;
            #endif
            int ps[m + 1]{};
            for(int i = 0; i < m; ++i) ps[i + 1] = ps[i] + int(V[i] == m - i);
            for(int i = 0; i < m; ++i)
            {
                int x = S[i].ss;
                for(int j = 0; j < C[x]; ++j)
                {
                    if(D[x][j] <= M[x]) ans[x].push_back(1);
                    else
                    {
                        int tch = (A + n) - lower_bound(A, A + n, D[x][j]);
                        int ind = lower_bound(S, S + m, pii{D[x][j], -1}) - S;
                        ans[x].push_back(int(tch >= m - ind + 1 && ps[ind] - ps[i + 1] == 0));
                    }
                }
            }
        }
        else
        {
            int ps[m + 1]{};
            for(int i = 0; i < m; ++i) ps[i + 1] = ps[i] + int(V[i] < m - i - 1);
            int ps2[m + 1]{};
            for(int i = 0; i < m; ++i) ps2[i + 1] = ps2[i] + int(V[i] < m - i);
            for(int i = 0; i < m; ++i)
            {
                int x = S[i].ss;
                for(int j = 0; j < C[x]; ++j)
                {
                    if(D[x][j] >= M[x]) ans[x].push_back(0);
                    else
                    {
                        int tch = (A + n) - lower_bound(A, A + n, D[x][j]);
                        int ind = upper_bound(S, S + m, pii{D[x][j], m + 1}) - S;
                        ans[x].push_back(int(tch >= m - ind && ps[i] - ps[ind] == 0 && ps2[ind] == 0 && ps2[m] - ps2[i + 1] == 0));
                    }
                }
            }
        }

        for(int i = 0; i < m; ++i) for(auto j : ans[i]) cout << j;
        cout << '\n';
    }
}