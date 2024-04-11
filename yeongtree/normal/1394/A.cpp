#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d, m; cin >> n >> d >> m;
    vector<int> A, B;
    for(int i = 0; i < n; ++i)
    {
        int x; cin >> x;
        if(x > m) A.push_back(x);
        else B.push_back(x);
    }
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());

    long long ans = 0;
    for(auto i : B) ans += i;
    if(A.size() == 0) { cout << ans; return 0; }
    long long a = A[0], b = ans;
    ans = a + b;
    for(int i = 1; i < A.size(); ++i)
    {
        int s = n - (i - 1) * (d + 1) - 1;
        int t = n - i * (d + 1) - 1;
        if(t < 0) break;
        for(int j = min(s, (int)B.size()) - 1; j >= t; --j)
        {
            b -= B[j];
        }
        a += A[i];
        ans = max(ans, a + b);
    }
    cout << ans;
}