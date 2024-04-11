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
        vector<vector<int>> V(n), W(n);
        vector<int> K;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                int x; cin >> x;
                V[i].push_back(x);
            }
        }
        for(int i = 0; i < n; ++i)
        {
            W[i] = V[i];
            sort(W[i].begin(), W[i].end());

            vector<int> D;
            for(int j = 0; j < m; ++j) if(V[i][j] != W[i][j]) D.push_back(j);
            if(D.size() > 2) { cout << "-1\n"; goto A; }

            if(D.size() == 2)
            {
                if(K.empty()) K = D;
                else if(K != D) { cout << "-1\n"; goto A; }
            }
        }

        if(K.empty()) cout << "1 1\n";
        else
        {
            for(int i = 0; i < n; ++i)
            {
                swap(V[i][K[0]], V[i][K[1]]);
                for(int j = 0; j < m - 1; ++j) if(V[i][j] > V[i][j + 1]) { cout << "-1\n"; goto A; }
            }
            cout << K[0] + 1 << ' ' << K[1] + 1 << '\n';
        }

        A:;
    }
}