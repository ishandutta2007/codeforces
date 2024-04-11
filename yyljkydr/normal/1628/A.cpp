#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T,n;

int a[N],s[N];

vector<int>b;

int vis[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        fill(vis,vis+n+1,0);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        s[n+1]=0;
        for(int i=n;i>=1;i--)
        {
            vis[a[i]]=1;
            s[i]=s[i+1];
            while(vis[s[i]])
                s[i]++;
        }
        fill(vis,vis+n+1,0);
        b.clear();
        int la=1,mex=0;
        for(int i=1;i<=n;i++)
        {
            vis[a[i]]=1;
            while(vis[mex])
                mex++;
            if(mex==s[la])
            {
                b.push_back(mex);
                for(int j=la;j<=i;j++)
                    vis[a[j]]=0;
                mex=0;
                la=i+1;
            }
        }
        printf("%d\n",b.size());
        for(int i=0;i<b.size();i++)
            printf("%d%c",b[i]," \n"[i+1==b.size()]);
    }
}