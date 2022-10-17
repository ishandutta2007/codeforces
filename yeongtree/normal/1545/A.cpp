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
        int n; cin >> n;
        int A[n]; for(auto &i : A) cin >> i;
        vector<int> pr(A, A + n);
        sort(pr.begin(), pr.end());
        pr.resize(unique(pr.begin(), pr.end()) - pr.begin());
        for(auto &i : A) i = lower_bound(pr.begin(), pr.end(), i) - pr.begin();
        int N = pr.size();
        int B[N][2]{};
        for(int i = 0; i < n; ++i) B[A[i]][i & 1]++;
        sort(A, A + n);
        int C[N][2]{};
        for(int i = 0; i < n; ++i) C[A[i]][i & 1]++;
        bool flag = true;
        for(int i = 0; i < N; ++i) for(int j = 0; j < 2; ++j) if(B[i][j] != C[i][j]) flag = false;
        cout << (flag ? "YES\n" : "NO\n");
    }
}