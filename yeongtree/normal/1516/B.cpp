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
        int x = 0;
        for(int i = 0; i < n; ++i) x ^= A[i];
        if(x == 0) cout << "YES\n";
        else
        {
            int B[n]; B[0] = A[0];
            for(int i = 1; i < n; ++i) B[i] = B[i - 1] ^ A[i];
            int a = 0;
            while(a < n && B[a] != x) ++a;
            int b = n - 1;
            while(b >= 0 && B[b] != 0) --b;
            if(a < b) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}