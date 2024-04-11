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

using namespace std;

struct myPQ
{
    priority_queue<long long> A, B;
    inline void norm() { while(B.size() && A.top() == B.top()) A.pop(), B.pop(); }
    inline void push(long long x) { A.push(x); }
    inline long long top(void) { return A.top(); }
    inline void pop(void) { A.pop(); norm(); }
    inline void pop(long long x) { B.push(x); norm(); }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int A[n + 1], B[n + 1]; A[0] = 0;
    for(int i = 1; i <= n; ++i) cin >> A[i];
    for(int i = 1; i <= n; ++i) cin >> B[i];

    long long dp[n + 1]{};
    long long ind[(n + 1) << 1]{};
    vector<int> S{0};
    myPQ Q; Q.push(-(long long)1e18);
    for(int i = 1; i <= n; ++i)
    {
        while(A[S.back()] > A[i])
            Q.pop(dp[S.back()]),
            S.pop_back();

        long long ret = Q.top();
        for(int x = S.back() + n + 1, y = i + n + 1; x != y; x >>= 1, y >>= 1)
        {
            if(x & 1) ret = max(ret, ind[x++] + B[i]);
            if(y & 1) ret = max(ret, ind[--y] + B[i]);
        }

        S.push_back(i);
        Q.push(ret);
        dp[i] = ret;

        int x = i + n + 1;
        ind[x] = ret;
        while(x >>= 1) ind[x] = max(ind[x << 1], ind[x << 1 | 1]);
    }

    cout << Q.top();
}