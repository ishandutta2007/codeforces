#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T,n,m,s[N];

char a[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        scanf("%s",a+1);
        for(int i=1;i<=n;i++)
            s[i]=s[i-1]+a[i]-'0';
        long long sn=s[n];
        if(sn*m%n)
        {
            puts("-1");
            continue;
        }
        int one=sn*m/n;
        bool fd=0;
        for(int i=1;i+m-1<=n;i++)
            if(s[i+m-1]-s[i-1]==one)
            {
                puts("1");
                printf("%d %d\n",i,i+m-1);
                fd=1;
                break;
            }
        if(fd)
            continue;
        for(int i=n-m+1;i<=n;i++)
            if(s[n]-s[i-1]+s[m-(n-i+1)]==one)
            {
                puts("2");
                printf("%d %d\n",1,m-(n-i+1));
                printf("%d %d\n",i,n);
                break;
            }
    }
}