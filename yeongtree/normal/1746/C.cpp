#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define piii pair<int, pii>
#define plll pair<long long, pll>
#define tiii tuple<int, int, int>
#define tiiii tuple<int, int, int, int>
#define ff first
#define ss second
#define ee ss.ff
#define rr ss.ss

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
        vector<pii> V; for(int i = 0; i < n - 1; ++i) if(A[i] > A[i + 1]) V.push_back({A[i] - A[i + 1], i + 2});
        sort(V.begin(), V.end());
        for(int i = 0; i < n - (int)V.size(); ++i) cout << "1 ";
        for(auto [a, b] : V) cout << b << ' ';
        cout << '\n';
    }
}