#include <iostream>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int p[n], s[n], c[k];
    for(int i = 0; i < n; ++i ) cin >> p[i];
    for(int i = 0; i < n; ++i){cin >> s[i]; --s[i];}
    for(int i = 0; i < k; ++i) {cin >> c[i]; --c[i];}

    int ss[m] = {};
    for(int i = 0; i < n; ++i)
    {
        if(ss[s[i]] < p[i]) ss[s[i]] = p[i];
    }

    int ans = 0;
    for(int i = 0; i <k; ++i)
    {
        if(ss[s[c[i]]] != p[c[i]]) ++ans;
    }

    cout << ans;
    return 0;
}