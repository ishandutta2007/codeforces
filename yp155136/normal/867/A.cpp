#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    cin >> n;
    int delta=0;
    string s;
    cin >> s;
    for (int i=0;n-1>i;i++)
    {
        if (s[i] == 'S' && s[i+1] == 'F') delta--;
        else if (s[i] == 'F' && s[i+1] == 'S') delta++;
    }
    if (delta < 0) puts("YES");
    else puts("NO");
}