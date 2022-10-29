#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    cin >>n;
    string s;
    cin >> s;
    map<string,int> mp;
    for (int i=0;n-1>i;i++)
    {
        mp[ s.substr(i,2) ]++;
    }
    int mx=0;
    for (auto i:mp)
    {
        mx = max(mx,i.second);
    }
    for (int i=0;n-1>i;i++)
    {
        if (mp[ s.substr(i,2) ] == mx)
        {
            cout << s.substr(i,2) << endl;
            return 0;
        }
    }
}