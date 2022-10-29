#include <bits/stdc++.h>
using namespace std;

int cnt[144];

int main ()
{
    string s;
    cin >>s;
    string t=s;
    sort(t.begin(),t.end());
    if (s != t)
    {
        puts("NO");
        return 0;
    }
    for (char i:s) cnt[i]++;
    if (cnt['a'] && cnt['b'] && cnt['c'] && (cnt['a'] == cnt['c'] || cnt['b'] == cnt['c']) )
    {
        puts("YES");
    }
    else
    {
        puts("NO");
    }
}