#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)(x).size())

int main ()
{
    string s;
    cin >> s;
    cin >> s;
    s = " " + s + " ";
    int n= SZ(s);
    vector<int> v;
    for (int i=0;n>i;i++)
    {
        if (s[i] == 'x')
        {
            if (s[i-1] == 'x')
            {
                v[ SZ(v)-1 ]++;
            }
            else
            {
                v.push_back(1);
            }
        }
    }
    int ans=0;
    for (int i:v)
    {
        if (i>=3) ans-=(i-2);
    }
    printf("%d\n",-ans);
}