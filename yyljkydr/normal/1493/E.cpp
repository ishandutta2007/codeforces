#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int n,a[N],b[N];

char s[N];

int main()
{
    scanf("%d",&n);
    scanf("%s",s);
    for(int i=0;i<n;i++)
        a[i]=s[i]-'0';
    scanf("%s",s);
    for(int i=0;i<n;i++)
        b[i]=s[i]-'0';
    if(a[0]==0&&b[0]==1)
    {
        for(int i=0;i<n;i++)
            putchar('1');
    }
    else
    {
        if(b[n-1]==1)
        {
            for(int i=0;i<n;i++)
                printf("%d",b[i]);
            puts("");
        }
        else
        {
            for(int i=n-1;i>=0;i--)
            {
                a[i]=b[i]-a[i];
                if(a[i]<0)
                    a[i-1]++,a[i]+=2;
            }
            int x=0;
            for(int i=0;i<n;i++)
            {
                x=x*10+a[i];
                if(x>1e6)
                    break;
            }
            if(x>=2)
                b[n-1]=1;
            for(int i=0;i<n;i++)
                printf("%d",b[i]);
            puts("");
        }
    }
}