#include <iostream>

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
        int B[n]; for(int i = 0; i < n; ++i) B[i] = i;
        long long ans = 0;

        int pt = 0;
        while(1)
        {
            while(pt < n && A[pt] == 1) ++pt;
            if(pt == n) break;
            if(A[pt] > n)
            {
                ans += A[pt] - n;
                A[pt] = n;
            }
            while(pt < n && A[pt] == 1) ++pt;
            if(pt == n) break;

            int t = pt;
            while(t < n)
            {
                int s = t + A[t];
                if(A[t] > 1) --A[t];
                t = s;
                if(t >= n) break;
                while(B[t] < n && A[B[t]] == 1) ++B[t];
                t = B[t];
            }

            ++ans;
        }

        cout << ans << '\n';
    }
}