#include <bits/stdc++.h>
using namespace std;
int query;
int main()
{
    ios::sync_with_stdio(false);
    cin>>query;
    for(int u=1; u<=query; u++)
    {
        long long x;
        cin>>x;
        if(x<=3)
        {
            cout<<-1<<endl;
            continue;
        }
        if(x%4==0)
        {
            cout<<(x/4)<<endl;
            continue;
        }
        if(x%4==2)
        {
            cout<<((x-2)/4)<<endl;
            continue;
        }
        if(x==5 || x==7 || x==11)
        {
            cout<<-1<<endl;
            continue;
        }
        if(x%4==1)
        {
            cout<<((x-5)/4)<<endl;
            continue;
        }
        cout<<((x-7)/4)<<endl;
    }
    return 0;
}