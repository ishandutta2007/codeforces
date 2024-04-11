#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int a,b,d;
    cin >> a >>b >> d;
    vector<int> v;
    vector<int> v2;
    for (int i=0;a>i;i++)
    {
        for (int j=0;b>j;j++)
        {
            int x;
            cin >>x;
            v.push_back(x/d);
            v2.push_back(x%d);
        }
    }
    if (*max_element(v2.begin(),v2.end()) == *min_element(v2.begin(),v2.end()))
    {
        sort(v.begin(),v.end());
        int haha = v[ (int)v.size()/2 ];
        int ans=0;
        for (int i:v) ans += abs(haha-i);
        cout << ans<<endl;
    }
    else
    {
        cout << -1<<endl;
    }
}