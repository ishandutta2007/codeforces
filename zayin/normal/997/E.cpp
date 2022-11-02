#include<bits/stdc++.h>
#define maxn 150050
#define val(k)  T[k].val
#define cnt(k)  T[k].cnt
#define sum(k)  T[k].sum
#define tag1(k) T[k].tag1
#define tag2(k) T[k].tag2
using namespace std;
typedef long long LL;

struct node {
    LL sum;
    int val,cnt;
    int tag1,tag2;
} T[maxn<<2];

int n,m;

int a[maxn];

LL ans[maxn];
int L[maxn],R[maxn];
vector<int> pos[maxn];

void init() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        scanf("%d",a+i);
    scanf("%d",&m);
    for (int i=1;i<=m;++i)  {
        scanf("%d%d",L+i,R+i);
        pos[R[i]].push_back(i);
    }
}

int stk1[maxn],tp1;//min
int stk2[maxn],tp2;//max

void build(int k,int l,int r)   {
    val(k)=l,cnt(k)=1;
    if(l==r)    return ;
    int mid=(l+r)>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
}

void renew(int k,int a,int b)   {
    sum(k)+=(LL)b*cnt(k);
    val(k)+=a;
    tag1(k)+=a;
    tag2(k)+=b;
}

void update(int k)  {
    int ls=k<<1,rs=k<<1|1;
    sum(k)=sum(ls)+sum(rs);
    val(k)=min(val(ls),val(rs));
    cnt(k)=0;
    if (val(k)==val(ls))    cnt(k)+=cnt(ls);
    if (val(k)==val(rs))    cnt(k)+=cnt(rs);
}

void godown(int k)  {
    int ls=k<<1,rs=k<<1|1;
    renew(ls,tag1(k),0);
    renew(rs,tag1(k),0);
    if (val(k)==val(ls))    renew(ls,0,tag2(k));
    if (val(k)==val(rs))    renew(rs,0,tag2(k));
    tag1(k)=tag2(k)=0;
}

//val
void change(int k,int l,int r,int a,int b,int dv)  {
    if (a<=l&&r<=b)
        renew(k,dv,0);
    else    {
        godown(k);
        int mid=(l+r)>>1;
        if (a<=mid)
            change(k<<1,l,mid,a,b,dv);
        if (b>mid)
            change(k<<1|1,mid+1,r,a,b,dv);
        update(k);
    }
    // cout<<"change:"<<k<<" "<<l<<" "<<r<<" "<<a<<" "<<b<<" "<<val(k)<<" "<<cnt(k)<<" "<<sum(k)<<endl;
}

LL query(int k,int l,int r,int a,int b)   {
    if (a>r||l>b)   return 0;
    // cout<<"query:"<<k<<" "<<l<<" "<<r<<" "<<a<<" "<<b<<" ("<<val(k)<<" "<<cnt(k)<<" "<<sum(k)<<") ("<<tag1(k)<<" "<<tag2(k)<<")"<<endl;
    if (a<=l&&r<=b) return sum(k);
    godown(k);
    int mid=(l+r)>>1;
    return query(k<<1,l,mid,a,b)+query(k<<1|1,mid+1,r,a,b);
}

void solve()    {
    //val:max-min+l>=r
    build(1,1,n);
    for (int i=1;i<=n;++i)  {
        // cout<<"i:"<<i<<endl;
        while (tp1&&a[i]<=a[stk1[tp1]])
            // cout<<"val_1_1:"<<stk1[tp1-1]+1<<" "<<stk1[tp1]<<" "<<a[stk1[tp1]]<<endl,
            change(1,1,n,stk1[tp1-1]+1,stk1[tp1],a[stk1[tp1]]),--tp1;
        while (tp2&&a[i]>=a[stk2[tp2]])
            // cout<<"val_2_1:"<<stk2[tp2-1]+1<<" "<<stk2[tp2]<<" "<<-a[stk2[tp2]]<<endl,
            change(1,1,n,stk2[tp2-1]+1,stk2[tp2],-a[stk2[tp2]]),--tp2;

        // cout<<"val_1:"<<stk1[tp1]+1<<" "<<i<<" "<<-a[i]<<endl;
        // cout<<"val_2:"<<stk2[tp2]+1<<" "<<i<<" "<<a[i]<<endl;

        change(1,1,n,stk1[tp1]+1,i,-a[i]);
        change(1,1,n,stk2[tp2]+1,i,a[i]);

        stk1[++tp1]=i;
        stk2[++tp2]=i;

        // cout<<"val(1):"<<val(1)<<endl;
        assert(val(1)==i);
        // tag2(1)+=1;
        renew(1,0,1);
        // change(1,1,n,1,i,0,1);

        for (int j:pos[i])    {
            ans[j]=query(1,1,n,L[j],R[j]);
        }
    }
    for (int i=1;i<=m;++i)
        printf("%lld\n",ans[i]);
}

int main()  {
    init();
    solve();
    return 0;
}