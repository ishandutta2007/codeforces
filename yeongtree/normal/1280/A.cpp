#include <iostream>
#include <string>

using namespace std;

const long long Q = (long long)1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int x; cin >> x;
        string s; cin >> s;
        int lp = 0, rp = s.size();
        long long ans = rp;

        while(lp < x)
        {
            int t = s[lp] - '1'; ++lp;
            for(int i = 0; i < t; ++i)
            {
                for(int j = lp; j < rp && s.size() <= x; ++j)
                    s.push_back(s[j]);
            }

            ans += (long long)t * ((ans + Q - lp) % Q);
            ans %= Q;
            rp = s.size();
        }

        cout << ans << '\n';
    }
}