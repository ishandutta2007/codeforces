#include <bits/stdc++.h>
using namespace std;
int n;
int u[209];
int r[209];
int d[209];
int l[209];
int x, y;
int ans;
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        char c;
        cin>>c;
        u[i]=u[i-1];
        r[i]=r[i-1];
        d[i]=d[i-1];
        l[i]=l[i-1];
        if(c=='U') u[i]++;
        if(c=='R') r[i]++;
        if(c=='D') d[i]++;
        if(c=='L') l[i]++;
    }
    x=u[n]-d[n];
    y=l[n]-r[n];
    ans=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=i; j<=n; j++)
        {
            if((u[j]-u[i-1])-(d[j]-d[i-1])==0 && (l[j]-l[i-1])-(r[j]-r[i-1])==0) ans++;
        }
    }
    cout<<ans;
    return 0;
}