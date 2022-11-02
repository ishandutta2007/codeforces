#include<bits/stdc++.h>
#define maxn 200050
#define inf (0x3f3f3f3f)
#define mx(k)  T[k].mx
#define tag(k)  T[k].tag
using namespace std;
typedef long long LL;

struct node {
    int mx[5],tag;
} T[maxn*4];

int n,m,N;

int a[maxn];
char s[maxn];

void renew(int k,int d) {
    mx(k)[0]+=d;
    mx(k)[1]-=d;
    mx(k)[2]-=d;
    mx(k)[3]-=d;
    tag(k)+=d;
}

void update(int k)  {
    int ls=k<<1,rs=k<<1|1;
    for (int i=0;i<5;++i)
        mx(k)[i]=max(mx(ls)[i],mx(rs)[i]);
    mx(k)[2]=max(mx(k)[2],mx(ls)[0]+2*mx(rs)[1]);
    mx(k)[3]=max(mx(k)[3],2*mx(ls)[1]+mx(rs)[0]);
    mx(k)[4]=max(mx(k)[4],max(mx(ls)[2]+mx(rs)[0],mx(ls)[0]+mx(rs)[3]));
}

void godown(int k)  {
    renew(k<<1,tag(k));
    renew(k<<1|1,tag(k));
    tag(k)=0;
}

void build(int k,int l,int r)   {
    if (l==r)   {
        mx(k)[0]=a[l],mx(k)[1]=-a[l];
        mx(k)[2]=mx(k)[3]=-a[l];
        mx(k)[4]=0;
    } else  {
        int mid=(l+r)>>1;
        build(k<<1,l,mid);
        build(k<<1|1,mid+1,r);
        update(k);
    }
    // cout<<k<<":"<<l<<" "<<r<<" ";
    // for (int i=0;i<5;++i) cout<<mx(k)[i]<<" "; cout<<endl;
}

void init() {
    scanf("%d%d%s",&n,&m,s+1);
    N=n-1<<1;
    for (int i=1;i<=N;++i)
        a[i]=a[i-1]+(s[i]=='('?1:-1);
    build(1,0,N);
}

void change(int k,int l,int r,int a,int b,int d)    {
    if (a<=l&&r<=b) 
        renew(k,d);
    else    {
        godown(k);
        int mid=(l+r)>>1;
        if (a<=mid)
            change(k<<1,l,mid,a,b,d);
        if (b>mid)
            change(k<<1|1,mid+1,r,a,b,d);
        update(k);
    }
}

void solve()    {
    printf("%d\n",mx(1)[4]);
    while (m--) {
        int a,b;
        scanf("%d%d",&a,&b);
        if (a>b) 
            swap(a,b);
        if (s[a]!=s[b]) {
            if (s[a]=='(')
                change(1,0,N,a,b-1,-2);
            else
                change(1,0,N,a,b-1,2);
            swap(s[a],s[b]);
        }
        printf("%d\n",mx(1)[4]);
    }
}

int main()  {
    init();
    solve();
    return 0;
}