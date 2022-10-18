#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct node
{
    int s,e;
} num[100005];
bool cmp(node a,node b)
{
    return a.s>b.s;
}
int bf(int i,int j,int k)
{
    int l=i,r=j;
    while(l<=r)
    {
        int mid=l+r>>1;
        if(num[k].e<num[mid].s)
            l=mid+1;
        else
            r=mid-1;
    }
    return l;
}
int main()
{
    int ans,id=1,st,ed,te,flag,temp;
    ll n,sum=0;
    scanf("%lld",&n);
    for(int i=1; i<=n; ++i)
    {
        flag=0;
        scanf("%d",&ans);
        scanf("%d",&st);
        temp=st;
        if(ans!=1)
        {
            for(int j=2; j<=ans-1; ++j)
            {
                scanf("%d",&te);
                if(flag==0&&te>st)
                    flag=1;
                st=te;
            }
            scanf("%d",&ed);
            if(!flag)
            {
                if(st>=ed)
                    num[id].s=temp,num[id++].e=ed;
            }
        }
        else
            num[id].s=st,num[id++].e=st;
    }
    sort(num+1,num+id,cmp);
    for(int i=1; i<id; ++i)
        sum+=id-bf(1,id-1,i);
    cout<<n*n-sum<<endl;
    return 0;
}