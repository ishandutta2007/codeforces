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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        int A[n]; for(auto &i : A) cin >> i;
        if(n & 1) cout << "NO\n";
        else
        {
            sort(A, A + n);
            int B[n];
            for(int i = 0; i < n / 2; ++i) B[i * 2] = A[i];
            for(int i = n / 2; i < n; ++i) B[(i - n / 2) * 2 + 1] = A[i];
            bool flag = true;
            for(int i = 0; i < n - 1; ++i) if(B[i] == B[i + 1]) flag = false;
            if(flag)
            {
                cout << "YES\n";
                for(int i = 0; i < n; ++i) cout << B[i] << ' ';
                cout << '\n';
            }
            else cout << "NO\n";
        }
    }
}