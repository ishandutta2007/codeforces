#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    cin >> n;
    vector<string> v;
    while (n--)
    {
        string s;
        cin >>s;
        sort(s.begin(),s.end());
        s.resize(unique(s.begin(),s.end()) - s.begin());
        v.push_back(s);
    }
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end()) - v.begin());
    cout << v.size() << endl;
}