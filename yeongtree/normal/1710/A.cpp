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
        int n, m, k; cin >> n >> m >> k;
        int A[k]; for(auto &i : A) cin >> i;
        long long a = 0; int b = 0;
        for(int i = 0; i < k; ++i)
        {
            if(A[i] >= 2 * n) a += A[i] / n;
            if(A[i] / n > 2) ++b;
        }
        if(a >= m && (b || m % 2 == 0)) { cout << "Yes\n"; continue; }
        a = 0; b = 0;
        for(int i = 0; i < k; ++i)
        {
            if(A[i] >= 2 * m) a += A[i] / m;
            if(A[i] / m > 2) ++b;
        }
        if(a >= n && (b || n % 2 == 0)) { cout << "Yes\n"; continue; }
        cout << "No\n";
    }
}