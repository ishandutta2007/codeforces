#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define pii pair<int, int>
#define piii pair<int, pii>
#define pll pair<long long, long long>
#define plll pair<long long, pll>
#define ff first
#define ss second
#define ee ss.ff
#define rr ss.ss

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int arr[n]; for(auto &i : arr) cin >> i;
    pii A[n]; for(int i = 0; i < n; ++i) A[i] = {arr[i], i};
    sort(A, A + n);
    bool chc[n]{};
    vector<pii> B;
    for(int i = 0; i < n; ++i)
    {
        for(int j = n - 1; j > A[i].ss; --j)
        {
            if(chc[j]) B.push_back({A[i].ss + 1, j + 1});
        }
        chc[A[i].ss] = true;
    }
    cout << B.size() << '\n';
    for(auto i : B) cout << i.ff << ' ' << i.ss << '\n';
}