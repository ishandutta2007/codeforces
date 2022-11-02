#include<bits/stdc++.h>
#define maxn 250050
using namespace std;
typedef long long LL;

struct node {
    int mn,mx;
} T[maxn<<2];
#define mx(k) T[k].mx
#define mn(k) T[k].mn

int n,a[maxn],pos[maxn];

void build(int k,int l,int r)   {
    if (l==r) {
        mx(k)=mn(k)=a[l];
    } else  {
        int mid=(l+r)>>1;
        build(k<<1,l,mid);
        build(k<<1|1,mid+1,r);
        mn(k)=min(mn(k<<1),mn(k<<1|1));
        mx(k)=max(mx(k<<1),mx(k<<1|1));
    }
}

int find_mn(int k,int l,int r,int p,int x)  {
    if (r<=p||mn(k)>=x) return maxn;
    if (l==r) return l;
    int mid=(l+r)>>1;
    int t=find_mn(k<<1,l,mid,p,x);
    if (t==maxn)
        t=find_mn(k<<1|1,mid+1,r,p,x);
    return t;
}

int find_mx(int k,int l,int r,int p,int x)  {
    if (r<=p||mx(k)<=x) return maxn;
    if (l==r) return l;
    int mid=(l+r)>>1;
    int t=find_mx(k<<1,l,mid,p,x);
    if (t==maxn)
        t=find_mx(k<<1|1,mid+1,r,p,x);
    return t;
}

LL ans[maxn];

int main()  {
    scanf("%d",&n);

    for (int i=1;i<=n;++i)  
        scanf("%d",a+i),pos[i]=i;
    for (int i=1;i<=n;++i)
        a[i+n]=a[i];

    build(1,1,n<<1);
    sort(pos+1,pos+n+1,[&](const int& i,const int& j)   {
        return a[i]>a[j];
    });

    if (a[pos[n]]>=(a[pos[1]]+1)/2)
        for (int i=1;i<=n;++i)
            printf("-1 ");
    else    {
        for (int k=1;k<=n;++k)  {
            int i=pos[k];
            int j1=find_mn(1,1,n<<1,i,(a[i]+1)>>1),j2=find_mx(1,1,n<<1,i,a[i]);
            int j=min(j1,j2);
            // cout<<i<<" "<<j1<<" "<<j2<<" "<<j<<" ~ "<<j-i<<endl;
            ans[i+n]=ans[i]=j-i+ans[j];
            // cout<<"ans:"<<i<<" "<<ans[i]<<endl;
        }
        for (int i=1;i<=n;++i)  {
            printf("%d ",ans[i]);
        }
    }
    return 0;
}