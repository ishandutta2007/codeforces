#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int n,p[N];

int Ask(int x,int y)
{
    printf("? %d %d\n",x,y);
    fflush(stdout);
    int k;
    scanf("%d",&k);
    return k;
}

int a[N],b[N];

int main()
{
    scanf("%d",&n);
    int last=1;
    for(int i=2;i<=n;i++)
    {
        a[i]=Ask(last,i);
        b[i]=Ask(i,last);
        if(b[i]>a[i])
            p[i]=b[i];
        else
            p[last]=a[i],last=i;
    }
    p[last]=n;
    printf("! ");
    for(int i=1;i<=n;i++)
        printf("%d%c",p[i]," \n"[i==n]);
}