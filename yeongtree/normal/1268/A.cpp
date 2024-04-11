#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    string s; cin >> s;

    bool flag = true;
    for(int i = 0; i < n; ++i)
    {
        if(s[i] > s[i % k]) {flag = false; break;}
        else if(s[i] < s[i % k]) {flag = true; break;}
    }

    if(flag)
    {
        cout << n << '\n';
        for(int i = 0; i < n; ++i) cout << s[i % k];
    }

    else
    {
        string t(s.begin(), s.begin() + k);
        ++t[k - 1];
        for(int i = k - 1; i >= 1; --i)
        {
            if(t[i] > '9') { t[i] = '0'; ++t[i - 1]; }
            else break;
        }
        if(t[0] > '9') { t[k - 1] = '1'; cout << n + 1 << '\n' << 1; }
        else cout << n << '\n';
        for(int i = 0; i < n; ++i) cout << t[i % k];
    }

    return 0;
}