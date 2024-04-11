#include <bits/stdc++.h>
using namespace std;

bool have[1006];

bool okay(int x)
{
    if (!have[x]) return true;
    return (!have[x-1])&&(!have[x+1]);
}

int main ()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i=1;n>=i;i++)
    {
        have[i] = (s[i-1]-'0');
    }
    for (int i=1;n>=i;i++)
    {
        if (!okay(i))
        {
            puts("No");
            return 0;
        }
    }
    for (int i=1;n>=i;i++)
    {
        if (!have[i])
        {
            have[i] = true;
            if (okay(i))
            {
                puts("No");
                return 0;
            }
            have[i] = false;
        }
    }
    puts("Yes");
}