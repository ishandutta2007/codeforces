#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n;

char s[N];

vector<int>v;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",s+1);
        n=strlen(s+1);
        v.clear();
        for(int i=1,j=1;i<=n;i=j)
        {
            if(s[i]=='0')
            {
                j=i+1;
                continue;
            }
            while(j<=n&&s[j]=='1')
                j++;
            v.push_back(j-i);
        }
        int ans=0;
        sort(v.begin(),v.end(),greater<int>());
        for(int i=0;i<v.size();i+=2)
            ans+=v[i];
        printf("%d\n",ans);
    }
}