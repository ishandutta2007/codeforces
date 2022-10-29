#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)(x).size())

typedef long long LL;

vector<int> v;

int cal(int l,int r)
{
    return upper_bound(v.begin(),v.end(),r) - lower_bound(v.begin(),v.end(),l);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    LL ans=0;
    int n = SZ(s);
    for (int i=0;n>i;i++)
    {
        if (i+4 >= n) continue;
        if (s[i] == 'm' && s[i+1] == 'e' && s[i+2] == 't' && s[i+3] == 'a' && s[i+4] == 'l') v.push_back(i);
    }
    for (int i=0;n>i;i++)
    {
        if (i+4 >= n) continue;
        if (s[i] == 'h' && s[i+1] == 'e' && s[i+2] == 'a' && s[i+3] == 'v' && s[i+4] == 'y')
        {
            ans += cal(i,n);
        }
    }
    cout << ans << endl;
}