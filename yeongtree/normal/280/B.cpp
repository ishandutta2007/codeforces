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

    int n; cin >> n;
    int A[n]; for(auto &i : A) cin >> i;
    int t;

    vector<int> V;
    while(1)
    {
        t = 1;
        int m = *max_element(A, A + n);
        while(t * 2 <= m) t <<= 1;
        for(int i = 0; i < n; ++i) if(A[i] >= t) V.push_back(i);
        if((int)V.size() < n) break;
        for(int i = 0; i < n; ++i) A[i] ^= t;
        V.clear();
    }

    int ans = 0;
    for(int i = 0; i < (int)V.size(); ++i)
    {
        int mx = 0;
        for(int j = V[i] - 1; j >= (i == 0 ? 0 : V[i - 1] + 1); --j)
        {
            mx = max(mx, A[j]);
            ans = max(ans, A[V[i]] ^ mx);
        }
        mx = 0;
        for(int j = V[i] + 1; j <= (i == (int)V.size() - 1 ? n - 1 : V[i + 1] - 1); ++j)
        {
            mx = max(mx, A[j]);
            ans = max(ans, A[V[i]] ^ mx);
        }
    }

    cout << ans;
}