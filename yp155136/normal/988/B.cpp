#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)(x).size())

bool can(string a,string b)
{
    int _ = SZ(a);
    for (int i=0;SZ(b)-_+1>i;i++)
    {
        if (b.substr(i,_) == a) return true;
    }
    return false;
}

int main ()
{
    auto cmp = [](const string &s1,const string &s2){ return SZ(s1) < SZ(s2); };
    int n;
    cin >> n;
    vector<string> v;
    for (int i=0;n>i;i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(),v.end(),cmp);
    for (int i=0;n>i;i++)
    {
        for (int j=0;i>j;j++)
        {
            if(!can(v[j],v[i]))
            {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    for (int i=0;n>i;i++)
    {
        cout << v[i] << endl;
    }
}