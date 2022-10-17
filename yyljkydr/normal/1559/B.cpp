#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n;

char s[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        scanf("%s",s+1);
        int p=1;
        while(p<=n&&s[p]=='?')
            p++;
        for(int i=p-1;i>=1;i--)
            if(s[i]=='?')
                s[i]=(s[i+1]=='B'?'R':'B');
        for(int i=p+1;i<=n;i++)
            if(s[i]=='?')
                s[i]=(s[i-1]=='B'?'R':'B');
        puts(s+1);
    }
}