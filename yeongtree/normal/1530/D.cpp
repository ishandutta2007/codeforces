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
    while(T--)
    {
        int n; cin >> n;
        int A[n]; for(auto &i : A) cin >> i, --i;
        int B[n]; for(int i = 0; i < n; ++i) B[i] = A[i];

        bool T[n]{};
        vector<int> V;
        for(int i = 0; i < n; ++i)
        {
            if(!T[A[i]]) T[A[i]] = true;
            else A[i] = -1, V.push_back(i);
        }

        if(V.size() == 1 && !T[V[0]])
        {
            int t = V[0];
            int tmp = B[t];
            for(int i = 0; i < n; ++i) if(A[i] == tmp) A[i] = -1, V[0] = i;
            A[t] = tmp;
        }

        for(int i = 0; i < n; ++i)
        {
            if(A[i] == -1 && !T[i]) A[i] = i, T[i] = true;
        }

        vector<int> W;
        for(int i = 0; i < n; ++i) if(!T[i]) W.push_back(i);
        int pt = 0;
        for(int i = 0; i < n; ++i) if(A[i] == -1) A[i] = W[pt++];

        if(V.size() >= 2)
        {
            int tmp = A[V[0]];
            for(int i = 1; i < (int)V.size(); ++i)
            {
                A[V[i - 1]] = A[V[i]];
            }
            A[V.back()] = tmp;
        }

        cout << n - (int)V.size() << '\n';
        for(int i = 0; i < n; ++i) cout << A[i] + 1 << ' ';
        cout << '\n';
    }
}