#include <bits/stdc++.h>
using namespace std;
int n;
int hanylany[409];
int hanyfiu[409];
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        char c;
        int ke, ve;
        cin>>c;
        cin>>ke>>ve;
        for(int j=ke; j<=ve; j++)
        {
            if(c=='M') hanyfiu[j]++;
            else hanylany[j]++;
        }
    }
    int maxi=0;
    for(int i=1; i<=366; i++)
    {
        maxi=max(maxi, 2*min(hanyfiu[i], hanylany[i]));
    }
    cout<<maxi;
    return 0;
}