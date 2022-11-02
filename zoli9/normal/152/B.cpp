#include <bits/stdc++.h>
using namespace std;
long long n, m, sx, sy;
long long k;
long long x[10009];
long long y[10009];
long long ans=0;
int main()
{
    cin>>n>>m>>sx>>sy;
    cin>>k;
    for(long long i=1; i<=k; i++)
    {
        cin>>x[i]>>y[i];
        if(x[i]>=0 && y[i]>=0)
        {
            long long elso, maso;
            if(x[i]==0) elso=1000000009;
            else elso=(n-sx)/x[i];
            if(y[i]==0) maso=1000000009;
            else maso=(m-sy)/y[i];
            ans+=min(elso, maso);
            sx+=x[i]*min(elso, maso);
            sy+=y[i]*min(elso, maso);
        }
        else if(x[i]>=0)
        {
            long long elso, maso;
            if(x[i]==0) elso=1000000009;
            else elso=(n-sx)/x[i];
            maso=(sy-1)/abs(y[i]);
            ans+=min(elso, maso);
            sx+=x[i]*min(elso, maso);
            sy+=y[i]*min(elso, maso);
        }
        else if(y[i]>=0)
        {
            long long elso, maso;
            elso=(sx-1)/abs(x[i]);
            if(y[i]==0) maso=1000000009;
            else maso=(m-sy)/y[i];
            ans+=min(elso, maso);
            sx+=x[i]*min(elso, maso);
            sy+=y[i]*min(elso, maso);
        }
        else
        {
            long long elso, maso;
            elso=(sx-1)/abs(x[i]);
            maso=(sy-1)/abs(y[i]);
            ans+=min(elso, maso);
            sx+=x[i]*min(elso, maso);
            sy+=y[i]*min(elso, maso);
        }
        //cout<<ans<<endl;
    }
    cout<<ans;
    return 0;
}