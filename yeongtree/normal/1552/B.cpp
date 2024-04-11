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

bool cmp(vector<int> x, vector<int> y)
{
    int cnt = 0;
    for(int i = 0; i < 5; ++i) if(x[i] > y[i]) ++cnt;
    return cnt >= 3;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        vector<vector<int>> A(n, vector<int>(5));
        for(auto &i : A) for(auto &j : i) cin >> j;

        int mx = 0; bool flag = true;
        for(int i = 1; i < n; ++i) if(cmp(A[mx], A[i])) mx = i;
        for(int i = 0; i < n; ++i) if(cmp(A[mx], A[i])) { flag = false; cout << "-1\n"; break; }
        if(flag) cout << mx + 1 << '\n';
    }
}