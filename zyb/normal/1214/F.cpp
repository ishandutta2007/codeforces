#include<bits/stdc++.h>
using namespace std;
#define M 3000005
#define N 200005
#define lowbit(x) x&-x
struct node {
    int v,id,v1;
}a[N],b[N];
struct pa {
    int id,flag,l,r;
}q[M];
int tot;
int n,m;
int da[N];
long long ans[N];
#define pb push_back
struct Node {
    int x,flag;
};
vector<Node>G[N],T[N];
inline bool cmp(node x,node y) {
    return x.v<y.v;
}
inline void get(int i,int l,int r,int id,int flag,int tt) {
    if (!tt) {
        if (l>r) return ;
        l=l-i+1;
        if (l<=0) l+=n;
        r=r-i+1;
        if (r<=0) r+=n;
        if (l<=r) q[++tot]=pa{i,flag,l,r};
        else q[++tot]=pa{i,flag,l,n},q[++tot]=pa{i,flag,1,r};
    }
    else {
        if (l>r) return ;
        l=i-l+1;
        if (l<=0) l+=n;
        r=i-r+1;
        if (r<=0) r+=n;
        swap(l,r);
        if (l<=r) q[++tot]=pa{i,flag,l,r};
        else q[++tot]=pa{i,flag,l,n},q[++tot]=pa{i,flag,1,r};
    }
}
inline void work(node a[],node b[],int flag) {
    for (int i=0;i<=n;i++) T[i].clear(),G[i].clear();
    tot=0;
    for (int i=1;i<=n;i++) {
        if (a[i].v<b[1].v||(a[i].v==b[1].v&&!flag)) {
            int l=1,r=n,s=0;
            while (l<=r) {
                int mid=(l+r)>>1;
                if (b[mid].v-a[i].v<=a[i].v+m-b[mid].v) l=mid+1,s=mid;
                else r=mid-1;
            }
            if (!s) q[++tot]=pa{i,2,1,n};
            else {
                get(i,1,s,i,1,flag);
                get(i,s+1,n,i,2,flag);
            }
        }
        else if (a[i].v>b[n].v||(a[i].v==b[n].v&&flag)) {
            int l=1,r=n,s=0;
            while (l<=r) {
                int mid=(l+r)>>1;
                if (a[i].v-b[mid].v>m-a[i].v+b[mid].v) l=mid+1,s=mid;
                else r=mid-1;
            }
            if (!s) q[++tot]={i,2,1,n};
            else {
                get(i,1,s,i,3,flag);
                get(i,s+1,n,i,2,flag);
            }
        }
        else {
            int l=1,r=n,d=0;
            if (flag) {
                while (l<=r) {
                    int mid=(l+r)>>1;
                    if (b[mid].v<=a[i].v) d=mid,l=mid+1;
                    else r=mid-1;
                }
            }
            else {
                while (l<=r) {
                    int mid=(l+r)>>1;
                    if (b[mid].v<a[i].v) d=mid,l=mid+1;
                    else r=mid-1;
                }
            }
            l=1,r=d;
            int s=0;
            while (l<=r) {
                int mid=(l+r)>>1;
                if (a[i].v-b[mid].v>m-a[i].v+b[mid].v) l=mid+1,s=mid;
                else r=mid-1;
            }
            get(i,1,s,i,3,flag);
            get(i,s+1,d,i,2,flag);
            l=d+1;
            r=n;
            s=d;
            while (l<=r) {
                int mid=(l+r)>>1;
                if (b[mid].v-a[i].v<=a[i].v+m-b[mid].v) l=mid+1,s=mid;
                else r=mid-1;
            }
            get(i,d+1,s,i,1,flag);
            get(i,s+1,n,i,2,flag);
        }
    }
    long long s=0;
    for (int i=1;i<=tot;i++) {
        G[q[i].l].pb(Node{q[i].id,q[i].flag});
        T[q[i].r+1].pb(Node{q[i].id,q[i].flag});
    }
    for (int i=1;i<=n;i++) {
        for (auto p:G[i]) {
            if (p.flag==1) s-=a[p.x].v;
            if (p.flag==2) s+=a[p.x].v;
            if (p.flag==3) s+=m-a[p.x].v;
        }
        for (auto p:T[i]) {
            if (p.flag==1) s+=a[p.x].v;
            if (p.flag==2) s-=a[p.x].v;
            if (p.flag==3) s-=m-a[p.x].v;
        }
        ans[i]+=s;
    }
}
int main() {
    scanf("%d%d",&m,&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i].v),a[i].id=i,a[i].v1=0;
    for (int i=1;i<=n;i++) scanf("%d",&b[i].v),b[i].id=i,b[i].v1=1;
    sort(a+1,a+1+n,cmp);
    sort(b+1,b+1+n,cmp);
    work(a,b,0);
    work(b,a,1);
    long long Ans=ans[1];
    for (int i=1;i<=n;i++) Ans=min(Ans,ans[i]);
    for (int i=1;i<=n;i++) if (Ans==ans[i]) {
        printf("%lld\n",ans[i]);
        int t=i;
        for (int j=1;j<=n;j++) {
            da[a[j].id]=b[t].id;
            t%=n;
            t++;
        }
        break;
    }
    for (int i=1;i<=n;i++) printf("%d ",da[i]);
    puts("");
}