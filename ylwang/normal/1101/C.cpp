#include <bits/stdc++.h>
using namespace std;
int l[100010],r[100010],n;
struct edge
{
    int l,r;
    bool operator<(const edge&a)const
    {
        if(l<a.l)
        {
            return 1;
        }
        else if(l>a.l)
        {
            return 0;
        }
        else
        {
            return r<a.r;
        }
    }
}e[100010];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&l[i],&r[i]);
            e[i].l=l[i],e[i].r=r[i];
        }
        sort(e+1,e+n+1);
        int rr=-1;
        int flag=0;
        for(int i=1;i<=n;i++)
        {
            if(i==1)
            {
                rr=e[i].r;
                continue;
            }
            if(e[i].l>rr)
            {
                flag=1;
                break;
            }
            else
            {
                rr=max(rr,e[i].r);
            }
        }
        if(!flag)
        {
            cout<<"-1"<<endl;
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            if(r[i]<=rr)
            {
                printf("1 ");
            }
            else
            {
                printf("2 ");
            }
        }
        printf("\n");
    }
}