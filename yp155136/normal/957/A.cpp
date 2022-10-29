#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int sz = s.size();
    for (int i=0;sz-1>i;i++)
    {
        if (s[i] == s[i+1] && s[i] != '?')
        {
            puts("No");
            return 0;
        }
    }
    bool _ = false;
    for (int i=0;sz>i;i++)
    {
        if (s[i] == '?')
        {
            _ = true;
        }
    }
    if (!_)
    {
        puts("No");
        return 0;
    }
    for (int i=0;sz-1>i;i++)
    {
        if (s[i] == '?' && s[i+1] == '?')
        {
            puts("Yes");
            return 0;
        }
    }
    for (int i=0;sz>i;i++)
    {
        set<char> st;
        if (s[i] == '?')
        {
            if (i-1 >= 0) st.insert(s[i-1]);
            if (i+1 < sz) st.insert(s[i+1]);
            if (st.size() != 2)
            {
                puts("Yes");
                return 0;
            }
        }
    }
    puts("No");
    return 0;
}