#include<bits/stdc++.h>
#define maxn 100050
using namespace std;
typedef long long LL;

int n,m;
int a[maxn],c[maxn];

LL A;

struct cmp  {
    bool operator () (const int i,const int j) const   {
        return c[i]<c[j]||(c[i]==c[j]&&i<j);
    }
};
set<int,cmp> q;

LL calc(int i,int s,int &d)
{
    if (!s) return 0;
    a[i]-=s,d-=s,A-=s;
    if (!a[i]&&q.count(i))
        q.erase(i);
    // cout<<"money:"<<c[i]*s<<endl;
    return 1LL*c[i]*s;
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i)  scanf("%d",a+i),A+=a[i];
    for (int i=1;i<=n;++i)  scanf("%d",c+i),q.insert(i);
    while (m--)
    {
        int i,d,s;
        scanf("%d%d",&i,&d);
        LL ans=calc(i,min(d,a[i]),d);
        while (d&&A)
        {
            int i=*q.begin();
            ans+=calc(i,min(d,a[i]),d);
            // cout<<"chose:"<<i<<" "<<d<<endl;
        }
        if (d)
            ans=0;
        printf("%lld\n",ans);
        // cout<<endl;
    }
    return 0;
}