#include<bits/stdc++.h>
using namespace std;

const int N=2e3+1e2+7;

char s[N];

int T,n,cnt[26];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%s",s);
            int len=strlen(s);
            for(int j=0;j<len;j++)
                cnt[s[j]-'a']++;
        }
        int ok=1;
        for(int i=0;i<26;i++,cnt[i-1]=0)
            if(cnt[i]%n!=0)
                ok=0;
        puts(ok?"YES":"NO");
    }
}