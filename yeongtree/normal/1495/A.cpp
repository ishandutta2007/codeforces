#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

int abs(int x) { return x > 0 ? x : -x; }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        vector<int> A, B;
        for(int i = 0; i < 2 * n; ++i)
        {
            int x, y; cin >> x >> y;
            if(x == 0) A.push_back(abs(y));
            else B.push_back(abs(x));
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        long double sum = 0;
        for(int i = 0; i < n; ++i) sum += sqrt((long double)(1ll * A[i] * A[i] + 1ll * B[i] * B[i]));
        cout << fixed << setprecision(20) << sum << '\n';
    }
}