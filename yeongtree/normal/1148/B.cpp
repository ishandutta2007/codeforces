#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, ta, tb, k; cin >> n >> m >> ta >> tb >> k;
    int A[n], B[m]; for(auto &i : A) cin >> i; for(auto &i : B) cin >> i;

    int ans = -1;
    for(int i = 0; i <= k; ++i)
    {
        if(i >= n || k - i >= m) {ans = -1; break;}

        int t = lower_bound(B, B + m, A[i] + ta) - B;
        if(t + k - i >= m) {ans = -1; break;}
        ans = max(ans, B[t + k - i] + tb);
    }

    cout << ans;
    return 0;
}