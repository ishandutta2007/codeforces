#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200009];
long long d[200009];
long long k[200009];
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        k[i]=k[i-1]+a[i];
    }
    d[n-1]=k[n];
    for(int i=n-2; i>=1; i--)
    {
        d[i]=max(d[i+1], k[i+1]-d[i+1]);
        //cout<<d[i]<<endl;
    }
    cout<<d[1]<<endl;
    return 0;
}