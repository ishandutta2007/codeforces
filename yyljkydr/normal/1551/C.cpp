#include<bits/stdc++.h>
using namespace std;

const int N=4e5+1e3+7;

int T,n;

char s[N];

int cnt[N][5],sum[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%s",s+1);
            int len=strlen(s+1);
            sum[i]=len;
            for(int j=0;j<5;j++)
                cnt[i][j]=0;
            for(int j=1;j<=len;j++)
                cnt[i][s[j]-'a']++;
        }
        vector<int>v;
        int ans=0;
        for(int i=0;i<5;i++)
        {
            v.clear();
            for(int j=1;j<=n;j++)
                v.push_back(2*cnt[j][i]-sum[j]);
            sort(v.begin(),v.end(),greater<int>());
            int s=0;
            for(int i=0;i<v.size();i++)
            {
                s+=v[i];
                if(s>0)
                    ans=max(ans,i+1);
            }
        }
        printf("%d\n",ans);
    }
}