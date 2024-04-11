#include<bits/stdc++.h>
using namespace std;
 
const int N=1e6+1e3+7;
 
int T;
 
int n,f[N],a[N];

int k;
 
bool solve(int i)
{
    bool ok=1;
    vector<int>use(111+1);
    if(i)
        use[0]=i;
    for(int i=1;i<=k;i++)
    {
        int x=a[i];
        for(int j=43;j>=0;j--)
        {
            if(use[j])
                continue;
            if(use[j+1]==i)
                continue;
            if(j&&use[j-1]==i)
                continue;
            if(f[j]>x)
                continue;
            x-=f[j];
            use[j]=i;
        }
        if(x)
        {
            ok=0;
            break;
        }
    }
    for(int j=0;j<=43;j++)
        if(use[j+1]&&!use[j])
        {
            ok=0;
            break;
        }
    return ok;
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        f[0]=f[1]=1;
        for(int i=2;i<=44;i++)
            f[i]=f[i-1]+f[i-2];
        vector<int>use(111);
        scanf("%d",&k);
        bool ok=0;
        for(int i=1;i<=k;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+k+1);
        reverse(a+1,a+k+1);
        ok|=solve(0);
        for(int i=1;i<=k;i++)
        {
            a[i]--;
            ok|=solve(i);
            if(ok)
                break;
            a[i]++;
        }
        puts(ok?"YES":"NO");
    }
}