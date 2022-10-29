#include <bits/stdc++.h>
using namespace std;

int p[123456];

//vector<int> v[123456];

int group[123456];

int kirino[123456];

int main ()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k,m;
    cin >> n >>k >>m;
    map<string,int> mp;
    for (int i=1;n>=i;i++)
    {
        string s;
        cin >> s;
        mp[s] = i;
    }
    for (int i=1;n>=i;i++)
    {
        cin >> p[i];
    }
    for (int i=1;k>=i;i++)
    {
        int x;
        cin >> x;
        kirino[i] = 1234567890;
        while (x--)
        {
            int _;
            cin >> _;
            group[_] = i;
            kirino[i] = min(kirino[i],p[_]);
        }
    }
    long long ans=0;
    while (m--)
    {
        string s;
        cin >> s;
        ans += kirino[ group[ mp[s] ] ];
    }
    cout << ans << endl;
}