#include<bits/stdc++.h>
using namespace std;

const int N=3e5+1e3+7;

int n,q;

int a[N],top[N];

int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),top[a[i]]=top[a[i]]==0?i:top[a[i]];
    while(q--)
    {
        int x;
        scanf("%d",&x);
        int p=top[x];
        printf("%d ",p);
        for(int j=1;j<=50;j++)
            if(j!=x&&top[j]<=p)
                top[j]++;
        top[x]=1;
    }
}