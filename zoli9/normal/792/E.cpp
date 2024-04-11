#include <bits/stdc++.h>
using namespace std;
int n;
long long a[509];
long long bestans=-1;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    for(long long x=1; x*x<=a[1]; x++)
    {
        long long curans=0;
        bool possi=true;
        for(int u=1; u<=n; u++)
        {
            long long setsize;
            if(a[u]%(x+1)==0) setsize=a[u]/(x+1);
            else setsize=a[u]/(x+1)+1;
            if(x*setsize>a[u])
            {
                possi=false;
                break;
            }
            else
            {
                curans+=setsize;
            }
        }
        if(possi)
        {
            if(bestans==-1 || curans<bestans) bestans=curans;
        }
    }
    for(long long set1=1; set1*set1<=a[1]; set1++)
    {
        long long x;
        if(a[1]%set1==0)
        {
            x=a[1]/set1-1;
            long long curans=0;
            bool possi=true;
            for(int u=1; u<=n; u++)
            {
                long long setsize;
                if(a[u]%(x+1)==0) setsize=a[u]/(x+1);
                else setsize=a[u]/(x+1)+1;
                if(x*setsize>a[u])
                {
                    possi=false;
                    break;
                }
                else
                {
                    curans+=setsize;
                }
            }
            if(possi)
            {
                if(bestans==-1 || curans<bestans) bestans=curans;
            }
        }
        x=a[1]/set1;
        long long curans=0;
        bool possi=true;
        for(int u=1; u<=n; u++)
        {
            long long setsize;
            if(a[u]%(x+1)==0) setsize=a[u]/(x+1);
            else setsize=a[u]/(x+1)+1;
            if(x*setsize>a[u])
            {
                possi=false;
                break;
            }
            else
            {
                curans+=setsize;
            }
        }
        if(possi)
        {
            if(bestans==-1 || curans<bestans) bestans=curans;
        }
    }
    cout<<bestans<<endl;
    return 0;
}