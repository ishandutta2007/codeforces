#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
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
#define int long long
const int INF = (int)1e9 + 7;

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        int A[n]{};
        vector<int> ls[n];
        for(int i = 0; i < n; ++i)
        {
            int c; cin >> c;
            for(int j = 0; j < c; ++j)
            {
                int x; cin >> x; --x;
                ls[x].push_back(i);
            }
            A[i] = c;
        }

        priority_queue<int, vector<int>, greater<int>> Q;
        for(int i = 0; i < n; ++i) if(!A[i]) Q.push(i);

        int cnt = 0;
        int ans = 0;
        while(Q.size())
        {
            int x = Q.top(); Q.pop();
            int y = x % n;
            for(auto z : ls[y])
            {
                if(!--A[z])
                {
                    if(z < y) Q.push(z + x / n * n + n);
                    else Q.push(z + x / n * n);
                }
            }
            ++cnt;
            ans = x;
        }

        cout << (cnt == n ? ans / n + 1 : -1) << '\n';
    }
}