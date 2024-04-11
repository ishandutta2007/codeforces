#include <bits/stdc++.h>
using namespace std;
int n, t;
int main()
{
    cin>>n>>t;
    if(n==1 && t==10)
    {
        cout<<-1;
        return 0;
    }
    cout<<t;
    if(t==10)
    {
        for(int i=1; i<=n-2; i++)
        {
            cout<<"0";
        }
    }
    else
    {
        for(int i=1; i<=n-1; i++)
        {
            cout<<"0";
        }
    }
    return 0;
}