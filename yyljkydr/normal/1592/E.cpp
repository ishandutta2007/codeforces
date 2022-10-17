#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int n,a[N],s[N];

map<int,int>mp[2];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int ans=0;
    for(int j=19;j>=0;j--)
    {
        mp[0].clear();
        mp[1].clear();
        mp[0][0]=0;
        for(int i=1;i<=n;i++)
        {
            s[i]=s[i-1]^(a[i]>>j);
            if(a[i]>>j&1)
            {
                if(mp[i&1].count(s[i]))
                    ans=max(ans,i-mp[i&1][s[i]]);
                else
                    mp[i&1][s[i]]=i;
            }
            else
                mp[0].clear(),mp[1].clear(),mp[i&1][s[i]]=i;
        }
    }
    printf("%d\n",ans);
}