#include<bits/stdc++.h>
#define maxn 200050
#define modu 998244353
using namespace std;
typedef long long LL;

int n,m;
char s[maxn];

LL pw[maxn];

struct node {
    LL hash,len,l,r;
    node(LL _h=0,LL _len=0,LL _l=0,LL _r=0)  {
        hash=_h%modu,len=_len,l=_l,r=_r;
    }
    node operator + (const node& N) const   {
        if (!~len) return N;
        if (!~N.len) return *this;

        node ans;
        if (!len&&!N.len)
            return node(0,0,l+N.l,r+N.r);
        if (!len)   {
            int c=(r+N.l)&1;
            if (c)
                return node(N.hash,N.len,1,r+N.l+N.r-1);
            else
                return node(N.hash,N.len,0,r+N.l+N.r);
        }

        if (!N.len) {
            return node(hash,len,l,N.r+r);
        }

        if (len&&N.len) {
            int c=(r+N.l)&1;
            if (c)
                return node(hash*pw[N.len+1]+pw[N.len]+N.hash,len+N.len+1,l,r+N.l+N.r-1);
            else
                return node(hash*pw[N.len]+N.hash,len+N.len,l,r+N.l+N.r);
        }
        return ans;
    }

    bool operator == (const node& N) const  {
        return hash==N.hash&&len==N.len&&l==N.l&&r==N.r;
    }

} T[maxn<<2];
#define hash(k) T[k].hash
#define len(k) T[k].len
#define l(k) T[k].l
#define r(k) T[k].r

ostream& operator << (ostream& os,const node& N)    {
    os<<"("<<N.l<<" "<<N.hash<<"["<<N.len<<"]"<<" "<<N.r<<")";
    return os;
}

void build(int k,int l,int r)   {
    hash(k)=0;
    if (l==r)
        l(k)=r(k)=(s[l]=='1'),len(k)=(s[l]=='0');
    else    {
        int mid=(l+r)>>1;
        build(k<<1,l,mid);
        build(k<<1|1,mid+1,r);
        T[k]=T[k<<1]+T[k<<1|1];
    }
    // cout<<"build:"<<k<<" "<<l<<" "<<r<<" "<<T[k]<<endl;
}

node query(int k,int l,int r,int a,int b)   {
    if (a>r||l>b) return node(-1,-1,-1,-1);
    if (a<=l&&r<=b) return T[k];
    int mid=(l+r)>>1;
    return query(k<<1,l,mid,a,b)+query(k<<1|1,mid+1,r,a,b);
}

int main()  {

    for (int i=pw[0]=1;i<maxn;++i) pw[i]=pw[i-1]*2%modu;

    scanf("%d%s",&n,s+1);
    build(1,1,n);
    
    // cout<<"----"<<endl;

    // node L=query(1,1,n,3,3),R=query(1,1,n,4,5);
    // cout<<L<<" "<<R<<" "<<L+R<<endl;
    // return 0;

    scanf("%d",&m);
    while (m--) {
        int i,j,len;
        scanf("%d%d%d",&i,&j,&len);
        node L=query(1,1,n,i,i+len-1),R=query(1,1,n,j,j+len-1);
        // cout<<"L:"<<L<<endl;
        // cout<<"R:"<<R<<endl;
        if (L==R)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}