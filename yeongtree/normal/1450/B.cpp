#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define pii pair<int, int>
#define piii pair<int, pii>
#define pll pair<long long, long long>
#define plll pair<long long, pll>
#define ff first
#define ss second
#define ee ss.ff
#define rr ss.ss

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n, k; cin >> n >> k;
        pii A[n];
        for(auto &i : A) cin >> i.ff >> i.ss;
        bool bflag = true;
        for(int i = 0; i < n; ++i)
        {
            bool flag = true;
            for(int j = 0; j < n; ++j)
            {
                if(abs(A[i].ff - A[j].ff) + abs(A[i].ss - A[j].ss) > k)
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                bflag = false;
                cout << "1\n";
                break;
            }
        }
        if(bflag) cout << "-1\n";
    }
}