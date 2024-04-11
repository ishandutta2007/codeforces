#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n; cin >> n;
    int s[n], t[n];
    for(int i = 0; i < n; ++i) cin >> s[i];
    for(int i = 0; i < n; ++i) cin >> t[i];
    if(s[0] != t[0]){cout << "No"; return 0;}
    int ss[n - 1]; for(int i = 0; i < n - 1; ++i) ss[i] = s[i + 1] - s[i];
    int st[n - 1]; for(int i = 0; i < n - 1; ++i) st[i] = t[i + 1] - t[i];
    sort(ss, ss + n - 1); sort(st, st + n - 1);
    bool flag = true;
    for(int i = 0; i < n - 1; ++i)
        if(ss[i] != st[i]){flag = false; break;}
    cout << (flag ? "Yes" : "No") << '\n';
    return 0;
}