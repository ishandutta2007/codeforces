#include <bits/stdc++.h>
using namespace std;
long long t, s, x;
int main()
{
    cin>>t>>s>>x;
    if(x==t)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    if(x==t+1)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    x-=t;
    if(x<0)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    if(x%s==0 || x%s==1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}