#include <iostream>
#include <vector>
#include <algorithm>
#define ff first
#define ss second

using namespace std;
using ull = long long;
using pul = pair<ull, ull>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    pul A[n]; for(auto &i : A) cin >> i.ss >> i.ff;
    sort(A, A + n);

    ull ans = 0;
    int pt1 = 0, pt2 = n - 1;
    ull sum = 0;
    while(pt1 < pt2)
    {
        if(A[pt1].ff <= sum) ans += A[pt1].ss, sum += A[pt1].ss, ++pt1;
        else if(A[pt2].ss > A[pt1].ff - sum) A[pt2].ss -= A[pt1].ff - sum, ans += 2 * (A[pt1].ff - sum), sum = A[pt1].ff;
        else ans += 2 * A[pt2].ss, sum += A[pt2].ss, --pt2;
    }
    if(A[pt1].ff - sum > A[pt1].ss) ans += 2 * A[pt1].ss;
    else ans += max((ull)0, A[pt1].ff - sum) + A[pt1].ss;

    cout << ans;
}