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

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n, x; cin >> n >> x;
        int A[n]; for(auto &i : A) cin >> i;
        sort(A, A + n);
        int s = 0;
        bool flag = true;
        for(int i = 0; i < n; ++i)
        {
            s += A[i];
            if(s == x)
            {
                if(i == n - 1) { flag = false; break; }
                else { swap(A[i], A[i + 1]); break; }
            }
        }
        if(flag)
        {
            cout << "YES\n";
            for(auto i : A) cout << i << ' ';
            cout << '\n';
        }
        else cout << "NO\n";
    }
}