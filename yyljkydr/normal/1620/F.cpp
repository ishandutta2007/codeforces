#include<bits/stdc++.h>
using namespace std;

const int N=3e6+1e3+7;

int T,n,a[N],vis[N];

pair<int,int> f[N][2];

int last[N][2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i],vis[i]=0;
        for(int i=1;i<=n;i++)
            for(int j=0;j<2;j++)
                f[i][j]={1e9,1e9};
        f[0][0]=f[0][1]={-1e9,-1e9};
        for(int i=1;i<=n;i++)
        {
            pair<int,int> dp1=f[i-1][0],dp2=f[i-1][1];
            if(-a[i]>dp1.first)
                dp1.first=-a[i];
            else if(-a[i]>dp1.second)
                dp1.second=-a[i];
            else
                dp1={1e9,1e9};
            if(-a[i]>dp2.first)
                dp2.first=-a[i];
            else if(-a[i]>dp2.second)
                dp2.second=-a[i];
            else
                dp2={1e9,1e9};
            if(dp1<dp2)
                f[i][0]=dp1,last[i][0]=0;
            else
                f[i][0]=dp2,last[i][0]=1;

            dp1=f[i-1][0],dp2=f[i-1][1];
            if(a[i]>dp1.first)
                dp1.first=a[i];
            else if(a[i]>dp1.second)
                dp1.second=a[i];
            else
                dp1={1e9,1e9};
            if(a[i]>dp2.first)
                dp2.first=a[i];
            else if(a[i]>dp2.second)
                dp2.second=a[i];
            else
                dp2={1e9,1e9};
            if(dp1<dp2)
                f[i][1]=dp1,last[i][1]=0;
            else
                f[i][1]=dp2,last[i][1]=1;
        }
        int ok=0;
        if(f[n][0].first<=n&&f[n][0].second<=n)
        {
            ok=1;
            int q=0;
            for(int i=n;i>=1;i--)
            {
                if(!q)
                    a[i]*=-1;
                q=last[i][q];
            }
        }
        else if(f[n][1].first<=n&&f[n][1].second<=n)
        {
            ok=1;
            int q=1;
            for(int i=n;i>=1;i--)
            {
                if(!q)
                    a[i]*=-1;
                q=last[i][q];
            }
        }
        if(ok)
        {
            cout<<"YES\n";
            for(int i=1;i<=n;i++)
                cout<<a[i]<<" \n"[i==n];
        }
        else
            cout<<"NO\n";
    }
}