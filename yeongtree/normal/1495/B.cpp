#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define piii pair<int, pii>
#define plll pair<long long, pll>
#define ff first
#define ss second
#define tiii tuple<int, int, int>
#define tiiii tuple<int, int, int, int>
#define tlll tuple<long long, long long, long long>
#define tllll tuple<long long, long long, long long, long long>
//#define DEBUG

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int A[n]; for(auto &i : A) cin >> i;
    vector<pii> B;
    pii mx = {-1, -1}, mx2 = {-1, -1};
    for(int i = 0; i < n; ++i)
    {
        if(i > 0 && A[i - 1] > A[i]) continue;
        if(i < n - 1 && A[i + 1] > A[i]) continue;
        B.push_back({0, 0});
        int j = i;
        while(j >= 0 && A[j - 1] < A[j]) --j;
        B.back().ff = i - j;
        j = i;
        while(j < n && A[j + 1] < A[j]) ++j;
        B.back().ss = j - i;
        auto tmp = pii{ max(B.back().ff, B.back().ss), (int)B.size() - 1 };
        if(mx2 < tmp) swap(mx2, tmp);
        if(mx < mx2) swap(mx, mx2);
    }

    #ifdef DEBUG
        cout << endl;
        cout << "B" << endl;
        for(auto i : B) cout << i.ff << ' ' << i.ss << endl;
        cout << endl;
    #endif

    int N = B.size();
    int ans = 0;
    for(int i = 0; i < N; ++i)
    {
        if(B[i].ff != B[i].ss || (B[i].ff & 1)) continue;
        if(B[i].ff <= mx2.ff) continue;
        if(i != mx.ss && B[i].ff <= mx.ff) continue;
        ++ans;
    }

    cout << ans;
}