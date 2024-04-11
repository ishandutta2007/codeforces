#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7,P=1e9+7;

int n,f[N];

char s[N];

int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    f[0]=1;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='m'||s[i]=='w')
        {
            puts("0");
            return 0;
        }
        f[i]=f[i-1];
        if(s[i]=='n'&&s[i-1]=='n')
            f[i]=(f[i]+f[i-2])%P;
        if(s[i]=='u'&&s[i-1]=='u')
            f[i]=(f[i]+f[i-2])%P;
    }
    printf("%d\n",f[n]);
}