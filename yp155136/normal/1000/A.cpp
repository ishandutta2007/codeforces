#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    cin >> n;
    map<string,int> mp;
    for (int i=0;n>i;i++)
    {
        string s;
        cin >> s;
        mp[s]++;
    }
    int ans=0;
    for (int i=0;n>i;i++)
    {
        string s;
        cin >> s;
        if (mp[s]) mp[s]--;
        else ++ans;
    }
    cout << ans << endl;
}