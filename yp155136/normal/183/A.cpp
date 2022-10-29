#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main ()
{
    map<string,int> mp;
    mp["UR"] = mp["DL"] = 1;
    mp["UL"] = mp["DR"] = 2;
    mp["ULDR"] = 3;
    long long x[4] = {0,1,1,0};
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        x[ mp[s]]++;
    }
    cout << (x[1]+x[3])*(x[2]+x[3]) << endl;
}