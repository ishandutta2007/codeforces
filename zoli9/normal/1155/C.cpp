#include <bits/stdc++.h>
using namespace std;
int n, m;
long long x[300009];
long long p[300009];
long long w=-1;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    cin>>x[1];
    for(int i=2; i<=n; i++)
    {
        cin>>x[i];
        if(w==-1) w=x[i]-x[i-1];
        else
        {
            w=__gcd(w, x[i]-x[i-1]);
        }
    }
    long long best=-1;
    long long bestpl=-1;
    for(int j=1; j<=m; j++)
    {
        cin>>p[j];
        if(w%p[j]==0)
        {
            long long cur=x[1]%p[j];
            if(cur==0) cur=p[j];
            if(best==-1 || cur<best)
            {
                best=cur;
                bestpl=j;
            }
        }
    }
    if(best==-1)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
        cout<<best<<" "<<bestpl<<endl;
    }
    return 0;
}