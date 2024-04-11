#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)(x).size())

bool judge(string s,string t,int n,int k)
{
    int ret=0;
    for (int i=0;i<SZ(s);++i)
    {
        if (i + SZ(t)-1 >= SZ(s) ) break;
        if (s.substr(i,SZ(t)) == t) ++ret;
    }
    return ret>=k;
}

int main ()
{
    int n,k;
    cin >> n >> k;
    string t;
    cin >> t;
    if (k == 1)
    {
        cout <<t << endl;
        return 0;
    }
    string ans = "";
    for (int i=SZ(t)-1;i>=0;i--)
    {
        string s = t;
        string tmp = "";
        for (int j=i;j<SZ(t);++j)
        {
            tmp.push_back(t[j]);
        }
        int cnt = k-1;
        while (cnt--) s += tmp;
        if (judge(s,t,n,k))
        {
            if (ans == "") ans = s;
            else if (SZ(s) < SZ(ans)) ans = s;
        }
    }
    cout << ans << endl;
}