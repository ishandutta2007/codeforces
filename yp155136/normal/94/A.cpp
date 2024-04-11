#include <bits/stdc++.h>
using namespace std;

int main ()
{
    map<string,int> mp;
    string s;
    cin >> s;
    for (int i=0;10>i;i++)
    {
        string t;
        cin >> t;
        mp[t] = i;
    }
    for (int i=0;8>i;i++)
    {
        string ss = s.substr(10*i,10);
        cout << mp[ss];
    }
    cout << endl;
}