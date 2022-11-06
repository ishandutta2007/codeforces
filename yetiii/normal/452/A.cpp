#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    vector<string> ca={"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
    int n;
    string s;
    cin>>n>>s;
    for (auto c:ca)
    {
        if (c.length()!=n) continue;
        bool ok=1;
        for (int i=0;i<n;++i) if (s[i]!='.'&&s[i]!=c[i]) ok=0;
        if (ok)
        {
            cout<<c<<endl;
            return 0;
        }
    }
    throw;
    return 0;
}