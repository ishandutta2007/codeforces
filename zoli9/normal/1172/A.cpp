#include <bits/stdc++.h>
using namespace std;
int n;
int a[400009];
int b[400009];
int pos[400009];
int tav(int x)
{
    return pos[x]+n+1-x;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        pos[a[i]]=0;
    }
    for(int i=1; i<=n; i++)
    {
        cin>>b[i];
        pos[b[i]]=i;
    }
    if(pos[1]>0)
    {
        bool jo=true;
        for(int i=pos[1]+1; i<=n; i++)
        {
            if(b[i]!=i-pos[1]+1)
            {
                jo=false;
                break;
            }
        }
        if(jo)
        {
            bool vege=true;
            int maxi=n-pos[1]+1;
            int maxtime=pos[1]-1;
            for(int i=maxi+1; i<=n; i++)
            {
                if(tav(i)>maxtime)
                {
                    vege=false;
                    break;
                }
            }
            if(vege)
            {
                cout<<maxtime<<endl;
                return 0;
            }
        }
    }
    int ans=0;
    for(int i=1; i<=n; i++)
    {
        ans=max(ans, tav(i));
    }
    cout<<ans<<endl;
    return 0;
}