#include <bits/stdc++.h>
using namespace std;

int main ()
{
    string s;
    cin >> s;
    reverse(s.begin(),s.end());
    int cnt0 = 0;
    for (auto i:s)
    {
        if (i=='0')
        {
            cnt0++;
        }
        else
        {
            if (cnt0 >= 6)
            {
                puts("yes");
                return 0;
            }
        }
    }
    puts("no");
}