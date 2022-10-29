#include <iostream>
#include <cstdio>
using namespace std;

int main ()
{
    string s;
    cin >> s;
    int ans=0;
    int n=s.size();
    for (int i=0;n>i;i++)
    {
        for (int j=i+1;n>j;j++)
        {
            for (int k=j+1;n>k;k++)
            {
                if (s[i] == 'Q' && s[j] == 'A' && s[k] == 'Q') ans++;
            }
        }
    }
    cout << ans << endl;
}