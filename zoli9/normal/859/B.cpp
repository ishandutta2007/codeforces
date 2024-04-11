#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    cin>>n;
    int s=sqrt(n);
    if(s*s==n)
    {
        cout<<4*s<<endl;
        return 0;
    }
    if(s*(s+1)>=n)
    {cout<<(2*s+2*(s+1))<<endl;
    return 0;
    }

    cout<<4*(s+1)<<endl;

    return 0;
}