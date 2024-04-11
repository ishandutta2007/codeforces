#include <bits/stdc++.h>
using namespace std;
int x[1009];
int y[1009];
int a[1009];
int b[1009];
int n;
map<pair<int, int>, bool> ma;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>x[i]>>y[i];
    }
    for(int i=1; i<=n; i++)
    {
        cin>>a[i]>>b[i];
        ma[{a[i], b[i]}]=true;
    }
    for(int elso=1; elso<=n; elso++)
    {
        int tx=x[1]+a[elso];
        int ty=y[1]+b[elso];
        bool jo=true;
        for(int i=2; i<=n; i++)
        {
            int kx=tx-x[i];
            int ky=ty-y[i];
            if(!ma[{kx, ky}])
                {
                    jo=false;
                    break;
                }
        }
        if(jo)
        {
            cout<<tx<<" "<<ty<<endl;
            return 0;
        }
    }

    return 0;
}