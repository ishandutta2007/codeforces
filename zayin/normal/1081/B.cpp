#include<bits/stdc++.h>
#define maxn 100050
using namespace std;

int n,a[maxn];

int pos[maxn];
int N,ans[maxn];

bool cmp(int i,int j)
{
    return a[i]<a[j];
}

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;++i)
        scanf("%d",&a[i]),a[i]=n-a[i],pos[i]=i;
    sort(pos,pos+n,cmp);

    bool flag=1;
    for (int k=0,j=0;flag&&k<n;k=j)
    {
        while (j<n&&a[pos[k]]==a[pos[j]])   ++j;
        // cout<<a[pos[k]]<<" "<<k<<" "<<j<<endl;
        if ((j-k)%a[pos[k]])
            flag=0;
        else
            for (int d=k;d<j;d+=a[pos[k]])
            {
                ++N;
                for (int i=0;i<a[pos[k]];++i)
                    ans[pos[d+i]]=N;
            }
    }

    if (!flag)
        printf("Impossible\n");
    else
    {
        printf("Possible\n");
        for (int i=0;i<n;++i)
            printf("%d ",ans[i]);
        putchar('\n');
    }
    return 0;
}