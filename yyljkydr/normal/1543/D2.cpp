#include<bits/stdc++.h>
using namespace std;

int T;

int n,k,now;

int c(int a,int b)
{
    int ret=0,base=1;
    while(a||b)
    {
        ret=(ret+(a-b+k)%k*base);
        a/=k,b/=k;
        base*=k;
    }
    return ret;
}

int query(int x)
{
    printf("%d\n",x);
    fflush(stdout);
    int ret=0;
    scanf("%d",&ret);
    return ret;
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        now=0;
        scanf("%d%d",&n,&k);
        int ok=0;
        for(int i=0;i<n;i++)
        {
            int ok=0;
            if(!i)
                ok=query(0);
            else if(i%2==0)
                ok=query(c(i,i-1));
            else
                ok=query(c(i-1,i));
            if(ok)
                break;
        }
    }
}