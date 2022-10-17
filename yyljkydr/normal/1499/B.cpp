#include<bits/stdc++.h>
using namespace std;

const int N=101;

int T,n;

char s[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",s+1);
        n=strlen(s+1);
        int ans=0;
        for(int i=0;i<=n;i++)
        {
            bool ok=1;
            vector<int>pos;
            for(int j=1;j<=i;j++)
                if(s[j]=='1')
                    pos.push_back(j);
            for(int j=i+1;j<=n;j++)
                if(s[j]=='0')
                    pos.push_back(j);
            for(int i=0;i+1<pos.size();i++)
                if(pos[i]+1==pos[i+1])
                    ok=0;
            ans|=ok;
        }
        puts(ans?"YES":"NO");
    }
}