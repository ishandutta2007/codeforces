#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    int a, b; cin >> a >> b;
    if(a > b)
    {
        swap(a, b);
        for(auto &c : s)
        {
            if(c == '0') c = '1';
            else if(c == '1') c = '0';
        }
    }

    int n = s.size();
    vector<int> t;
    for(int i = 0; i < n; ++i) if(s[i] == '?') t.push_back(i);
    int m = t.size();

    int x[n], y[n], z[n], w[n];
    for(int i = 0; i < n; ++i)
    {
        x[i] = (i > 0 ? x[i - 1] : 0) + (s[i] == '0' ? 1 : 0);
        y[i] = (i > 0 ? y[i - 1] : 0) + (s[i] == '1' ? 1 : 0);
    }
    for(int i = n - 1; i >= 0; --i)
    {
        z[i] = (i < n - 1 ? z[i + 1] : 0) + (s[i] == '0' ? 1 : 0);
        w[i] = (i < n - 1 ? w[i + 1] : 0) + (s[i] == '1' ? 1 : 0);
    }

    long long ans[m + 1]{};
    long long tmp = 0;
    for(int i = 1; i <= m; ++i)
    {
        tmp += 1ll * y[t[i - 1]] * b + 1ll * w[t[i - 1]] * a;
        ans[i] += tmp;
    }
    tmp = 0;
    for(int i = m - 1; i >= 0; --i)
    {
        tmp += 1ll * x[t[i]] * a + 1ll * z[t[i]] * b;
        ans[i] += tmp;
    }
    for(int i = 0; i <= m; ++i) ans[i] += 1ll * i * (m - i) * a;

    long long rans = (long long)8e18;
    for(auto i : ans) rans = min(i, rans);

    for(int i = 0; i < n; ++i) if(s[i] != '?')
    {
        if(s[i] == '0') rans += 1ll * y[i] * b;
        else rans += 1ll * x[i] * a;
    }

    cout << rans;
    return 0;
}