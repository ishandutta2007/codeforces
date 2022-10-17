#include<bits/stdc++.h>
using namespace std;

int T,n;

int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n;
        int a=n-n%7;
        int b=n+7-n%7;
        int ans=a/10==n/10?a:b;
        cout<<ans<<endl;
    }
}