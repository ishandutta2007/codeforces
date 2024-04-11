#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define ll long long

using namespace std;

int t, n, l, r;

int cl[1234567], cr[1234567];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n >> l >> r;
        for(int i = 0; i <= n; i++)
            cl[i] = cr[i] = 0;
        int c;
        for(int i = 0; i < l; i++)
        {
            cin >> c;
            cl[c]++;
        }
        for(int i = 0; i < r; i++)
        {
            cin >> c;
            cr[c]++;
        }
        int mi = min(l, r);
        int ans = n-mi;
        for(int i = 1; i<= n; i++)
        {
            if(r > l && cr[i] > cl[i])
            {
                mi = min(r-l, cr[i]-cl[i]);
                ans -= mi/2;
                r -= mi/2;
                l += mi/2;
            }
            if(l > r && cl[i] > cr[i])
            {
                mi = min(l-r, cl[i]-cr[i]);
                ans -= mi/2;
                l -= mi/2;
                r += mi/2;

            }
            mi = min(cl[i], cr[i]);
            ans -= mi;
        }
        cout << ans << endl;
    }
    return 0;
}