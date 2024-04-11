#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n;

char a[N],b[N];

int go(int x)
{
    if(x)
    {
        for(int i=1;i<=n;i++)
            if(i!=x)
                a[i]='1'^'0'^a[i];
    }
    int c1=0,c2=0;
    for(int i=1;i<=n;i++)
        if(a[i]=='1'&&b[i]=='0')
            c1++;
        else if(a[i]=='0'&&b[i]=='1')
            c2++;
    int ret;
    if(c1!=c2)
        ret=1e9;
    else
        ret=c1;
    if(x)
    {
        for(int i=1;i<=n;i++)
            if(i!=x)
                a[i]='1'^'0'^a[i];
    }
    return ret;
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        int ans=1e9;
        scanf("%s",a+1);
        scanf("%s",b+1);
        ans=min(ans,go(0)*2);
        for(int i=1;i<=n;i++)
            if(a[i]=='1'&&b[i]=='0')
            {
                ans=min(go(i)*2+1,ans);
                break;
            }
        for(int i=1;i<=n;i++)
            if(a[i]=='1'&&b[i]=='1')
            {
                ans=min(go(i)*2+1,ans);
                break;
            }
        printf("%d\n",ans==1e9?-1:ans);
    }
}