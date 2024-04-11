#include <bits/stdc++.h>
using namespace std;
int n;
int ans[5009];
int t[5009];
int akt[5009];
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i];
    }
    for(int kezd=1; kezd<=n; kezd++)
    {
        for(int i=1; i<=n; i++)
        {
            akt[i]=0;
        }
        int dbmax=1;
        int colmax=t[kezd];
        //cout<<colmax<<endl;
        ans[colmax]++;
        akt[t[kezd]]++;
        for(int j=kezd+1; j<=n; j++)
        {
            int szin=t[j];
            akt[szin]++;
            if(szin==colmax) dbmax++;
            else
            {
                if(dbmax==akt[szin])
                {
                    if(colmax>szin) colmax=szin;
                }
                else if(dbmax<akt[szin])
                {
                    colmax=szin;
                    dbmax=akt[szin];
                }
            }
            //cout<<colmax<<endl;
            ans[colmax]++;
        }
    }
    for(int i=1; i<=n; i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}