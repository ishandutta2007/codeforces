#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        string s;
        cin >> n >> k >> s;
        int x = n / k, tot = 0;
        for (int i = 0; i < (k + 1) / 2; ++i)
        {
            int cnt[26] = {0}, m = 0;
            for (int j = 0; j < x; ++j)
                cnt[s[k * j + i] - 'a']++, cnt[s[k * (j + 1) - i - 1] - 'a']++;
            for (int j = 0; j < 26; ++j)
                m = max(m, cnt[j]);
            tot += (x * 2 - m) / (i == k / 2 ? 2 : 1); // 
        }
        cout << tot << endl;
    }
    return 0;
}