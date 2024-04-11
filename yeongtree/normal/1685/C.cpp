#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <string>
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
        int n; cin >> n; n <<= 1;
        string s; cin >> s;
        int A[n + 1]; A[0] = 0;
        for(int i = 0; i < (int)s.size(); ++i)
        {
            if(s[i] == '(') A[i + 1] = A[i] + 1;
            else A[i + 1] = A[i] - 1;
        }

        bool flag = false;
        for(int i = 0; i <= n; ++i) if(A[i] < 0) flag = true;
        if(!flag) { cout << "0\n"; continue; }

        pii mx = {-1, -1};
        for(int i = 0; i <= n; ++i) mx = max(mx, {A[i], i});
        pii mxl = {-1, -1};
        for(int i = 0; i <= n; ++i)
        {
            if(A[i] < 0) break;
            mxl = max(mxl, {A[i], i});
        }
        pii mxr = {-1, -1};
        for(int i = n; i >= 0; --i)
        {
            if(A[i] < 0) break;
            mxr = max(mxr, {A[i], i});
        }

        if(mx.ff <= mxl.ff + mxr.ff)
        {
            cout << "1\n" << mxl.ss + 1 << ' ' << mxr.ss << '\n';
        }
        else
        {
            cout << "2\n1 " << mx.ss << '\n' << mx.ss + 1 << ' ' << n << '\n';
        }
    }
}