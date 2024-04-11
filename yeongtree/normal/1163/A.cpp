#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k,t=0;
    cin>>n>>k;
    if(k==0)
    {
        cout<<"1";
        return 0;
    }
    if(n==3)
    {
        if(k==3)cout<<0;
        else cout<<1;
        return 0;
    }
    t=n/2+n%2;
    if(t<=k)cout<<n-k;
    else cout<<k;
    return 0;
}